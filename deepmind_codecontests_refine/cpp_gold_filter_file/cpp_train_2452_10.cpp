#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
int n, m;
vector<pair<int, int> > g[1011], t[3011];
long long w[30111];
int lca1[30111], lca2[30111], vx[30111], vy[30111], S, T;
bool vis[1011], te[30011];
int ban, tag[1011], mxv;
int lv[1011], p[11][1011];
void init_tree(int x) {
  vis[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    if (!vis[g[x][i].first]) {
      t[x].push_back(make_pair(g[x][i].first, g[x][i].second));
      t[g[x][i].first].push_back(make_pair(x, g[x][i].second));
      p[0][g[x][i].first] = x;
      lv[g[x][i].first] = lv[x] + 1;
      te[g[x][i].second] = 1;
      init_tree(g[x][i].first);
    }
  }
}
void initp(int x, int pre = -1) {
  if (pre == -1) p[0][x] = -1, lv[x] = 1;
  for (int i = 0; i < t[x].size(); i++) {
    if (t[x][i].first != pre) {
      p[0][t[x][i].first] = x;
      lv[t[x][i].first] = lv[x] + 1;
      initp(t[x][i].first, x);
    }
  }
}
void set_visit(int x, int pre = -1) {
  vis[x] = 1;
  for (int i = 0; i < t[x].size(); i++) {
    if (t[x][i].first != pre && t[x][i].second != ban) {
      set_visit(t[x][i].first, x);
    }
  }
}
int getlca(int x, int y) {
  if (lv[x] < lv[y]) swap(x, y);
  for (int i = 10; i >= 0; i--) {
    if (p[i][x] != -1 && lv[p[i][x]] >= lv[y]) {
      x = p[i][x];
    }
  }
  if (x == y) return x;
  for (int i = 10; i >= 0; i--) {
    if (p[i][x] != p[i][y]) {
      x = p[i][x];
      y = p[i][y];
    }
  }
  return p[0][x];
}
void sumup(int x, int pre = -1) {
  for (int i = 0; i < t[x].size(); i++) {
    if (t[x][i].first != pre && t[x][i].second != ban) {
      sumup(t[x][i].first, x);
      tag[x] += tag[t[x][i].first];
    }
  }
}
pair<long long, int> dfs(int x, int pre = -1) {
  pair<long long, int> ret = make_pair(1ll << 60, -1);
  if (mxv == 1) {
    for (int i = 0; i < g[x].size(); i++) {
      if (!te[g[x][i].second] && vis[g[x][i].first] != vis[x]) {
        ret = min(ret, make_pair(w[g[x][i].second], g[x][i].second));
      }
    }
  }
  for (int i = 0; i < t[x].size(); i++) {
    if (t[x][i].first != pre && t[x][i].second != ban) {
      if (tag[t[x][i].first] == mxv) {
        ret = min(ret, make_pair(w[t[x][i].second], t[x][i].second));
      }
      ret = min(ret, dfs(t[x][i].first, x));
    }
  }
  return ret;
}
int main() {
  n = getnum(), m = getnum();
  S = getnum(), T = getnum();
  for (int i = 1; i <= m; i++) {
    int x, y, ww;
    x = getnum(), y = getnum(), ww = getnum();
    g[x].push_back(make_pair(y, i));
    g[y].push_back(make_pair(x, i));
    w[i] = ww;
    vx[i] = x;
    vy[i] = y;
  }
  init_tree(S);
  if (!vis[T]) {
    cout << 0 << endl << 0 << endl;
    return 0;
  }
  initp(T);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[i - 1][j] == -1)
        p[i][j] = -1;
      else
        p[i][j] = p[i - 1][p[i - 1][j]];
    }
  }
  for (int i = 1; i <= m; i++) {
    lca2[i] = getlca(vx[i], vy[i]);
  }
  initp(S);
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[i - 1][j] == -1)
        p[i][j] = -1;
      else
        p[i][j] = p[i - 1][p[i - 1][j]];
    }
  }
  for (int i = 1; i <= m; i++) {
    lca1[i] = getlca(vx[i], vy[i]);
  }
  long long ans = 1ll << 60;
  int id1, id2;
  for (int i = 1; i <= m; i++) {
    if (!te[i]) continue;
    ban = i;
    memset(vis, 0, sizeof(vis));
    set_visit(S);
    if (vis[T]) continue;
    memset(tag, 0, sizeof(tag));
    mxv = 0;
    for (int j = 1; j <= m; j++) {
      if (te[j]) continue;
      if (vis[vx[j]] != vis[vy[j]]) {
        tag[vx[j]]++;
        tag[vy[j]]++;
        mxv++;
      } else {
        tag[vx[j]]--;
        tag[vy[j]]--;
        if (vis[vx[j]])
          tag[lca1[j]] += 2;
        else
          tag[lca2[j]] += 2;
      }
    }
    if (mxv == 0) {
      if (w[i] < ans) {
        ans = w[i];
        id1 = i;
        id2 = -1;
      }
    }
    sumup(S);
    sumup(T);
    pair<long long, int> bestans = min(dfs(S), dfs(T));
    if (bestans.second != -1) {
      if (w[i] + w[bestans.second] < ans) {
        ans = w[i] + w[bestans.second];
        id1 = i;
        id2 = bestans.second;
      }
    }
  }
  if (ans == (1ll << 60)) {
    puts("-1");
  } else {
    cout << ans << endl;
    if (id2 == -1) {
      cout << 1 << endl << id1 << endl;
    } else {
      cout << 2 << endl << id1 << " " << id2 << endl;
    }
  }
  return 0;
}
