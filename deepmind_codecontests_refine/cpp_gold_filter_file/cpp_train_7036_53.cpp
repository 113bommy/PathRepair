#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<double> num;
  long long avg = 0;
  for (long long i = 0; i < 250; i++) {
    long long tmp;
    cin >> tmp;
    num.push_back(tmp);
    avg += tmp;
  }
  avg /= 250;
  double variance = 0;
  for (auto x : num) {
    variance += pow(fabs(avg - x), 2);
  }
  variance /= 250;
  if (fabs(variance / avg) <= 1.5 && fabs(variance / avg) >= 0.5) {
    cout << "poisson\n";
  } else {
    cout << "uniform\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
