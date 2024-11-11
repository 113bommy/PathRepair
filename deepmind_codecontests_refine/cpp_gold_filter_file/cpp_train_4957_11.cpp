#include <bits/stdc++.h>
using namespace std;
const int Nmax = 2e5 + 5;
int a[Nmax];
int t[Nmax];
int cnt[Nmax];
int n, k, ans, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  int cur = 0;
  for (int last = 1; last <= min(n, k - 1); last++) {
    if (t[last] <= k - 1) {
      cur++;
      int bound = last + (k - t[last]);
      if (bound <= n) cnt[bound]++;
    }
    cur -= cnt[last];
    ans = max(ans, cur);
  }
  cout << ans;
  return 0;
}
