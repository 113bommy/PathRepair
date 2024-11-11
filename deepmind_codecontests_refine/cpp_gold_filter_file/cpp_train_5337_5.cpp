#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
inline long long two(long long n) { return 1 << n; }
const long long N = 1e4 + 5;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    long long r, g, b, w;
    cin >> r >> g >> b >> w;
    long long cc = 0;
    if (r % 2 == 1) cc++;
    if (b % 2 == 1) cc++;
    if (g % 2 == 1) cc++;
    if (w % 2 == 0) {
      if (cc == 2)
        cout << "No\n";
      else
        cout << "Yes\n";
    } else {
      if (cc == 2) {
        if (r % 2 == 0 && r > 0 || b % 2 == 0 && b > 0 || g % 2 == 0 && g > 0)
          cout << "Yes\n";
        else
          cout << "No\n";
      } else {
        if (cc == 1)
          cout << "No\n";
        else
          cout << "Yes\n";
      }
    }
  }
  return 0;
}
