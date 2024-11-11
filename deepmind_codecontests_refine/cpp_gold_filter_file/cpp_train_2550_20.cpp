#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
const long long mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  long long k;
  int n;
  cin >> k >> n;
  int a[201][201];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x + 100][y + 100] = 1;
  }
  int dist[201][201], cnt[51], vis[201][201];
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  dist[100][100] = 0;
  set<pair<long long, pair<long long, long long> > > st;
  st.insert({0, {100, 100}});
  while (!st.empty()) {
    int x = st.begin()->second.first;
    int y = st.begin()->second.second;
    st.erase(*st.begin());
    if (vis[x][y]) continue;
    vis[x][y] = 1;
    for (int k = 0; k < 8; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 || nx > 200 || ny < 0 || ny > 200 || a[nx][ny]) continue;
      if (dist[nx][ny] > dist[x][y] + 1) {
        dist[nx][ny] = dist[x][y] + 1;
        st.insert({dist[nx][ny], {nx, ny}});
      }
    }
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i <= 200; i++) {
    for (int j = 0; j <= 200; j++) {
      if (dist[i][j] <= 50) {
        cnt[dist[i][j]]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 50 && i <= k; i++) {
    ans += cnt[i];
  }
  if (k >= 50) {
    long long m = (k - 50 + 1) % mod;
    long long d = cnt[50] - cnt[49];
    long long a = cnt[50];
    long long tmp = m * ((2 * a + (m - 1) * d) % mod) % mod;
    tmp *= (mod + 1) / 2;
    tmp %= mod;
    ans += tmp;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
