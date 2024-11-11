#include <bits/stdc++.h>
using namespace std;
const int N = 35005;
int n, m, nxt[N], a[N], last[N], l[N * 40], r[N * 40], t[N * 40], root[N],
    dp[51][N], opt[51][N], sz;
inline int vcopy(int v) {
  ++sz;
  l[sz] = l[v];
  r[sz] = r[v];
  t[sz] = t[v];
  return sz;
}
void update(int v, int l, int r, int pos, int val) {
  if (l == r) {
    t[v] += val;
    return;
  }
  int mid = (r + l) >> 1;
  if (pos <= mid) {
    ::l[v] = vcopy(::l[v]);
    update(::l[v], l, mid, pos, val);
  } else {
    ::r[v] = vcopy(::r[v]);
    update(::r[v], mid + 1, r, pos, val);
  }
  t[v] = t[::l[v]] + t[::r[v]];
}
int get(int v, int l, int r, int tl, int tr) {
  if (!v || l > r || tl > r || l > tr || tl > tr) {
    return 0;
  }
  if (tl <= l && r <= tr) {
    return t[v];
  }
  int mid = (r + l) >> 1;
  return get(::l[v], l, mid, tl, tr) + get(::r[v], mid + 1, r, tl, tr);
}
inline int get(int l, int r) {
  if (l > r) {
    return 0;
  }
  return get(root[r], 1, n, l, r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    root[i] = vcopy(root[i - 1]);
    if (last[a[i]]) {
      update(root[i], 1, n, last[a[i]], -1);
    }
    nxt[last[a[i]]] = i;
    last[a[i]] = i;
    update(root[i], 1, n, i, 1);
  }
  for (int i = 1; i <= n; i++) {
    if (!nxt[i]) {
      nxt[i] = n + 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    opt[i][n + 1] = n;
    for (int j = n; j >= 1; j--) {
      int x = get(opt[i - 1][j] + 1, j);
      for (int k = opt[i - 1][j]; k <= opt[i][j + 1]; k++) {
        if (dp[i - 1][k] + x > dp[i][j]) {
          dp[i][j] = dp[i - 1][k] + x;
          opt[i][j] = k;
        }
        if (nxt[k + 1] > j) {
          x--;
        }
      }
    }
  }
  cout << dp[m][n];
}
