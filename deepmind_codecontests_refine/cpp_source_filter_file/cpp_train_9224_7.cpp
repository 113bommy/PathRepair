#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[101];
  int n, i;
  bool f;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s[i];
    f = true;
    for (int j = 1; j < i; j++) {
      if (s[i] == s[j]) {
        f = false;
        cout << "YES" << endl;
        continue;
      }
    }
    if (f) cout << "NO" << endl;
  }
  return 0;
}
