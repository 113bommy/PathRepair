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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll s, x;
  cin >> s >> x;
  if (x > s || (s - x) & 1 || ((s - x) >> 1) & x) {
    cout << 0 << endl;
    return 0;
  }
  cout << (1ll << __builtin_popcountll(x)) - 2 * (x == s ? 1 : 0) << endl;
  return 0;
}
