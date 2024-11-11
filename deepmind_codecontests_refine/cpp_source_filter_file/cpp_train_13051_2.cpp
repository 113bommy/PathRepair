#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000010;
const int inf = ~0u >> 2;
int l, r, p;
int cntp;
int pr[30];
int n;
int a[maxn], dp[maxn];
bool can[maxn];
void rp(int num, int i, int sum) {
  a[n++] = num;
  for (; i < cntp; i++) {
    if ((long long)num * pr[i] > r) break;
    rp(num * pr[i], i, sum + 1);
  }
}
void init() {
  for (int i = 2; i <= p; i++) {
    bool f = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        f = false;
      }
    }
    if (f) pr[cntp++] = i;
  }
  rp(1, 0, 0);
}
void solve() {
  fill(dp, dp + n, inf);
  dp[0] = 0;
  sort(a, a + n);
  for (int i = 1; i <= p; i++) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      while (k < n && a[k] < a[j] * i) k++;
      if (k == n) break;
      if ((long long)a[k] == a[j] * i) {
        if (dp[k] > dp[j] + 1) dp[k] = dp[j] + 1;
        if (dp[k] <= p) can[k] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= l && can[i]) ans++;
  }
  cout << ans << endl;
}
int main() {
  cin >> l >> r >> p;
  init();
  solve();
  return 0;
}
