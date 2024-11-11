#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  ;
  long long n, c = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == s[i + 1] && s[i] != '?') {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (i == 0 || i == n - 1) {
        cout << "YES" << endl;
        return 0;
      }
      if (s[i + 1] == '?') {
        cout << "YES" << endl;
        return 0;
      }
      if (s[i - 1] == s[i + 1]) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
