#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  long long INF = 2e16;
  long long a[27][27];
  cin >> n;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++) {
      a[i][j] = INF;
      if (i == j) a[i][j] = 0;
    }
  for (int i = 0; i < n; i++) {
    char a1, b1;
    cin >> a1 >> b1;
    int c;
    cin >> c;
    a[a1 - 'a'][b1 - 'a'] = min(a[a1 - 'a'][b1 - 'a'], (long long)c);
  }
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
  if (s1.size() != s2.size())
    cout << "-1";
  else {
    string s = s1;
    long long ans = 0;
    for (int i = 0; i < s1.size(); i++) {
      long long val = INF;
      for (int j = 0; j < 26; j++)
        if (a[s1[i] - 'a'][j] + a[s2[i] - 'a'][j] < val) {
          val = a[s1[i] - 'a'][j] + a[s2[i] - 'a'][j];
          s[i] = j + 'a';
        };
      if (val >= INF) {
        cout << "-1";
        return 0;
      } else
        ans += val;
    }
    cout << ans << endl;
    cout << s;
  }
  return 0;
}
