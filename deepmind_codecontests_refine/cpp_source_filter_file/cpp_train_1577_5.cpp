#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, s, e;
int c[maxn], d[maxn];
int dis(int s, int e) { return s < e ? e - s : n - s + e; }
void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    d[i] = 0x3f3f3f3f;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s >> e;
    c[s]++;
    d[s] = min(d[s], dis(s, e));
  }
}
void slove() {
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
      if (c[j] == 0) continue;
      int cal = (c[j] - 1) * n + dis(i, j) + d[j];
      ans = max(ans, cal);
    }
    cout << ans << ' ';
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  slove();
  return 0;
}
