#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int f[MAXN][MAXN];
int main() {
  long long n, m, b, mod;
  cin >> n >> m >> b >> mod;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  f[0][0] = 1;
  for (int wr = 0; wr < n; wr++)
    for (int i = 0; i < m; i++)
      for (int j = 0; j < b; j++)
        if (f[i][j])
          if (a[wr] + j <= b)
            f[i + 1][a[wr] + j] = (f[i + 1][a[wr] + j] + f[i][j]) % mod;
  long long ans = 0;
  for (int j = 0; j <= b; j++) ans = (ans + f[m][j]) % mod;
  cout << ans;
}
