#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5, MAXM = 2e5 + 5, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
int n, a[MAXN], b[MAXN], p, ss = 0;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  for (int i = (1); i <= (n); i++) cin >> b[i];
  int ans = INF, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i]) ss++;
    if (b[i] == 1) {
      p = i;
      int j = i;
      for (; j + 1 <= n && b[j + 1] == b[j] + 1; j++)
        ;
      if (j == n) cnt = j - i + 1;
    }
  }
  if (cnt) {
    bool flag = true;
    for (int i = 1; i < p; i++) {
      if (!b[i]) continue;
      if (b[i] - cnt <= i) {
        flag = false;
        break;
      }
    }
    if (flag) ans = n - cnt;
  }
  if (ss == 0)
    ans = n;
  else {
    int res = 0;
    for (int j = p; j <= n; j++) {
      if (b[j]) res = max(res, j - b[j] + 1);
    }
    ans = min(ans, res + n);
  }
  cout << ans << '\n';
  return 0;
}
