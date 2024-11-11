#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, a[N], ans[N], mxm, color, cnt[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    mxm = 0;
    fill(cnt, cnt + N, 0);
    for (int j = i; j < n; j++) {
      cnt[a[j]]++;
      if (cnt[a[j]] > mxm) {
        color = a[j];
        mxm = cnt[a[j]];
      } else if (cnt[a[j]] == mxm) {
        if (a[j] < color) {
          color = a[j];
        }
      }
      ans[color]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? "\n" : " ");
  }
}
