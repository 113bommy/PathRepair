#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[105];
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int ans = 0;
    int idx = 1;
    int c[100] = {0};
    int ls = a[1];
    for (int i = 1; i <= 2 * k; i++) {
      if (ls == a[i]) {
        c[idx]++;
      } else {
        c[++idx]++;
        ls = a[i];
      }
    }
    int mx = 0;
    for (int i = 1; i <= idx; i++) mx = max(mx, c[i]);
    if (mx <= k)
      ans = 0;
    else {
      ans = 2 * k - (2 * k - mx) * 2;
      ans /= 2;
    }
    for (int i = 2 * k + 1; i <= n; i++) {
      ans += a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
