#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using ii = pair<ll, ll>;
constexpr bool LOG = true;
void Log() {
  if (LOG) cerr << "\n";
}
template <class T, class... S>
void Log(T t, S... s) {
  if (LOG) cerr << t << "\t", Log(s...);
}
struct GS {
  ll pos, price;
};
bool operator<(GS l, GS r) { return l.price < r.price; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll d, n, m;
  cin >> d >> n >> m;
  vector<GS> gs(m);
  for (auto &x : gs) cin >> x.pos >> x.price;
  gs.push_back({0, 0});
  sort(begin(gs), end(gs));
  set<ll> done;
  done.insert(d);
  ll ans = 0;
  for (auto g : gs) {
    auto it = done.lower_bound(g.pos);
    ll arr = 0;
    if (it != done.begin()) {
      auto p = prev(it);
      arr = max(0ll, m - (g.pos - *p));
    }
    ll needed = min(m, *it - g.pos);
    if (needed > arr) {
      ans += (needed - arr) * g.price;
    }
    done.insert(g.pos);
  }
  ll lp = 0;
  for (auto x : done) {
    if (x > lp + m) {
      cout << "-1\n";
      return 0;
    } else
      lp = x;
  }
  cout << ans << endl;
  return 0;
}
