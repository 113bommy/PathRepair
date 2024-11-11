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
  ll l, r;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, p;
  cin >> n >> p;
  vector<S> s(n);
  for (auto &x : s) cin >> x.l >> x.r;
  s.push_back(s.front());
  ld ans = 0;
  for (ll i = 0; i < (n); ++i) {
    ld pr1 = s[i].r / p - (s[i].l - 1) / p;
    ld pr2 = s[i + 1].r / p - (s[i].l - 1) / p;
    ld p1 = pr1 / (s[i].r - s[i].l + 1);
    ld p2 = pr2 / (s[i + 1].r - s[i + 1].l + 1);
    ans += 2000 * (1 - (1 - p1) * (1 - p2));
  }
  cout << setprecision(15) << double(ans) << endl;
  return 0;
}
