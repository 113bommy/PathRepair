#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;
ll res;
ll a[N];
void solve() {
  ll wm, wf, cs, cw, ans = 0, me, rem, fl, s, w;
  cin >> wm >> wf >> cs >> cw >> s >> w;
  for (int i = 0; i <= cs; ++i) {
    me = fl = 0;
    if (i * s > wm) {
      ll can = wm / w;
      if (can > cw) {
        me = cw;
        fl = min(cs, wf / s);
      } else {
        me = can;
        if (s < w) {
          rem = cw - can;
          if (wf > cs * s) {
            fl = cs + min(rem, (wf - cs * s) / w);
          } else
            fl = wf / s;
        } else {
          rem = cw - can;
          if (wf > rem * w) {
            fl = rem + min(cs, (wf - rem * w) / s);
          } else
            fl = wf / w;
        }
      }
    } else {
      ll can = (wm - i * s) / w;
      if (can > cw) {
        me = cw + i;
        fl = min((cs - i), wf / s);
      } else {
        me = can + i;
        if (s < w) {
          rem = cw - can;
          if (wf > (cs - i) * s) {
            fl = (cs - i) + min(rem, (wf - (cs - i) * s) / w);
          } else
            fl = wf / s;
        } else {
          rem = cw - can;
          if (wf > rem * w) {
            fl = rem + min((cs - i), (wf - rem * w) / s);
          } else
            fl = wf / w;
        }
      }
    }
    ans = max(ans, fl + me);
  }
  cout << ans << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
