#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-9;
inline int sgn(double a) { return a < -eps ? -1 : a > eps; }
string s;
int sz;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  sz = s.size();
  long long ans = 0;
  for (int i = 0; i < sz; i++) {
    if (i == 0) {
      if ((s[i] - '0') % 4 == 0) {
        ans++;
      }
    } else {
      int t = s[i] - '0';
      t += (s[i - 1] - '0') * 10;
      if (t % 4 == 0) {
        ans += i;
      }
      if ((s[i] - '0') % 4 == 0) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
