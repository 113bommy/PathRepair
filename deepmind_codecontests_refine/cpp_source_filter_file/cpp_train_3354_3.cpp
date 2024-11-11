#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int pwr(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * 1LL * a) % mod;
    a = (a * 1LL * a) % mod;
    b >>= 1;
  }
  return ans;
}
const int N = 3e5 + 5;
int a[N];
vector<int> pos[N];
int pr[N];
int n, m;
vector<int> tr[4 * N];
int lol[N];
void build(int nd, int s, int e) {
  for (int i = s; i <= e; i++) {
    tr[nd].push_back(pr[i]);
  }
  sort(tr[nd].begin(), tr[nd].end());
  if (s == e) return;
  int m = (s + e) >> 1;
  build(nd << 1, s, m);
  build(nd << 1 | 1, m + 1, e);
}
int query(int l, int r, int nd = 1, int s = 1, int e = m) {
  if (s > r || e < l) return 0;
  if (l <= s && e <= r) {
    return lower_bound(tr[nd].begin(), tr[nd].end(), l) - tr[nd].begin();
  }
  int m = (s + e) >> 1;
  return query(l, r, nd << 1, s, m) + query(l, r, nd << 1 | 1, m + 1, e);
}
int mini[N], maxi[N];
int bit[N];
bool vis[N];
void upd(int idx, int val) {
  while (idx < N) {
    bit[idx] += val;
    idx += idx & (-idx);
  }
}
int query(int idx) {
  int s = 0;
  while (idx > 0) {
    s += bit[idx];
    idx -= idx & (-idx);
  }
  return s;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!pos[i].empty()) {
      pr[pos[i][0]] = -1;
    }
    for (int j = 1; j < pos[i].size(); j++) {
      pr[pos[i][j]] = pos[i][j - 1];
    }
  }
  build(1, 1, m);
  for (int i = 1; i <= m; i++) {
    if (!vis[a[i]]) {
      vis[a[i]] = 1;
      upd(a[i], 1);
    }
    if (i == pos[a[i]][0]) {
      maxi[a[i]] = max(maxi[a[i]], query(n) - query(a[i]) + a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (pos[i].empty()) {
      mini[i] = i;
      maxi[i] = query(n) - query(i) + i;
    } else {
      mini[i] = 1;
      for (int j = 0; j + 1 < pos[i].size(); j++) {
        maxi[i] = max(maxi[i], query(pos[i][j] + 1, pos[i][j + 1] - 1) + 1);
      }
      maxi[i] = max(maxi[i], query(pos[i].back() + 1, n) + 1);
    }
    cout << mini[i] << " " << maxi[i] << '\n';
  }
  return 0;
}
