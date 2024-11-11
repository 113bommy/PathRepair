#include <bits/stdc++.h>
using namespace std;
int f[26][26];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, k;
  string s;
  for (i = 0; i < 26; i++)
    for (j = 0; j < 26; j++) f[i][j] = 0;
  cin >> n;
  while (n--) {
    cin >> s;
    m = s.size();
    i = s[0] - 97;
    j = s[m - 1] - 97;
    for (k = 0; k < 26; k++)
      if (f[k][i]) f[k][j] = max(f[k][j], f[k][i] + m);
    f[i][j] = max(f[i][j], m);
  }
  for (k = 0; k < 26; k++) n = max(n, f[k][k]);
  cout << n;
}
