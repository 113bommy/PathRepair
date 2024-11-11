#include <bits/stdc++.h>
using namespace std;
long long used[200001];
int main() {
  long long n;
  cin >> n;
  int a[n + 1];
  for (int k = 1; k <= n; k++) cin >> a[k];
  long long m;
  cin >> m;
  pair<long long, long long> cnt[m + 1];
  for (int k = 1; k <= m; k++) {
    int x;
    cin >> x;
    if (x == 1) {
      int y, z;
      cin >> y >> z;
      cnt[k].first = y;
      cnt[k].second = z;
    }
    if (x == 2) {
      int y;
      cin >> y;
      cnt[k].first = y;
      cnt[k].second = -1;
    }
  }
  long long mx = 1;
  long long ans[n + 1];
  for (int k = m; k > 0; k--) {
    if (cnt[k].second == -1) {
      mx = max(mx, cnt[k].first);
    }
    if (cnt[k].second != -1 && used[cnt[k].first] == 0) {
      ans[cnt[k].first] = max(mx, cnt[k].second);
      used[cnt[k].first] = 1;
    }
  }
  for (int k = 1; k <= n; k++) {
    if (used[k] == 0) {
      long long xx = a[k];
      cout << max(xx, mx) << ' ';
    } else
      cout << ans[k] << ' ';
  }
  return 0;
}
