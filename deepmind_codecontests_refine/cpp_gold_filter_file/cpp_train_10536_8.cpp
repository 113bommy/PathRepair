#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int v = min(count(s.begin(), s.end(), 'L'), count(s.begin(), s.end(), 'R'));
    int h = min(count(s.begin(), s.end(), 'U'), count(s.begin(), s.end(), 'D'));
    if (v > 0 && h > 0) {
      cout << ((v + h) << 1) << '\n';
      cout << (string(v, 'L') + string(h, 'U') + string(v, 'R') +
               string(h, 'D'))
           << '\n';
    } else if (v == 0) {
      if (h >= 1) {
        cout << 2 << '\n';
        cout << "UD\n";
      } else {
        cout << 0 << '\n';
      }
    } else if (h == 0) {
      if (v >= 1) {
        cout << 2 << '\n';
        cout << "LR\n";
      } else {
        cout << 0 << '\n';
      }
    }
  }
  return EXIT_SUCCESS;
}
