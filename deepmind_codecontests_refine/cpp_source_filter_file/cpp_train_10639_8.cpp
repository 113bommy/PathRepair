#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 2e6 + 5;
int n, m, dp[maxn];
struct node {
  int l, r;
} a[maxn];
bool cmp(node a, node b) {
  if (a.l == b.l) return a.r > b.r;
  return a.l < b.l;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed << setprecision(9);
  cin >> n >> m;
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x - y, x + y};
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    for (int R = m; R > 0; R--) {
      int num = max(R - a[i].r, 0);
      int L = max(0, a[i].l - num);
      dp[R] = min(dp[R], dp[L - 1] + num);
      dp[R] = min(dp[R], dp[R + 1]);
    }
  }
  cout << dp[m] << endl;
  return 0;
}
