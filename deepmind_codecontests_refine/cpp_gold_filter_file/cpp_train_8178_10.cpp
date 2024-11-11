#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, id, n, m, x, y, k, c, p, dif, ans, sum, pre, rem, cur, tmp, tot, r, l, u,
    d, xx, yy;
int a[N], vis[N], f[N], b[N], cu[N];
vector<int> v, adj[N];
bool fl, ok;
int dp[N];
int mem[N];
int sol(int i = n) {
  int &ret = mem[i];
  if (~ret) return ret;
  if (!i) return ret = 0;
  ret = sol(i - 1) + 20;
  int B90 = upper_bound(a + 1, a + n + 1, a[i] - 90) - (a + 1);
  ret = min(ret, sol(B90) + 50);
  int Bday = upper_bound(a + 1, a + n + 1, a[i] - 1440) - (a + 1);
  ret = min(ret, sol(Bday) + 120);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (int)n; ++i) scanf("%d", &a[i]);
  memset(mem, -1, sizeof mem);
  ;
  sol();
  for (int i = 1; i <= (int)n; ++i) printf("%d\n", mem[i] - mem[i - 1]);
  return 0;
}
