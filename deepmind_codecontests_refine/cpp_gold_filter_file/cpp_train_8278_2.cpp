#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> per_one(n);
  for (int i = 0; i < n; ++i) {
    cin >> per_one[i];
  }
  vector<long long> has(n);
  vector<pair<long long, pair<long long, long>>> already(n);
  for (int i = 0; i < n; ++i) {
    cin >> has[i];
    already[i].first = has[i] / per_one[i];
    already[i].second.first = per_one[i] - (has[i] % per_one[i]);
    already[i].second.second = per_one[i];
  }
  sort(already.begin(), already.end());
  long long ans = already[0].first, p = 0, pp = 0;
  long long need;
  for (int i = 0; i < n && k > 0; ++i) {
    need = already[i].second.first;
    p += already[i].second.second;
    while (i < n - 1 && already[i + 1].first == already[i].first) {
      ++i;
      need += already[i].second.first;
      p += already[i].second.second;
    }
    if (need + pp <= k) {
      k -= (need + pp);
      ++ans;
    } else {
      k = 0;
    }
    if (i + 1 < n) {
      if ((already[i + 1].first - ans) * p <= k) {
        k -= (already[i + 1].first - ans) * p;
        ans = already[i + 1].first;
      } else {
        ans += (k / p);
        k = 0;
      }
    }
    pp = p;
  }
  if (k > 0) ans += (k / p);
  cout << ans << '\n';
  return 0;
}
