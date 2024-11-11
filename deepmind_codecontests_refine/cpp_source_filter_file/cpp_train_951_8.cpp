#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int N = 2 * 1e5 + 10;
int n, a[N];
string maxx(string l, string r) {
  if (int(l.size()) > int(r.size())) return l;
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  string ans = "", cur = "", s_l, s_r;
  for (int l = 0, r = n - 1, ant = -1; l <= r;) {
    18;
    if (a[l] == a[r] && a[l] > ant) {
      s_l = s_r = ans;
      int _l, _r, _ant = ant;
      _l = l, _r = r;
      while (_l < r && a[_l] > _ant) {
        s_l += "L";
        _ant = a[_l];
        _l++;
      }
      _ant = ant;
      while (l < _r && a[_r] > _ant) {
        s_r += "R";
        _ant = a[_r];
        _r--;
      }
      cur = maxx(cur, maxx(s_l, s_r));
    }
    if ((a[l] < a[r] && ant < a[l]) || (ant > a[r] && ant < a[l])) {
      ans += "L";
      ant = a[l];
      l++;
    } else if (ant < a[r]) {
      ans += "R";
      ant = a[r];
      r--;
    } else
      break;
  }
  ans = maxx(ans, cur);
  cout << int(ans.size()) << '\n' << ans << '\n';
  return 0;
}
