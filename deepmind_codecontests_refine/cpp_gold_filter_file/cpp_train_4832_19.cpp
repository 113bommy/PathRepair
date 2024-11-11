#include <bits/stdc++.h>
using namespace std;
int p[2000006] = {0};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, g = 1000000007, x;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x, p[x]++;
  for (int i = 1; i < 2000006; i++) p[i] += p[i - 1];
  int ans = 1;
  for (int i = 2; i < 2000006; i++) {
    int tot = 0;
    for (int j = i; j + i < 2000006; j += i) {
      int nxt = j + min(i - 1, k);
      tot += p[nxt] - p[j - 1];
    }
    if (tot == n) {
      ans = i;
    }
  }
  cout << ans << "\n";
}
