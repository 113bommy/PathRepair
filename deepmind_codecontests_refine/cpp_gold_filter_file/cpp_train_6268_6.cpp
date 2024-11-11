#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
const ll MOD = 998244353;
ll mod_pow(ll a, ll e, ll m) {
  if (e == 0) return 1;
  return mod_pow(a * a % m, e / 2, m) * (e & 1 ? a : 1) % m;
}
ll inv(ll i) { return mod_pow(i, MOD - 2, MOD); }
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  ll n;
  cin >> n;
  vector<vector<int>> desired(n);
  vector<int> child_for_pres(1000001);
  for (int i = (0); i < (n); ++i) {
    int k;
    cin >> k;
    desired[i] = vector<int>(k);
    for (int j = (0); j < (k); ++j)
      cin >> desired[i][j], child_for_pres[desired[i][j]]++;
  }
  ll c = 0;
  for (int i = (0); i < (n); ++i) {
    for (auto& j : (desired[i])) {
      c = (c + child_for_pres[j] * inv(n * n % MOD) % MOD *
                   inv(desired[i].size())) %
          MOD;
    }
  }
  cout << c;
  cout.flush();
  return 0;
}
