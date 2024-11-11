#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double pi = acos(-1.0), eps = 1e-6;
void File() {
  freopen("D:\\in.txt", "r", stdin);
  freopen("D:\\out.txt", "w", stdout);
}
template <class T>
inline void read(T &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
const int maxn = 2000010;
char s[maxn], t[maxn];
int n, k, pre[maxn];
bool f[maxn], g[maxn];
long long dp[maxn], mod = 1e9 + 7;
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", t);
  int m = strlen(t);
  for (int i = 1; i <= m; i++) {
    dp[i] = 2 * dp[i - 1] % mod;
    if (pre[t[i - 1]] != 0) dp[i] = (dp[i] - dp[pre[t[i - 1]] - 1] + mod) % mod;
    if (!f[t[i - 1]]) f[t[i - 1]] = 1, dp[i] = (dp[i] + 1) % mod;
    pre[t[i - 1]] = i;
  }
  for (int i = 0; i < m; i++) g[t[i] - 'a'] = i + 1;
  for (int i = m + 1; i <= m + n; i++) {
    int mi = 30, num = 3000000;
    for (int j = 0; j < k; j++)
      if (g[j] < num) num = g[j], mi = j;
    t[i - 1] = mi + 'a';
    dp[i] = 2 * dp[i - 1] % mod;
    if (pre[t[i - 1]] != 0) dp[i] = (dp[i] - dp[pre[t[i - 1]] - 1] + mod) % mod;
    if (!f[t[i - 1]]) f[t[i - 1]] = 1, dp[i] = (dp[i] + 1) % mod;
    pre[t[i - 1]] = i;
    g[t[i - 1] - 'a'] = i;
  }
  printf("%lld\n", (dp[m + n] + 1) % mod);
  return 0;
}
