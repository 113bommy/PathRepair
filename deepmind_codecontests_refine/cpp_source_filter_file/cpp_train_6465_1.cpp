#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, s, minn, maxx = -1, ans = 0, sum = 0, d, a[100005], b[100005],
                         cnt[100005], pos, pos2 = -1, dp1[100005], dp2[100005],
                         dp3[100005], vis[100005], vis2[100005], vis3[100005],
                         pos3 = -1;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  a[0] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    d = 1;
    for (int j = 1; j <= n; j++) {
      if (b[j] != b[j + i] && j + i <= n) {
        d = 0;
        break;
      }
    }
    if (d) {
      b[ans] = i;
      ans++;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < ans; i++) {
    cout << b[i] << " ";
  }
}
