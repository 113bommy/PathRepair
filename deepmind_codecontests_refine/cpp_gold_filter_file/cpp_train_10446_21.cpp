#include <bits/stdc++.h>
using namespace std;
const long double pi = 4 * atan((long double)1);
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long llinf = 1e18;
const long long nax = 0;
long long w, h;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> h >> w;
  long long ans = 0;
  for (int i = 2; i <= h; i += 2) {
    for (int j = 2; j <= w; j += 2) {
      ans += (h - i + 1) * (w - j + 1);
    }
  }
  cout << ans << '\n';
}
