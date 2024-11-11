#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '8' && (n - i) >= 11) {
        ok = 1;
        break;
      }
    }
    if (ok)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
