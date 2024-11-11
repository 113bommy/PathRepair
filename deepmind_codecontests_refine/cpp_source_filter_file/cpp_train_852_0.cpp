#include <bits/stdc++.h>
using namespace std;
int n, i;
string s[1010];
int f[1010][1010], g[1010][1010], j, ans;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++)
    for (j = n - 1; j > i; j--) {
      if (s[i][j] - 48 != (f[i][j] + g[i][j]) % 2) {
        ans++;
        f[i][j] ^= 1;
        g[i][j] ^= 1;
      }
      f[i][j - 1] ^= f[i][j];
      g[i + 1][j] ^= g[i][j];
    }
  for (i = n - 1; i >= 0; i--)
    for (j = 0; j < i; j++) {
      if (s[i][j] - 48 != (f[i][j] + g[i][j]) % 2) {
        ans++;
        f[i][j] ^= 1;
        g[i][j] ^= 1;
      }
      f[i][j + 1] ^= f[i][j];
      g[i - 1][j] ^= g[i][j];
    }
  for (i = 1; i <= n; i++)
    if (s[i][i] - 48 != (f[i][j] + g[i][j]) % 2) ans++;
  cout << ans;
}
