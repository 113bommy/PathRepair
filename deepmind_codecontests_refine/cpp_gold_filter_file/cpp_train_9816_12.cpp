#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
long long s[maxn], fc[20];
int vis[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  s[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + i;
  fc[0] = 1;
  for (int i = 1; i <= 15; i++) fc[i] = fc[i - 1] * i;
  long long c = 0;
  while (m--) {
    int x;
    cin >> x;
    if (x == 1) {
      int l, r;
      cin >> l >> r;
      if (r <= n - 15) {
        cout << s[r] - s[l - 1] << endl;
        continue;
      }
      long long ans = 0;
      if (r >= 15 && l <= n - 15) ans = s[n - 15] - s[l - 1];
      int st = max(1, n - 14);
      for (int i = st; i <= n; i++) vis[i] = 0;
      long long cc = c;
      for (int i = st; i <= n; i++) {
        if (i > r) break;
        int move = cc / fc[n - i] + 1;
        int cnt = 0;
        for (int j = st; j <= n; j++) {
          if (vis[j] == 0) cnt++;
          if (move == cnt) {
            vis[j] = 1;
            if (i >= l) ans += j;
            break;
          }
        }
        cc %= fc[n - i];
      }
      cout << ans << endl;
    } else {
      cin >> x;
      c += x;
    }
  }
  return 0;
}
