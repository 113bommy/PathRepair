#include <bits/stdc++.h>
using namespace std;
long double h, c, t;
vector<pair<double, int> > pot;
void bs() {
  long long lo = 0, hi = 1e9, mid;
  long long bestN = -1;
  long double bestDif = 1e9;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    long double tmp = ((mid + 1) * h + mid * c) / (2 * (mid + 1) - 1);
    long double error = abs(tmp - t);
    if (tmp > t)
      lo = mid + 1;
    else
      hi = mid - 1;
    if (error < bestDif) {
      pot.clear();
      bestN = mid;
      bestDif = error;
      pot.push_back({bestDif, (2 * (bestN + 1)) - 1});
    } else if (error == bestDif)
      pot.push_back({error, (2 * (mid + 1)) - 1});
  }
}
long long solve() {
  pot.clear();
  bs();
  double avg = (h + c) / 2;
  pot.push_back({abs(avg - t), 2});
  pot.push_back({abs(h - t), 1});
  sort(pot.begin(), pot.end());
  return pot[0].second;
}
int main() {
  int TC;
  cin >> TC;
  while (TC--) {
    cin >> h >> c >> t;
    long long ans = solve();
    cout << ans << "\n";
  }
}
