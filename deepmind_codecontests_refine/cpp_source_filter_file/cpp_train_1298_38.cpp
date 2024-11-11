#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 5e3 + 10;
vector<int> g[M];
int h[N], a[N], n, m, k, p;
long long b[N];
bool check(long long x) {
  int rs = 0;
  for (int i = 1; i < m; ++i) g[i].clear();
  for (int i = 1; i <= n; ++i) {
    b[i] = x;
    if (b[i] < a[i]) return false;
    if (b[i] / a[i] < m) g[b[i] / a[i]].push_back(i);
  }
  for (int i = 1; i < m; ++i) {
    rs += k;
    for (auto o : g[i]) {
      while (b[o] / a[o] == i) {
        if (!rs) return false;
        rs--;
        b[o] += p;
      }
      if (b[o] / a[o] < m) g[b[o] / a[o]].push_back(o);
    }
    g[i].clear();
  }
  rs += k;
  for (int i = 1; i <= n; ++i) {
    while (b[i] - 1LL * a[i] * m < h[i]) {
      if (!rs) return false;
      rs--;
      b[i] += p;
    }
  }
  return true;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &p);
  for (int i = 1; i <= n; ++i) scanf("%d %d", &h[i], &a[i]);
  long long l = -1, r = 5e11 + 1e9 + 1, mid;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%lld\n", r);
}
