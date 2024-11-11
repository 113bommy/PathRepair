#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * w;
}
const long long mod = 998244353;
int n, k, a[1005];
long long f[1005][1005], res[100005], ans, s[1005][1005];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  a[0] = -1000000000;
  for (int v = 1; v * (k - 1) <= a[n]; v++) {
    f[0][0] = 1;
    s[0][0] = 1;
    int now = 0;
    for (int i = 1; i <= n; i++) {
      while (a[now] <= a[i] - v) now++;
      for (int j = 0; j <= k; j++) {
        if (j) f[i][j] = s[now - 1][j - 1];
        s[i][j] = (s[i - 1][j] + f[i][j]) % mod;
      }
      res[v] += f[i][k];
    }
    ans += res[v] % mod;
  }
  cout << ans << endl;
  return 0;
}
