#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
int nb, ns, nc, pb, ps, pc;
int rb, rs, rc;
ll r;
ll mx = 1e12 + 1000;
string s;
bool ok(ll pos) {
  ll needb = 1ll * rb * pos, needs = 1ll * rs * pos, needc = 1ll * rc * pos;
  if ((ll)nb >= needb && (ll)ns >= needs && (ll)nc >= needc)
    return true;
  else {
    needb = max((ll)0, needb - nb);
    needc = max((ll)0, needc - nc);
    needs = max((ll)0, needs - ns);
    return (ll)r >= (needb * pb + needs * ps + needc * pc);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  rb = rs = rc = 0;
  for (char c : s) {
    rb += c == 'B';
    rs += c == 'S';
    rc += c == 'C';
  }
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  ll begin = 0, end = mx, ans = 0;
  while (begin <= end) {
    ll mid = begin + (end - begin) / 2;
    if (ok(mid)) {
      begin = mid + 1;
      ans = mid;
    } else {
      end = mid - 1;
    }
  }
  cout << ans << endl;
}
