#include <bits/stdc++.h>
using namespace std;
const int N = 200004;
const long long MOD = 1000000007;
const int OO = INT_MAX;
inline long long mod(long long x) { return x % MOD; }
pair<long long, long long> taps[N];
long long acam[N];
long long acte[N];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, target;
  cin >> n >> target;
  taps[0] = make_pair(0, 0);
  for (long long i = 1; i <= n; i++) {
    cin >> taps[i].first;
  }
  for (long long i = 1; i <= n; i++) {
    cin >> taps[i].second;
  }
  sort(taps + 1, taps + n + 1, cmp);
  for (long long i = 1; i <= n; i++) {
    acam[i] = taps[i].first + acam[i - 1];
    acte[i] = taps[i].second * taps[i].first + acte[i - 1];
  }
  double hi, lo;
  lo = 0.0;
  hi = acam[n];
  int splits = 300;
  while (splits--) {
    double mid = (lo + hi) / 2.0;
    long long cit = upper_bound(acam, acam + n + 1, mid) - acam;
    double coldest;
    if (cit == n + 1)
      coldest = acte[n];
    else
      coldest =
          (acte[cit - 1] + taps[cit].second * (mid - acam[cit - 1])) / mid;
    long long hit = upper_bound(acam, acam + n + 1, acam[n] - mid) - acam;
    double hottest;
    if (mid < 0.5)
      hottest = taps[n].second;
    else
      hottest = ((acte[n] - acte[hit]) +
                 taps[hit].second * (mid - (acam[n] - acam[hit]))) /
                mid;
    double eps = 1e-12;
    if (coldest < target + eps && target < hottest + eps)
      lo = mid;
    else
      hi = mid;
  }
  cout << fixed << setprecision(12) << (lo + hi) / 2.0 << endl;
}
