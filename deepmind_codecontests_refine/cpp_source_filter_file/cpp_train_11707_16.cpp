#include <bits/stdc++.h>
using namespace std;
const int N = 255;
int n, sz[N], val[N], l[N], r[N], mid;
bool dp[N][2][3], vis[N][2][3];
inline bool c(int x, int y, int z) { return x == z || y == z ? z : !z; }
bool dfs(int pos, int w, int s) {
  if (val[pos] != -1)
    return val[pos] > mid;
  else if (sz[pos] == 1)
    return c(dfs(l[pos], 0, 0), dfs(r[pos], 0, 0), w ^ (s == 2));
  else if (vis[pos][w][s])
    return dp[pos][w][s];
  bool &ans = dp[pos][w][s];
  vis[pos][w][s] = 1;
  if (s) {
    ans = dfs(pos, !w, 0);
    if (sz[pos] & 1) {
      if (sz[l[pos]] & 1) {
        ans = c(ans,
                c(dfs(l[pos], w, 0),
                  dfs(r[pos], !w, (sz[l[pos]] == 1 && s == 1)) + 1, !w),
                w);
        ans = c(ans,
                c(dfs(r[pos], w, 0),
                  dfs(l[pos], !w, (sz[r[pos]] == 1 && s == 1)) + 1, !w),
                w);
      } else {
        if (sz[l[pos]])
          ans = c(ans,
                  c(dfs(l[pos], w, (s == 1 && !sz[r[pos]]) + 1),
                    dfs(r[pos], !w, 0), !w),
                  w);
        if (sz[r[pos]])
          ans = c(ans,
                  c(dfs(r[pos], w, (s == 1 && !sz[l[pos]]) + 1),
                    dfs(l[pos], !w, 0), !w),
                  w);
      }
    } else {
      ans = c(
          ans,
          c(dfs(l[pos], w, (s == 1 && !sz[r[pos]]) + 1), dfs(r[pos], w, 0), w),
          w);
    }
  } else {
    if (sz[pos] & 1) {
      if (sz[l[pos]] & 1)
        ans = c(dfs(l[pos], w, 1), dfs(r[pos], w, 1), w);
      else
        ans = c(dfs(l[pos], w, 0), dfs(r[pos], w, 0), w);
    } else {
      ans = c(c(dfs(l[pos], w, 0), dfs(r[pos], !w, 0), !w),
              c(dfs(r[pos], w, 1), dfs(l[pos], !w, 1), !w), w);
    }
  }
  return ans;
}
void dfs(int pos) {
  sz[pos] = 0;
  if (val[pos] != -1) return;
  dfs(l[pos]);
  dfs(r[pos]);
  sz[pos] = 1 + sz[l[pos]] + sz[r[pos]];
  if (sz[r[pos]] & 1) swap(l[pos], r[pos]);
}
void init(int n) {
  for (int i = 0; i < n; i++) {
    cin >> val[i];
    if (val[i] == -1)
      cin >> l[i] >> r[i];
    else
      l[i] = r[i] = -1;
  }
  dfs(0);
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    init(n);
    int l = 0, r = 1000;
    while (l < r) {
      mid = (l + r) >> 1;
      memset(vis, 0, sizeof(vis));
      if (dfs(0, 1, 0))
        l = mid + 1;
      else
        r = mid;
    }
    cerr << l << endl;
  }
  return 0;
}
