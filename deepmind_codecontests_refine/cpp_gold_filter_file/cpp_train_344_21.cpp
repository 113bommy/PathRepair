#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  vector<char> v;
  int a[150] = {0}, f;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) a[s[i]]++;
  for (int i = 0; i < t.length(); i++) {
    if (a[t[i]] && i != s.length() - 1) {
      v.push_back(t[i]);
      a[t[i]]--;
    } else {
      for (int j = t[i] + 1; j < 'a' + 26; j++) {
        if (a[j]) {
          v.push_back(j);
          a[j]--;
          goto print;
        }
      }
      while (v.size()) {
        char c = v.back();
        a[c]++;
        v.pop_back();
        for (int j = c + 1; j < 'a' + 26; j++) {
          if (a[j]) {
            v.push_back(j);
            a[j]--;
            goto print;
          }
        }
      }
      cout << -1 << endl;
      return 0;
    }
  }
print:
  for (int i = 0; i < v.size(); i++) cout << (char)v[i];
  for (int i = 'a'; i < 'a' + 26; i++) {
    while (a[i]--) cout << char(i);
  }
  cout << endl;
  return 0;
}
