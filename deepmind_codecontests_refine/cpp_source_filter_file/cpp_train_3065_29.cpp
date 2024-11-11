#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e5 + 10;
const int K = 310;
int f[K];
int a[N];
vector<int> ps[N];
int n, m, s, e, ans;
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &e);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0, x; i < m; ++i) {
    scanf("%d", &x);
    ps[x].push_back(i);
  }
  for (int i = 0; i < N; ++i) {
    ps[i].push_back(INF);
  }
  f[0] = -1;
  fill(f + 1, f + K, INF);
  for (int i = 0; i < n; ++i) {
    for (int j = K - 1; j; --j) {
      f[j] =
          min(f[j], *upper_bound(ps[a[i]].begin(), ps[a[i]].end(), f[j - 1]));
      if (i + f[j] + 2 + j * e <= s) ans = max(ans, j);
    }
  }
  printf("%d\n", ans);
  return 0;
}
