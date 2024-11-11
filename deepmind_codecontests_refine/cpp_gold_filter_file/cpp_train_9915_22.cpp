#include <bits/stdc++.h>
using namespace std;
int T, k, n, a[200010], cnt[200010];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> k;
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 2; i <= n - 1; i++) {
      cnt[i] = cnt[i - 1];
      if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        cnt[i]++;
      }
    }
    int ans = 0, pos = 1;
    for (int i = 1; i <= n - 1; i++) {
      int L = i + 1, R = i + k - 1 - 1;
      if (R + 1 > n) break;
      int temp = cnt[R] - cnt[L - 1];
      if (temp > ans) {
        pos = i;
        ans = temp;
      }
    }
    cout << ans + 1 << " " << pos << endl;
  }
  return 0;
}
