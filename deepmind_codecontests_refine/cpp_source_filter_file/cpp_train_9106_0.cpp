#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  cin >> s >> k;
  if (s.size() % 4 != 0) {
    cout << "NO\n";
    return 0;
  }
  int l = s.size() / k;
  for (int i = 0; i < k; ++i) {
    string t = s.substr(i * l, l);
    for (int j = 0; j < l; ++j) {
      if (s[i * l + j] != t[l - 1 - j]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}
