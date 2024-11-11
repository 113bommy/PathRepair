#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
double PI = 4 * atan(1);
long long ans = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<pair<int, int> > posi;
  for (long long b = 1; b <= n; ++b) {
    if (m >= b * b) {
      posi.push_back(make_pair(-2 * b + 1, -1));
      ans += 2 * (b * b - b);
    } else {
      int k = ceil(sqrt(b * b - m));
      posi.push_back(make_pair(-b + k, -1));
      posi.push_back(make_pair(-2 * b + 1, -b - k));
      ans += 2 * (m - (b - k));
    }
  }
  sort(posi.begin(), posi.end());
  for (int i = 0; i < posi.size(); i++) {
    int low = posi[i].first, high = posi[i].second;
    while (i < posi.size() && posi[i + 1].first <= high)
      high = max(high, posi[++i].second);
    ans += (high - low + 1);
  }
  cout << ans << "\n";
}
