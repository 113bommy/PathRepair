#include <bits/stdc++.h>
using namespace std;
long long int INF = 1e18 + 5;
long long int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int h, n;
  cin >> h >> n;
  vector<long long int> pref(n);
  for (long long int i = 0; i < n; i++) {
    cin >> pref[i];
    pref[i] += (i ? pref[i - 1] : 0);
  }
  long long int ans = INF;
  if (pref[n - 1] < 0) {
    ans = min(ans, n * ((h + abs(pref[n - 1]) - 1) / abs(pref[n - 1])));
  }
  for (long long int i = 0; i < n; i++) {
    long long int now = -(h + pref[i]);
    if (now >= 0) {
      ans = min(ans, i);
      continue;
    }
    if (pref[n - 1] >= 0) {
      continue;
    }
    ans =
        min(ans,
            i + 1 + n * ((abs(now) + abs(pref[n - 1]) - 1) / abs(pref[n - 1])));
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << "\n";
}
