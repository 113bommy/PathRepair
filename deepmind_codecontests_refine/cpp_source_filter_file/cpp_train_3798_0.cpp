#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 17;
int Q[2 * N];
int get(int L, int R) {
  int res = (int)1e9;
  for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
    if (L & 1) res = min(res, Q[L++]);
    if (R & 1) res = min(res, Q[--R]);
  }
  return res;
}
void add(int pos, int x) {
  pos += N;
  Q[pos] = x;
  pos >>= 1;
  while (pos) {
    Q[pos] = min(Q[2 * pos], Q[2 * pos + 1]);
    pos >>= 1;
  }
}
int n, m, k, q;
int x[1 << 18], y[1 << 18];
int rx1[1 << 18], ry1[1 << 18], rx2[1 << 18], ry2[1 << 18];
int res[1 << 18];
struct P {
  int x, y;
  int id;
  P() {}
  P(int x, int y, int id) : x(x), y(y), id(id) {}
};
bool operator<(const P& a, const P& b) {
  if (a.y == b.y) {
    if (a.x == b.x) return a.id < b.id;
    return a.x < b.y;
  }
  return a.y < b.y;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    x[i]--, y[i]--;
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &rx1[i], &ry1[i], &rx2[i], &ry2[i]);
    rx1[i]--, ry1[i]--;
    rx2[i]--, ry2[i]--;
  }
  for (int it = 0; it < 2; ++it) {
    memset(Q, -1, sizeof(Q));
    vector<P> E;
    for (int i = 0; i < k; ++i) E.push_back(P(x[i], y[i], -1));
    for (int i = 0; i < q; ++i) E.push_back(P(rx2[i], ry2[i], i));
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); ++i) {
      if (E[i].id == -1)
        add(E[i].x, E[i].y);
      else {
        if (get(rx1[E[i].id], rx2[E[i].id] + 1) >= ry1[E[i].id])
          res[E[i].id] = 1;
      }
    }
    for (int i = 0; i < q; ++i) {
      swap(rx1[i], ry1[i]);
      swap(rx2[i], ry2[i]);
    }
    for (int i = 0; i < k; ++i) swap(x[i], y[i]);
  }
  for (int i = 0; i < q; ++i)
    if (res[i])
      printf("YES\n");
    else
      printf("NO\n");
  return 0;
}
