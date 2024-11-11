#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e3 + 5;
const long long Mod = 51123987;
const long long inf = 0x3f3f3f3f3f3f3f;
int f[155][55][55][55] = {}, Next[151][3] = {};
int main() {
  long long n, ans = 0;
  string s;
  cin >> n >> s;
  f[0][0][0][0] = 1;
  int a[300] = {};
  a['a'] = n + 1;
  a['b'] = n + 1;
  a['c'] = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    a[s[i]] = i;
    for (int j = 0; j < 3; j++) Next[i][j] = a[j + 'a'];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n / 3 + 1; j++)
      for (int k = 0; k <= n / 3 + 1; k++)
        for (int l = 0; l <= n / 3 + 1; l++) {
          if (f[i][j][k][l]) {
            f[Next[i][0]][j + 1][k][l] += f[i][j][k][l];
            f[Next[i][1]][j][k + 1][l] += f[i][j][k][l];
            f[Next[i][2]][j][k][l + 1] += f[i][j][k][l];
            f[Next[i][0]][j + 1][k][l] %= Mod;
            f[Next[i][1]][j][k + 1][l] %= Mod;
            f[Next[i][2]][j][k][l + 1] %= Mod;
          }
          if (j + k + l == n && abs(j - k) <= 1 && abs(j - l) <= 1 &&
              abs(k - l) <= 1) {
            ans = (ans + f[i][j][k][l]) % Mod;
          }
        }
  }
  cout << ans << endl;
  return 0;
}
