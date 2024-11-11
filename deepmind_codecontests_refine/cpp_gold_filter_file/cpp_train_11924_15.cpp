#include <bits/stdc++.h>
using namespace std;
int mx = -1, ans;
int cnt[1110111], a[1110111];
int d[1110111];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= m) cnt[a[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    if (cnt[i])
      for (int j = i; j <= m; j += i) d[j] += cnt[i];
  }
  for (int i = 1; i <= m; i++) {
    if (mx < d[i]) {
      mx = d[i];
      ans = i;
    }
  }
  cout << ans << " " << mx << endl;
  for (int i = 1; i <= n; i++)
    if (ans % a[i] == 0) cout << i << " ";
  return 0;
}
