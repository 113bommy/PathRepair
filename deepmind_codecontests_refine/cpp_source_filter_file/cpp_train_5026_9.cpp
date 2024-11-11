#include <bits/stdc++.h>
using namespace std;
long double const PI = 4 * atan((long double)1);
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool res[4];
    res[0] = (((a + b) & 1) && (a > 0 || d > 0));
    res[1] = (((a + b) & 1) && (b > 0 || c > 0));
    res[2] = (((a + b) & 1) == 0 && (a > 0 || d > 0));
    res[3] = (((a + b) & 1) == 0 && (b > 0 || c > 0));
    for (int i = 0; i < 4; ++i) {
      if (i) cout << " ";
      cout << (res[i] ? "Ya" : "Tidak");
    }
    cout << '\n';
  }
  return 0;
}
