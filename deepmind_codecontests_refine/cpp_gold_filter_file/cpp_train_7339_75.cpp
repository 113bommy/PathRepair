#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
long long mod = 1e9 + 7;
long long const INFll = 9223372036854775807;
long double INFld = 28e14;
long long const INF = 2e9;
long double const eps = 1e-7;
long double const pi = acos(-1.0);
using namespace std;
struct __debug__ {
  __debug__(string filename) {
    ios_base::sync_with_stdio(0);
    string filein = filename + ".in";
    string fileout = filename + ".out";
  }
  ~__debug__() {}
} __Debug__("mincut");
string q[8];
int main() {
  for (int i = 0; i < 8; i++) {
    cin >> q[i];
  }
  char ans = 'A';
  int a = INF;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (q[i][j] == 'W') {
        int k = i;
        bool ok = 1;
        while (k--) {
          if (q[k][j] == 'B') {
            ok = 0;
            break;
          }
        }
        if (ok && a >= i) {
          a = i;
          ans = 'A';
        }
      }
      if (q[i][j] == 'B') {
        int k = i;
        bool ok = 1;
        while (k++ < 7) {
          if (q[k][j] == 'W') {
            ok = 0;
            break;
          }
        }
        if (ok && a > 7 - i) {
          a = 7 - i;
          ans = 'B';
        }
      }
    }
  }
  cout << ans;
}
