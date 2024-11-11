#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i < n / 2) {
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
        } else {
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        }
        f = true;
        break;
      }
    }
    if (!f) {
      cout << 1 << " " << n << " " << 1 << " " << n / 2 << endl;
    }
  }
  return 0;
}
