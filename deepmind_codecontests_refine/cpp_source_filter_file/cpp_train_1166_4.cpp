#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, n, ans, cn1, cn2, cn3, t;
string s, s1, s2;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  cin >> e;
  cin >> f;
  ans = 0;
  if (e > f) {
    ans = min(a, d);
    d = d - ans;
    ans = ans * e;
    ans += min(b, min(c, d)) * f;
    cout << ans;
  } else if (e < f) {
    ans = 0;
    ans = min(b, min(c, d));
    d = d - ans;
    ans = ans * f;
    ans += min(a, d) * e;
    cout << ans << endl;
  }
  return 0;
}
