#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  std::vector<long long> sa(n);
  std::vector<long long> sb(m);
  for (long long i = 0; i < n; i++) cin >> sa[i];
  for (long long i = 0; i < m; i++) cin >> sb[i];
  long long ans = 0;
  if (k >= n)
    cout << -1 << endl;
  else {
    for (long long x = 0; x <= k; x++) {
      long long starta = sa[x];
      long long enda = starta + ta;
      long long startb = lower_bound(sb.begin(), sb.end(), enda) - sb.begin();
      if (startb + (k - x) >= m) {
        cout << "-1" << endl;
        return 0;
      } else {
        long long endb = sb[startb + (k - x)] + tb;
        ans = max(endb, ans);
      }
    }
    cout << ans << endl;
  }
}
