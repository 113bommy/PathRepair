#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T, class V>
ostream &operator<<(ostream &s, pair<T, V> a) {
  s << a.first << ' ' << a.second;
  return s;
}
int f[101][200005];
int st[4 * 200005];
void init(long long int node, long long int ss, long long int sf, int i,
          int j) {
  if (ss == sf) {
    st[node] = f[j][ss] - f[i][ss];
    return;
  }
  long long int mid = (ss + sf) / 2;
  init(2 * node, ss, mid, i, j);
  init(2 * node + 1, mid + 1, sf, i, j);
  st[node] = max(st[2 * node], st[2 * node + 1]);
}
int query(int node, int ss, int sf, int val) {
  if (st[node] + val < 0) return -1;
  if (ss == sf) return ss;
  int mid = (ss + sf) / 2;
  if (st[2 * node] + val >= 0) return query(2 * node, ss, mid, val);
  return query(2 * node + 1, mid + 1, sf, val);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (int qq = 1; qq <= T; qq++) {
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (auto &x : v) cin >> x;
    for (int i = 0; i < n; i++) {
      f[v[i]][i + 1] = 1;
      for (int j = 1; j <= 100; j++) f[j][i + 1] += f[j][i];
    }
    int mx = 0;
    for (int i = 1; i <= 100; i++) {
      if (f[i][n] > f[mx][n]) mx = i;
    }
    if (f[mx][n] == n) {
      cout << -1 << endl;
      return 0;
    }
    int ans = 0;
    for (int j = 1; j <= 100; j++) {
      if (j == mx) continue;
      init(1, 0, n, j, mx);
      for (int i = 0; i < n; i++) {
        int r = query(1, 0, n, f[j][i + 1] - f[mx][i + 1]);
        if (r != -1) ans = max(ans, i - r + 1);
      }
    }
    cout << ans << endl;
  }
}
