#include <bits/stdc++.h>
using namespace std;
string a[55];
bool d[55][55][30], d2[55][55][30];
int ans[55][55];
int main() {
  cout.setf(ios::fixed);
  cout.precision(12);
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= s1.length(); i++)
    for (int j = 0; j <= s1.length(); j++)
      for (int k = 0; k < 26; k++) d[i][j][k] = false;
  for (int i = 0; i < s1.length(); i++) {
    d[i][i + 1][s1[i] - 'a'] = true;
  }
  for (int i = 2; i <= s1.length(); i++)
    for (int j = 0; j + i <= s1.length(); j++)
      for (int k = j + 1; k <= j + i - 1; k++)
        for (int l = 0; l < n; l++) {
          if (d[j][k][a[l][3] - 'a'] && d[k][j + i][a[l][4] - 'a']) {
            d[j][j + i][a[l][0] - 'a'] = true;
          }
        }
  for (int i = 0; i <= s2.length(); i++)
    for (int j = 0; j <= s2.length(); j++)
      for (int k = 0; k < 26; k++) d2[i][j][k] = false;
  for (int i = 0; i < s2.length(); i++) {
    d2[i][i + 1][s2[i] - 'a'] = true;
  }
  for (int i = 2; i <= s2.length(); i++)
    for (int j = 0; j + i <= s2.length(); j++)
      for (int k = j + 1; k <= j + i - 1; k++)
        for (int l = 0; l < n; l++) {
          if (d2[j][k][a[l][3] - 'a'] && d2[k][j + i][a[l][4] - 'a']) {
            d2[j][j + i][a[l][0] - 'a'] = true;
          }
        }
  for (int i = 0; i <= s1.length(); i++)
    for (int j = 0; j <= s2.length(); j++) ans[i][j] = 1000;
  ans[0][0] = 0;
  for (int i = 0; i <= s1.length(); i++)
    for (int j = 0; j <= s2.length(); j++)
      if (ans[i][j] < 1000) {
        for (int k = 0; k < 26; k++)
          for (int i1 = i + 1; i1 <= s1.length(); i1++)
            for (int j1 = j + 1; j1 <= s2.length(); j1++)
              if (d[i][i1][k] && d[j][j1][k])
                ans[i1][j1] = min(ans[i1][j1], ans[i][j] + 1);
      }
  if (ans[s1.length()][s2.length()] != 1000)
    cout << ans[s1.length()][s2.length()];
  else
    cout << -1;
  return 0;
}
