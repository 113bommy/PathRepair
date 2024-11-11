#include <bits/stdc++.h>
using namespace std;
int n, a[5005], cnt[5005], ans[5005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int l = 1; l <= n; l++) {
    int idx = 0;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int r = l; r <= n; r++) {
      cnt[a[r]]++;
      if (cnt[a[r]] > cnt[idx] || cnt[a[r]] == cnt[idx] && a[r] < idx)
        idx = a[r];
      ans[a[idx]]++;
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
