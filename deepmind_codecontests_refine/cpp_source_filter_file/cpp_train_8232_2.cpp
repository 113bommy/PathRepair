#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  while (k--) {
    long int ans = -1;
    long int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    if (ta == tb) {
      ans = abs(fb - fa);
    } else if (a <= fa && fa <= b) {
      ans = abs(ta - tb) + (abs(fa - fb));
    } else if (fa < a) {
      ans = abs(a - fa) + abs(ta - tb) + abs(a - fb);
    } else if (fb > b) {
      ans = abs(b - fa) + abs(ta - tb) + abs(fb - b);
    }
    cout << ans << endl;
  }
}
