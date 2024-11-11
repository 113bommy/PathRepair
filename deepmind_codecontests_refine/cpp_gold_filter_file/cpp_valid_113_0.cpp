#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> heros(n);
  for (auto& x : heros) cin >> x;
  sort(heros.begin(), heros.end());
  long long sum = accumulate(heros.begin(), heros.end(), 0ll);
  int m;
  cin >> m;
  while (m--) {
    long long atk, dfns;
    cin >> atk >> dfns;
    int id = lower_bound(heros.begin(), heros.end(), atk) - heros.begin();
    long long ans = 2e18 + 5;
    if (id > 0) {
      ans = min(ans,
                atk - heros[id - 1] + max(0ll, dfns - (sum - heros[id - 1])));
    }
    if (id < n) {
      ans = min(ans, max(0ll, dfns - (sum - heros[id])));
    }
    cout << ans << endl;
  }
  return 0;
}
