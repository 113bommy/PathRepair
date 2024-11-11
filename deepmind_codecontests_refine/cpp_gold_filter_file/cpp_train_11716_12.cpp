#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
map<pair<long long int, long long int>, long long> m;
void solve() {
  cout << setprecision(15);
  long long a, aa, b, bb, t, tt;
  cin >> a >> aa >> b >> bb >> t >> tt;
  long long tes;
  cin >> tes;
  double sum = 0;
  vector<pair<double, pair<long long int, long long int>>> va;
  vector<pair<double, pair<long long int, long long int>>> vb;
  for (long long i = 0; i <= tes - 1; i++) {
    long long x, y;
    cin >> x >> y;
    double disa = sqrt((x - a) * (x - a) + (y - aa) * (y - aa)) -
                  sqrt((x - t) * (x - t) + (y - tt) * (y - tt));
    double disb = -sqrt((x - t) * (x - t) + (y - tt) * (y - tt)) +
                  sqrt((x - b) * (x - b) + (y - bb) * (y - bb));
    sum += 2 * sqrt((x - t) * (x - t) + (y - tt) * (y - tt));
    va.push_back({disa, {x, y}});
    vb.push_back({disb, {x, y}});
  }
  sort((va).begin(), (va).end());
  sort((vb).begin(), (vb).end());
  double ans = 0;
  if (tes == 1) {
    cout << sum + min(va[0].first, vb[0].first);
  } else {
    if (va[0].second.first != vb[0].second.first ||
        va[0].second.second != vb[0].second.second) {
      ans = sum + va[0].first + vb[0].first;
    } else {
      if (va[0].first + vb[1].first < va[1].first + vb[0].first) {
        ans = sum + va[0].first + vb[1].first;
      } else {
        ans = sum + vb[0].first + va[1].first;
      }
    }
    ans = min(ans, min(sum + va[0].first, sum + vb[0].first));
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
