#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l >> s;
    int first = s[0] - '0';
    int second = s[1] - '0';
    if (s.length() == 2 && first >= second) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s[i] << " " << s.substr(1) << endl;
  }
  return 0;
}
