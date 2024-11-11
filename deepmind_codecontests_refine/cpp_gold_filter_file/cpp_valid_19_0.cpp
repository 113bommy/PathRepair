#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 998244353;
const ll INF = 1e18;
ll Pow(ll a, ll n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  if (n % 2 == 1) return (a * Pow(a, n - 1));
  ll t = Pow(a, n / 2);
  return (t * t);
}
int main() {
  ll T;
  cin >> T;
  for (long long l = 0; l < (T); ++l) {
    ll N;
    cin >> N;
    vec A(N);
    for (long long i = 0; i < (N); ++i) cin >> A.at(i);
    if (N == 1) {
      if (A.at(0) == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      continue;
    }
    ll t = 0;
    for (long long i = 0; i < (N); ++i) {
      for (long long tmp = 0; tmp < (Pow(3, N - 1)); ++tmp) {
        ll k = 0, s = tmp;
        for (long long j = 0; j < (N); ++j) {
          if (j == i) {
            continue;
          }
          if (s % 3 == 1)
            k += A.at(j);
          else if (s % 3 == 2)
            k -= A.at(j);
          s /= 3;
        }
        if (k == A.at(i)) t = 1;
      }
    }
    if (t == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
