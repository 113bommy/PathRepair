#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e2 + 27;
const int INF = 2e9 + 7;
const int MOD = 1e9 + 7;
const long long LINF = 1e17 + 7;
const double Pi = acos(-1.);
const double EPS = 1e-8;
int n, m, t, ans, c[M];
void inc(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void dfs(int p, int cnt, bitset<M> st) {
  if (p > n) {
    inc(ans, cnt);
    return;
  }
  dfs(p + 1, cnt, st);
  if (c[p] && !st[p])
    dfs(p + 1, (long long)cnt * c[p],
        st | st << p | st >> p | st << (m - p) | st >> (m - p));
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d", &n);
    n %= m;
    n < m - n ? ++c[n] : ++c[m - n];
  }
  n = m >> 1;
  dfs(1, 1, bitset<M>(1));
  printf("%d", ans);
  return 0;
}
