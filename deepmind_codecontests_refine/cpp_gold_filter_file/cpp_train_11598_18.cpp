#include <bits/stdc++.h>
using namespace std;
long long const MAXA = (long long)1e9 + 1;
int main() {
  string s;
  cin >> s;
  if (s[0] != '1') {
    cout << "NO\n";
    return 0;
  }
  for (long long i = 0; i < s.length(); i++) {
    if (!(s[i] == '4' || s[i] == '1')) {
      cout << "NO\n";
      return 0;
    }
    if (i <= s.length() - 3)
      if (s[i] == '4' && s[i + 1] == '4' && s[i + 2] == '4') {
        cout << "NO\n";
        return 0;
      }
  }
  cout << "YES\n";
  return 0;
}
