#include <bits/stdc++.h>
using namespace std;
long long int n, m, kd[4 * ((int)1e5 + 5)], color[4 * ((int)1e5 + 5)],
    lazy[4 * ((int)1e5 + 5)], c, x, y, v;
void init(long long int root, long long int bas, long long int son) {
  if (bas == son) {
    kd[root] = bas;
    return;
  }
  init((root << 1), bas, ((bas + son) >> 1));
  init(((root << 1) | 1), ((bas + son) >> 1) + 1, son);
}
long long int query(long long int root, long long int bas, long long int son,
                    long long int x, long long int y) {
  if (son < x or y < bas) return 0;
  if (x <= bas and son <= y) return color[root] + lazy[root] * (son - bas + 1);
  if (kd[root]) {
    lazy[(root << 1)] += lazy[root];
    lazy[((root << 1) | 1)] += lazy[root];
    kd[(root << 1)] = kd[root];
    kd[((root << 1) | 1)] = kd[root];
    lazy[root] = kd[root] = 0;
  }
  long long int ret =
      query((root << 1), bas, ((bas + son) >> 1), x, y) +
      query(((root << 1) | 1), ((bas + son) >> 1) + 1, son, x, y);
  color[root] = color[(root << 1)] + color[((root << 1) | 1)] +
                lazy[(root << 1)] * (((bas + son) >> 1) - bas + 1) +
                lazy[((root << 1) | 1)] * (son - (((bas + son) >> 1) + 1) + 1);
  if (kd[(root << 1)] == kd[((root << 1) | 1)] and kd[(root << 1)])
    kd[root] = kd[(root << 1)];
  return ret;
}
long long int update(long long int root, long long int bas, long long int son,
                     long long int x, long long int y, long long int v) {
  if (son < x or y < bas) return color[root] + lazy[root] * (son - bas + 1);
  if (x <= bas and son <= y and kd[root]) {
    lazy[root] += abs(kd[root] - v);
    kd[root] = v;
    return color[root] + lazy[root] * (son - bas + 1);
  }
  if (kd[root]) {
    lazy[(root << 1)] += lazy[root];
    lazy[((root << 1) | 1)] += lazy[root];
    kd[(root << 1)] = kd[root];
    kd[((root << 1) | 1)] = kd[root];
    lazy[root] = kd[root] = 0;
  }
  color[root] = update((root << 1), bas, ((bas + son) >> 1), x, y, v) +
                update(((root << 1) | 1), ((bas + son) >> 1) + 1, son, x, y, v);
  if (kd[(root << 1)] == kd[((root << 1) | 1)] and kd[(root << 1)])
    kd[root] = kd[(root << 1)];
  return color[root];
}
int main() {
  cin >> n >> m;
  init(1, 1, n);
  for (int i = 1; i <= m; i++) {
    cin >> c >> x >> y;
    if (c == 1) {
      cin >> v;
      update(1, 1, n, x, y, v);
    } else
      cout << query(1, 1, n, x, y) << '\n';
  }
  return 0;
}
