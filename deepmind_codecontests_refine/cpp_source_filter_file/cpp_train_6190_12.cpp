#include <bits/stdc++.h>
using namespace std;
int n, p;
string s;
int main() {
  cin >> n >> p;
  cin >> s;
  string ans = "";
  for (int i = n - 1; i >= 0; i--)
    for (int let = s[i] - 'a' + 1; let < p; let++) {
      char c = char('a' + let);
      bool ok = true;
      if (i > 0) ok &= (c != s[i - 1]);
      if (i > 1) ok &= (c != s[i - 2]);
      if (!ok) continue;
      for (int j = 0; j < i; j++) ans += s[j];
      ans += c;
      for (int j = i + 1; j < n; j++) {
        char c = 'a';
        while (c < char('a' + p) and
               ((j > 0 and c == s[j - 1]) or (j > 1 and c == s[j - 2])))
          c++;
        if (c == char('a' + p)) {
          ok = 0;
          break;
        }
        ans += c;
      }
      if (!ok) {
        ans = "";
        continue;
      }
      cout << ans << endl;
      return 0;
    }
  cout << "NO\n";
  return 0;
}
