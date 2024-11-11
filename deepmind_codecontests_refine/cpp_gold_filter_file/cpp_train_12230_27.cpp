#include <bits/stdc++.h>
using namespace std;
const int MN = 1000111;
int n, m, maxLeft[MN], minRight[MN], a[MN], b[MN], lg[MN], maxChild[MN];
int ke[2][MN];
bool can;
int nn[22][MN], ln[22][MN];
void init() {
  for (int i = 1, t = 0; i < MN; i *= 2, ++t) lg[i] = t;
  for (int i = (2), _b = (MN - 1); i <= _b; i++)
    if (!lg[i]) lg[i] = lg[i - 1];
  for (int i = (1), _b = (n); i <= _b; i++) {
    nn[0][i] = a[i];
    ln[0][i] = b[i];
  }
  for (int t = (1), _b = (20); t <= _b; t++) {
    for (int i = (1), _b = (n - (1 << t) + 1); i <= _b; i++) {
      nn[t][i] = min(nn[t - 1][i], nn[t - 1][i + (1 << (t - 1))]);
      ln[t][i] = max(ln[t - 1][i], ln[t - 1][i + (1 << (t - 1))]);
    }
  }
}
int getMin(int l, int r) {
  if (l > r) return n + 1;
  int g = lg[r - l + 1];
  return min(nn[g][l], nn[g][r - (1 << g) + 1]);
}
int getMax(int l, int r) {
  if (l > r) return -1;
  int g = lg[r - l + 1];
  return max(ln[g][l], ln[g][r - (1 << g) + 1]);
}
void solve(int i, int l, int r) {
  if (l > r) return;
  if (getMin(l, r) < l || getMax(l, r) > r) {
    can = false;
    return;
  }
  if (maxLeft[i] == -1) {
    ke[0][i] = 0;
    ke[1][i] = l;
    solve(i + 1, i + 2, r);
  } else if (minRight[i] == n + 1) {
    ke[0][i] = l;
    ke[1][i] = 0;
    solve(i + 1, i + 2, r);
  } else {
    if (maxLeft[i] >= minRight[i]) {
      can = false;
      return;
    }
    int res = -1;
    int left = maxLeft[i], right = minRight[i] - 1;
    left = right = maxChild[maxLeft[i]];
    for (int mid = (left), _b = (min(minRight[i] - 1, right + n)); mid <= _b;
         mid++) {
      if (getMax(l, mid) <= mid && getMin(mid + 1, r) >= mid + 1) {
        res = mid;
      }
    }
    if (res == -1) {
      can = false;
      return;
    }
    ke[0][i] = i + 1;
    ke[1][i] = res + 1;
    solve(i + 1, i + 2, res);
    solve(res + 1, res + 2, r);
  }
}
void dfs(int u) {
  if (ke[0][u]) dfs(ke[0][u]);
  cout << u << ' ';
  if (ke[1][u]) dfs(ke[1][u]);
}
int it[MN * 8];
int it_get(int i, int l, int r, int u, int v) {
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return it[i];
  int mid = (l + r) >> 1;
  return max(it_get(((i) << 1), l, mid, u, v),
             it_get((((i) << 1) + 1), mid + 1, r, u, v));
}
void it_update(int i, int l, int r, int u, int val) {
  if (u < l || r < u) return;
  if (l == r) {
    it[i] = max(it[i], val);
    return;
  }
  int mid = (l + r) >> 1;
  it_update(((i) << 1), l, mid, u, val);
  it_update((((i) << 1) + 1), mid + 1, r, u, val);
  it[i] = max(it[((i) << 1)], it[(((i) << 1) + 1)]);
}
int main() {
  ios ::sync_with_stdio(false);
  cout << (fixed) << setprecision(9);
  while (cin >> n >> m) {
    memset(ke, 0, sizeof ke);
    for (int i = (1), _b = (n); i <= _b; i++) {
      maxLeft[i] = -1;
      minRight[i] = n + 1;
      maxChild[i] = i;
      a[i] = b[i] = i;
    }
    can = true;
    for (int i = (1), _b = (m); i <= _b; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      if (u >= v) can = false;
      if (s[0] == 'L') {
        maxLeft[u] = max(maxLeft[u], v);
      } else {
        minRight[u] = min(minRight[u], v);
      }
      a[u] = min(a[u], v);
      b[u] = max(b[u], v);
      maxChild[u] = max(maxChild[u], v);
    }
    memset(it, 0, sizeof it);
    for (int i = (n), _b = (1); i >= _b; i--) {
      int u = maxChild[i];
      it_update(1, 1, n, i, maxChild[i]);
      maxChild[i] = max(maxChild[u], it_get(1, 1, n, i, u));
      it_update(1, 1, n, i, maxChild[i]);
    }
    if (can) init();
    if (can) solve(1, 2, n);
    if (!can) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    dfs(1);
    cout << endl;
  }
  return 0;
}
