#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9 + 7;
const int64_t primm = 998244353;
long long erk[35], st, en, mid, mad;
string s;
char c;
int main() {
  erk[0] = 0;
  erk[1] = 1;
  for (long long i = (long long)2; i < (long long)35; i++)
    erk[i] = 2 * erk[i - 1];
  while (cin >> s) {
    if (s[0] != 's') return 0;
    for (long long i = 0; i < (long long)34; i++) {
      cout << "? " << erk[i] << " " << erk[i + 1] << endl;
      cin >> c;
      if (c == 'x') {
        st = erk[i];
        en = erk[i + 1];
        break;
      }
    }
    while (en - st > 1) {
      mid = en + st;
      mid /= 2;
      mad = en - st;
      mad /= 2;
      cout << "? " << mid << " " << mad << endl;
      cin >> c;
      if (c == 'x')
        st = mid;
      else
        en = mid;
    }
    cout << "!" << en << endl;
  }
}
