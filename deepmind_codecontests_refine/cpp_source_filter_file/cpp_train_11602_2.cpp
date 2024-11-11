#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5;
int n;
char ans[maxN];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (int j = 0; j < s.length(); j++) {
      if (ans[j] == 0) ans[j] = '?';
      if (s[j] == '?' || ans[j] == 'X') continue;
      if (ans[j] == '?' && s[j] != '?')
        ans[j] = s[j];
      else if (ans[j] != '?' && s[j] != '?' && ans[j] != s[j])
        ans[j] = 'X';
    }
  }
  for (int i = 0; i < s.length(); i++) {
    if (ans[i] == 'X')
      ans[i] = '?';
    else if (ans[i] == '?')
      ans[i] = 'a';
  }
  cout << ans;
  return 0;
}
