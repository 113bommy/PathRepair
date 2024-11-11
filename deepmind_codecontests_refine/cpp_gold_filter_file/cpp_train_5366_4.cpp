#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int, int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;
using ld = long double;
using vld = vector<ld>;
using vvld = vector<vld>;
using pll = pair<ll, ll>;
struct pt {
  ll x, y;
};
using vpt = vector<pt>;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    vpt v(n);
    for (pt& p : v) cin >> p.x >> p.y;
    map<pll, int> m;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        m[{v[i].x + v[j].x, v[i].y + v[j].y}]++;
      }
    }
    int ans = 0;
    for (auto x : m) {
      int co = x.second;
      ans += co * (co - 1) / 2;
    }
    cout << ans << '\n';
  }
}
