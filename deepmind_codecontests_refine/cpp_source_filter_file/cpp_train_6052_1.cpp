#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ;
  string s;
  cin >> s;
  int a[5][5];
  for (int i = 0; i < 5; i++) {
    memset(a[i], 0, sizeof(a[i]));
  }
  int f = 0, g = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (f == 0) {
        cout << "4 2\n";
        f = 1;
      } else {
        cout << "3 2\n";
        f = 0;
      }
    } else {
      if (g == 0) {
        cout << "3 1\n";
        g = 1;
      } else {
        cout << "3 4\n";
        g = 0;
      }
    }
  }
  cerr << "\ntime elapsed:" << clock() * 1000.0 / CLOCKS_PER_SEC << "ms"
       << "\n";
  return 0;
}
