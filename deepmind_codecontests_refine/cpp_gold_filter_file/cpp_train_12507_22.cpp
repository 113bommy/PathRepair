#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  vector<pair<long long, long long> > mas;
  cin >> n;
  mas.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> mas[i].first >> mas[i].second;
  }
  cin >> k;
  for (long long i = 0; i < n; i++) {
    if (mas[i].first <= k && k <= mas[i].second) {
      cout << n - i;
      return 0;
    }
  }
  cout << n;
  return 0;
}
