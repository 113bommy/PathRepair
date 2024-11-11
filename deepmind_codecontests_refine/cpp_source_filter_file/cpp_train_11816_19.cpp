#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long binpow(long long x, int deg) {
  if (deg <= 1) {
    if (deg == 1) return x;
    return 1;
  }
  if (deg & 1) return x * binpow(x, deg - 1) % MOD;
  return binpow(x * x % MOD, deg / 2);
}
long long rev(long long x) { return binpow(x, MOD - 2); }
vector<long long> fuck(123456);
vector<long long> revFuck(123456);
void pre() {
  fuck[0] = 1;
  for (int i = 1; i < fuck.size(); ++i) fuck[i] = fuck[i - 1] * i % MOD;
  for (int i = 0; i < revFuck.size(); ++i) revFuck[i] = rev(fuck[i]);
}
long long C(int n, int k) {
  return fuck[n] * revFuck[k] % MOD * revFuck[n - k] % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  pre();
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  a.push_back(make_pair(h, w));
  vector<long long> ways(n + 1);
  for (int i = 0; i < a.size(); ++i) {
    ways[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
    for (int j = 0; j < i; ++j)
      if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
        ways[i] += MOD - (ways[j] *
                          C(a[i].first - a[j].first + a[i].second - a[j].second,
                            a[i].first - a[j].first) %
                          MOD);
        ways[i] %= MOD;
      }
  }
  cout << ways.back() << "\n";
}
