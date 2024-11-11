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
struct S {
  ld x;
  ld seen;
  ld p;
};
bool operator<(S l, S r) { return l.x < r.x; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  priority_queue<S> pq;
  ld seen_all = 1;
  for (ll i = 0; i < (n); ++i) {
    ld x;
    cin >> x;
    seen_all *= x / 100;
    pq.push({1 - x / 100, x / 100, x / 100});
  }
  Log("seen_all", seen_all);
  ld ans = n;
  for (ll i = 0; i < (1000000); ++i) {
    S s = pq.top();
    pq.pop();
    ld seen_others = seen_all / s.seen;
    ld ansi = seen_others * (1 - s.seen) * s.p;
    ans += ansi * (i + 1);
    ld new_seen = s.seen + (1 - s.seen) * s.p;
    pq.push({(1 - new_seen) / new_seen * s.p, new_seen, s.p});
    seen_all *= new_seen / s.seen;
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
