#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using ii = pair<ll, ll>;
constexpr bool LOG = false;
void Log() {
  if (LOG) cerr << "\n";
}
template <class T, class... S>
void Log(T t, S... s) {
  if (LOG) cerr << t << "\t", Log(s...);
}
struct S {
  ld not_seen;
  ld p;
  ll i;
};
ld eps = 1e-13;
bool operator<(S l, S r) {
  ld a = l.not_seen / (1 - l.not_seen) * l.p;
  ld b = r.not_seen / (1 - r.not_seen) * r.p;
  return a < b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  priority_queue<S> pq;
  vector<ld> ps(n), seen(n, 0);
  for (ll i = 0; i < (n); ++i) {
    ld x;
    cin >> x;
    ps[i] = x / 100;
    pq.push({1, x / 100, i});
    Log("push:", 1, x / 100, i);
  }
  Log("reading done, pq size:", pq.size());
  ld ans = 0;
  for (ll i = 0; i < (1000000); ++i) {
    S s = pq.top();
    Log("\nTOP:", s.not_seen, s.p, s.i, "size", pq.size());
    pq.pop();
    ld seen_others = 1;
    for (ll j = 0; j < (n); ++j) {
      Log("seen", j, seen[j]);
      if (j != s.i) seen_others *= seen[j];
    }
    ld not_seen_i = s.not_seen;
    ld ansi = seen_others * not_seen_i * s.p;
    ans += ansi * (i + 1);
    seen[s.i] = seen[s.i] + (1 - seen[s.i]) * s.p;
    Log("s_os", seen_others, "nsi", s.not_seen, "ansi", ansi);
    pq.push({1 - seen[s.i], s.p, s.i});
    Log("PUSH:", 1 - seen[s.i], s.p, s.i);
    cin.get();
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
