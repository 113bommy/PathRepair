#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int a[2010][2010];
int rockR[2020][2020];
int rockD[2020][2020];
long long R[2020][2020];
long long D[2020][2020];
long long preR[2020][2020], preD[2020][2020];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= int(n); i++) {
    string s;
    cin >> s;
    for (int j = 0; j < int(m); j++)
      if (s[j] == 'R')
        a[i][j + 1] = 1;
      else
        a[i][j + 1] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      rockR[i][j] = rockR[i][j + 1] + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= int(m); j++) rockD[i][j] = rockD[i + 1][j] + a[i][j];
  }
  if (n == 1 && m == 1) {
    cout << 1 - a[n][m] << '\n';
    return 0;
  }
  D[n][m] = 1;
  R[n][m] = 1;
  preD[n][m] = 1;
  preR[n][m] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (i == n && j == m) continue;
      int right = rockR[i][j] - a[i][j];
      int rem = m - j;
      int can = rem - right;
      R[i][j] = ((preD[i][j + 1] - preD[i][j + can + 1]) % mod + mod) % mod;
      int down = rockD[i][j] - a[i][j];
      rem = n - i;
      can = rem - down;
      D[i][j] = ((preR[i + 1][j] - preR[i + 1 + can][j]) % mod + mod) % mod;
      preR[i][j] = preR[i + 1][j] + R[i][j];
      preR[i][j] %= mod;
      preD[i][j] = preD[i][j + 1] + D[i][j];
      preD[i][j] %= mod;
    }
  }
  cout << (D[1][1] + R[1][1]) % mod << '\n';
  return 0;
}
