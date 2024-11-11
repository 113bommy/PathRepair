#include <bits/stdc++.h>
using namespace std;
bool isLetter(char c) { return c >= 'a' && c <= 'z'; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int k = 0;
  cin >> k;
  cin >> s;
  int n = s.size();
  set<char> cSet;
  for (int i = 0; i < k; ++i) {
    char c = 'a' + i;
    cSet.insert(c);
  }
  for (int i = 0; i < n; ++i) {
    if (isLetter(s[i])) {
      if (s[i] - 'a' >= k || (isLetter(s[n - 1 - i]) && s[n - 1 - i] != s[i])) {
        cout << "IMPOSSIBLE";
        return 0;
      } else {
        cSet.erase(s[i]);
        if (s[n - 1 - i] == '?') {
          s[n - 1 - i] = s[i];
        }
      }
    } else {
      if (isLetter(s[n - 1 - i])) {
        char c = s[n - 1 - i];
        if (c - 'a' >= k) {
          cout << "IMPOSSIBLE";
          return 0;
        } else {
          s[i] = c;
          cSet.erase(c);
        }
      }
    }
  }
  int l = (n - 1) / 2, r = n / 2;
  while (l >= 0) {
    if (s[l] == '?') {
      if (cSet.empty()) {
        s[l] = 'a';
        s[r] = 'a';
      } else {
        char c = *cSet.begin();
        cSet.erase(c);
        s[l] = c;
        s[r] = c;
      }
    }
    --l;
    ++r;
  }
  if (!cSet.empty()) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << s;
  return 0;
}
