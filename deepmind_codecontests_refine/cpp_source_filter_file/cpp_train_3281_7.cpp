#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
const int maxm = 1005;
const int maxl = 1000005;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-9;
inline int sgn(double a) { return a < -eps ? -1 : a > eps; }
int n, m;
int a[maxn];
int l[maxm];
int r[maxm];
int Xor[maxl];
int dp[maxn];
int ans[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i < maxl - 1; i++) {
    Xor[i] = Xor[i - 1] ^ i;
  }
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = i; j <= n; j++) {
      if (a[i] >= a[j])
        x = max(x, Xor[a[i]] ^ Xor[a[j] - 1]);
      else
        x = max(x, Xor[a[j]] ^ Xor[a[i] - 1]);
      dp[j] = x;
    }
    for (int j = 1; j <= m; j++) {
      if (l[j] <= i && r[j] >= i) ans[j] = max(ans[j], dp[r[j]]);
    }
  }
  for (int j = 1; j <= m; j++) cout << ans[j] << '\n';
  return 0;
}
