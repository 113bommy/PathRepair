#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000005;
int ci[233], T, n, a[maxn], ans, all;
bool v[maxn], isp[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x;
}
void dfs(int x) {
  if (v[x]) return;
  v[x] = 1;
  if (isp[x]) dfs(all ^ x);
  for (int i = 0; i <= T; i++)
    if (ci[i] & x) dfs(x ^ ci[i]);
}
inline void solve() {
  for (int i = 1; i <= n; i++)
    if (!v[a[i]]) {
      ans++, dfs(all ^ a[i]);
    }
}
int main() {
  ci[0] = 1;
  for (int i = 1; i <= 22; i++) ci[i] = ci[i - 1] << 1;
  T = read(), n = read(), all = ci[n] - 1;
  for (int i = 1; i <= n; i++) a[i] = read(), isp[a[i]] = 1;
  solve();
  printf("%d\n", ans);
  return 0;
}
