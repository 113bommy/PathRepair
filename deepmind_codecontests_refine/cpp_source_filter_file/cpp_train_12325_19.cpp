#include <bits/stdc++.h>
using namespace std;
int g[1000005] = {};
int diff[1000005] = {};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      diff[abs(a[i] - a[j])]++;
    }
  }
  int start = max(0, n - k);
  for (int ans = start; ans < 1000005; ans++) {
    int dups = 0;
    for (int j = 0; j <= 1000005; j += ans) {
      dups += diff[j];
    }
    if (dups > k * (k + 1)) continue;
    memset(g, 0, sizeof(g));
    int isgood = 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (g[a[i] % ans] != 0) cur++;
      if (cur > k) {
        isgood = 0;
        break;
      }
      g[a[i] % ans]++;
    }
    if (isgood) {
      cout << ans << endl;
      break;
    }
  }
  return 0;
}
