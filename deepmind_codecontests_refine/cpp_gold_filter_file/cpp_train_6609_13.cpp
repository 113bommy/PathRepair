#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const int iinf = 1 << 29;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long mrand(long long B) { return (unsigned long long)rng() % B; }
long long cross(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first * p2.second - p2.first * p1.second;
}
bool online(pair<long long, long long> a, pair<long long, long long> b,
            pair<long long, long long> c) {
  pair<long long, long long> p1{b.first - a.first, b.second - a.second};
  pair<long long, long long> p2{c.first - a.first, c.second - a.second};
  return cross(p1, p2) == 0;
}
const int mxn = 1000;
int n, k;
vector<pair<long long, long long>> v;
long double dp[mxn + 1][mxn + 1];
vector<long long> nones;
long long getOnes(long long a, long long b) {
  long long tot = 0;
  for (long long p = 1; p / 10LL <= 1e17; p *= 10) {
    if (a < p) {
      if (b < p) break;
      if (b >= p + p) {
        tot += p;
      } else {
        tot += b - p + 1LL;
        break;
      }
    } else {
      if (a >= p + p) continue;
      tot += min(b, p + p - 1LL) - a + 1LL;
    }
  }
  return tot;
}
void work() {
  cin >> n;
  v.resize(n);
  for (auto &e : v) cin >> e.first >> e.second;
  nones.resize(n);
  for (int i = 0; i < n; ++i) {
    nones[i] = getOnes(v[i].first, v[i].second);
  }
  cin >> k;
  dp[0][0] = 1.0 - (long double)nones[0] / (v[0].second - v[0].first + 1LL);
  dp[0][1] = (long double)nones[0] / (v[0].second - v[0].first + 1LL);
  for (int i = 1; i < n; ++i) {
    long double p_of_zero =
        1.0 - (long double)nones[i] / (v[i].second - v[i].first + 1LL);
    long double p_of_one =
        (long double)nones[i] / (v[i].second - v[i].first + 1LL);
    dp[i][0] = dp[i - 1][0] * p_of_zero;
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i - 1][j] * p_of_zero + dp[i - 1][j - 1] * p_of_one;
    }
  }
  int x = ceil(n * k / 100.0);
  if (x > n) {
    cout << "0\n";
    return;
  }
  long double ans = 0;
  for (int i = x; i <= n; ++i) ans += dp[n - 1][i];
  cout << setprecision(17) << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  work();
  return 0;
}
