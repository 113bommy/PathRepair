#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool f = true;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      cout << "YES\n";
      cout << s[i] << s[i + 1] << endl;
      f = false;
      break;
    }
  }
  if (f) cout << "NO\n";
  return 0;
}
