#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long n;
  cin >> n;
  long long x[n], y[n];
  vector<pair<pair<long long, long long>, long long>> v;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    v.push_back({{x[i] / 1005, y[i]}, i});
  }
  sort(v.begin(), v.end());
  for (auto i : v) cout << i.second + 1 << ' ';
}
