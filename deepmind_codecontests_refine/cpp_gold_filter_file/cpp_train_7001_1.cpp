#include <bits/stdc++.h>
using namespace std;
long long int count(string s) {
  string s2 = "abacaba";
  long long int x = 0;
  for (long long int i = 0; i + 7 <= s.length(); i++)
    if (s.substr(i, 7) == s2) x++;
  return x;
}
int main() {
  long long int i, j, k, m, n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    string s, s2 = "abacaba";
    cin >> s;
    long long int x = 0;
    for (i = 0; i + 7 <= n; i++)
      if (s.substr(i, 7) == s2) x++;
    if (x > 1) {
      cout << "No\n";
      continue;
    }
    if (x == 1) {
      for (i = 0; i < n; i++)
        if (s[i] == '?') s[i] = 'z';
      cout << "Yes\n";
      cout << s << endl;
      continue;
    }
    bool flag = false;
    for (i = 0; i + 7 <= n; i++) {
      long long int ctr = 0;
      bool f = true;
      for (j = i; j <= i + 6; j++, ctr++) {
        if (s[j] == '?' or s[j] == s2[ctr]) {
        } else
          f = false;
      }
      if (f) {
        long long int ctr = 0;
        string s1 = s;
        for (j = i; j <= i + 6; j++) s[j] = s2[ctr++];
        for (long long int q = 0; q < n; q++)
          if (s[q] == '?') s[q] = 'z';
        if (count(s) == 1) {
          flag = true;
          cout << "Yes\n" << s << endl;
          break;
        } else
          s = s1;
      }
    }
    if (!flag) cout << "No\n";
  }
}
