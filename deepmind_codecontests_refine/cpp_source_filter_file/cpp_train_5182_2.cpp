#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> c(n), p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) cin >> c[i];
  long long ans = -1e18;
  for (int i = 0; i < n; ++i) {
    int j = i, cnt = 0;
    long long cur = 0;
    vector<long long> pr = {0};
    do {
      cur += c[p[j]];
      pr.push_back(cur);
      ans = max(ans, cur);
      j = p[j];
      ++cnt;
    } while (j != i and cnt < k);
    if (k / cnt) {
      for (int it = 0; it <= cnt; ++it) {
        ans = max(ans, (k / cnt - 1) * cur + pr[it]);
      }
    }
    for (int it = 0; it <= k % cnt; ++it) {
      if (it or (k / cnt)) {
        ans = max(ans, (k / cnt) * cur + pr[it]);
      }
    }
  }
  cout << ans;
  return 0;
}
