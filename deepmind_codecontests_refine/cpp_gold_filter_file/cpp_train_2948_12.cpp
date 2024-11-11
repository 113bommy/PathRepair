#include <bits/stdc++.h>
using namespace std;
int sz[100010], mxd[100010], dep[100010], dis[100010], rt, rtsz, sum, n, L, R,
    ans = -1, ansU, ansV, U, V;
int pre[100010], tmp[100010], idpre[100010], idtmp[100010], q[100010];
const int INF = 1 << 30;
bool vis[100010];
vector<pair<int, int> > nxt[100010];
void getrt(int x, int fa) {
  int tmpsz = 0;
  sz[x] = 1;
  for (pair<int, int> v : nxt[x]) {
    if (vis[v.first] || v.first == fa) continue;
    getrt(v.first, x), sz[x] += sz[v.first];
    tmpsz = max(tmpsz, sz[v.first]);
  }
  tmpsz = max(tmpsz, sum - sz[x]);
  if (tmpsz < rtsz) rt = x, rtsz = tmpsz;
}
void getdp(int x, int fa, int d, int &y) {
  y = max(y, dep[x] = d);
  for (pair<int, int> v : nxt[x]) {
    if (vis[v.first] || v.first == fa) continue;
    getdp(v.first, x, d + 1, y);
  }
}
bool get_ans(int x, int fa, int dis, int s) {
  bool ret = dep[x] >= L && dep[x] <= R && dis >= 0;
  if (dis > tmp[dep[x]]) tmp[dep[x]] = dis, idtmp[dep[x]] = x;
  if (ret) return U = x, V = rt, true;
  for (pair<int, int> v : nxt[x]) {
    if (vis[v.first] || v.first == fa) continue;
    ret |= get_ans(v.first, x, dis + (v.second >= s ? 1 : -1), s);
    if (ret) return true;
  }
  return false;
}
bool check(int x, int s) {
  memset(pre, 0xcf, sizeof(int) * (mxd[nxt[x][nxt[x].size() - 1].first] + 1));
  for (int i = 0; i < nxt[x].size(); i++) {
    pair<int, int> v = nxt[x][i];
    if (vis[v.first]) continue;
    memset(tmp, 0xcf, sizeof(int) * (mxd[v.first] + 1));
    if (get_ans(v.first, x, v.second >= s ? 1 : -1, s)) return true;
    int l = 1, r = 0, tmpr = 0, lst = i ? nxt[x][i - 1].first : 0;
    for (int j = mxd[v.first]; j; j--) {
      while (tmpr < min(mxd[lst], R - j)) {
        tmpr++;
        while (l <= r && pre[q[r]] <= pre[tmpr]) r--;
        q[++r] = tmpr;
      }
      while (l <= r && q[l] + j < L) l++;
      if (l <= r && pre[q[l]] + tmp[j] >= 0)
        return U = idpre[q[l]], V = idtmp[j], true;
    }
    for (int j = 1; j <= mxd[v.first]; j++) {
      if (tmp[j] > pre[j]) pre[j] = tmp[j], idpre[j] = idtmp[j];
    }
  }
  return false;
}
void Divide_Conquer(int x) {
  rtsz = INF, getrt(x, 0);
  int tmprt = rt;
  vis[tmprt] = 1;
  for (pair<int, int> v : nxt[tmprt]) {
    if (vis[v.first]) continue;
    mxd[v.first] = 0, getdp(v.first, 0, 1, mxd[v.first]);
  }
  sort(nxt[tmprt].begin(), nxt[tmprt].end(),
       [](pair<int, int> x, pair<int, int> y) {
         return mxd[x.first] < mxd[y.first];
       });
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(tmprt, mid))
      l = mid + 1;
    else
      r = mid;
  }
  if (!check(tmprt, l)) check(tmprt, --l);
  if (l > ans) ans = l, ansU = U, ansV = V;
  for (pair<int, int> v : nxt[tmprt]) {
    if (vis[v.first]) continue;
    sum = sz[v.first], Divide_Conquer(v.first);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> L >> R;
  for (int i = 1, u, v, w; i <= n - 1; i++)
    cin >> u >> v >> w, nxt[u].push_back({v, w}), nxt[v].push_back({u, w});
  memset(pre, 0xcf, sizeof(pre));
  sum = n, Divide_Conquer(1);
  cout << ansU << " " << ansV << endl;
  return 0;
}
