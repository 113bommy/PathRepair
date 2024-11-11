#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long tim;
int ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> t;
  tim = 1000000000;
  for (int i = 0; i < (n); i++) {
    long long s, d;
    cin >> s >> d;
    if (s > t) {
      if (s < tim) {
        tim = s;
        ans = i;
      }
    }
    if ((t - s) % d == 0) {
      if (t < tim) {
        tim = t;
        ans = i;
      }
    } else if (t - ((t - s) % d) + d < tim) {
      tim = (t - ((t - s) % d)) + d;
      ans = i;
    }
  }
  cout << ans + 1 << "\n";
  return 0;
}
