#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, mod = 1e9 + 7, inf = 1e18;
int ar[27];
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  long long r[n], c[m];
  for (int i = 0; i < n; i++) {
    r[i] = 0;
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') r[i]++;
  }
  for (int j = 0; j < m; j++) {
    c[j] = 0;
    for (int i = 0; i < n; i++)
      if (s[i][j] == '*') c[j]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') ans += (r[i] - 1) * (c[j] - 1);
  cout << ans << "\n";
}
