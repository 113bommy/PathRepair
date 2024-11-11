#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
const ll INF = LLONG_MAX;
const int N = (int)2e+5 + 8;
ld x;
vector<pair<ll, ll>> res;
void MAIN(int tc) {
  cin >> x;
  for (ld a = 1; a <= 1e7; a++) {
    ld num = (6 * x) + (a * a * a) - (a);
    ld den = (3 * a * a) + (3 * a);
    ld b = num / den;
    if (fmod(num, den) == 0 && a <= b) {
      res.push_back({a, b});
      res.push_back({b, a});
    }
  }
  sort((res).begin(), (res).end(), [&](pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.first == p2.first ? p1.first < p2.first : p1.second > p2.second;
  });
  res.resize(unique(res.begin(), res.end()) - res.begin());
  ;
  cout << res.size() << "\n";
  ;
  for (auto [a, b] : res) {
    cout << a << " " << b << "\n";
    ;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int test_cases = 1;
  for (int i = 1; i <= test_cases; i++) {
    MAIN(i);
  }
}
