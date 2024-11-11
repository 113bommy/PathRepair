#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
int dp[MAXN][20];
int a[MAXN];
void RMQinit(int n) {
  for (int i = 1; i <= n; i++) {
    dp[i][0] = a[i];
  }
  int m = int(log((double)n) / log(2.0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
  }
}
int Querymax(int l, int r) {
  int k = int(log(double(r - l + 1)) / log(2.0));
  return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}
long long ans[MAXN];
void add(int l, int r, int v) {
  ans[l] += v;
  ans[r + 1] -= v;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, w;
  cin >> n >> w;
  memset(ans, 0, sizeof(ans));
  for (int tt = 0; tt < n; tt++) {
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    RMQinit(m);
    if (m * 2 <= w) {
      for (int i = 1; i <= m; i++) {
        int vh = max(0, Querymax(1, i));
        add(i, i, vh);
        int vt = max(0, Querymax(m - i + 1, m));
        add(w - i + 1, w - i + 1, vt);
      }
      int v = max(0, Querymax(1, m));
      add(m + 1, w - m, v);
    } else {
      for (int i = 1; i <= w; i++) {
        int v = Querymax(max(m - w + i, 1), min(i, m));
        if (i + m <= w || i > m) v = max(v, 0);
        add(i, i, v);
      }
    }
  }
  for (int i = 1; i <= w; i++) {
    ans[i] += ans[i - 1];
    cout << ans[i] << (i == w ? '\n' : ' ');
  }
}
