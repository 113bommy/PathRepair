#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
const int MAX = 131072;
const int MAXS = MAX * 2 + 7;
const int MAXV = 15;
const int V = 10;
class stT {
 public:
  void upd(int p, int a[]) {
    p += MAX;
    for (int i = 0; i < V; ++i) data[p][i] += a[i];
    for (p >>= 1; p; p >>= 1)
      for (int i = 0; i < V; ++i)
        data[p][i] = data[p << 1][i] + data[p << 1 | 1][i];
  }
  void query(int l, int r, int a[]) {
    for (l += MAX - 1, r += MAX + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
      if (~l & 1)
        for (int i = 0; i < V; ++i) a[i] += data[l ^ 1][i];
      if (r & 1)
        for (int i = 0; i < V; ++i) a[i] += data[r ^ 1][i];
    }
  }

 private:
  int data[MAXS][MAXV];
} st1, st2, ast1, ast2;
int n, m;
bool vis[MAXN];
int ql[MAXN], qr[MAXN], qans[MAXN][MAXV];
vector<int> aql[MAXN], que[MAXN];
char s[MAXN];
int a[MAXN];
vector<int> aq[MAXN];
int stk[MAXN], top, smax[MAXN], sc[MAXN][MAXV];
int tv[MAXV];
void init();
void input();
void work();
void upd(int p, int val[]);
void query(int l, int r, int ans[], bool flag);
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &ql[i], &qr[i]);
}
void work() {
  for (int i = 1; i <= n; ++i)
    a[i] = (s[i] == '>') ? -1 : (s[i] == '<') ? -2 : (s[i] - '0');
  for (int i = 1; i <= m; ++i) aql[ql[i]].push_back(i), que[qr[i]].push_back(i);
  int tl;
  for (int i = 1; i <= n; ++i) {
    for (auto x : aql[i]) aq[stk[top]].push_back(x);
    if (a[i] == -1) {
      ++top;
      stk[top] = i;
      smax[top] = -1;
      for (int j = 0; j < V; ++j) sc[top][j] = 0;
    } else if (a[i] == -2) {
      while (top && (smax[top] & 1)) {
        tl = stk[top];
        for (auto x : aq[tl]) {
          if (!vis[x]) {
            vis[x] = true;
            query(ql[x], i, qans[x], false);
          }
        }
        upd(tl, sc[top]);
        --top;
      }
      for (auto x : aq[stk[top]]) {
        if (!vis[x]) {
          vis[x] = true;
          query(ql[x], i, qans[x], false);
        }
      }
      aq[stk[top]].clear();
      upd(stk[top], sc[top]);
      for (int j = 0; j < V; ++j) sc[top][j] = 0;
      smax[top] = -1;
    } else {
      smax[top] = (((smax[top]) > (a[i])) ? (smax[top]) : (a[i]));
      ++sc[top][a[i]];
      memset(tv, 0, sizeof(tv));
      tv[a[i]] = 1;
      st1.upd(i, tv);
      if (a[i]) tv[a[i] - 1] = 1;
      st2.upd(i, tv);
    }
    for (auto x : que[i]) {
      if (!vis[x]) {
        vis[x] = true;
        query(ql[x], i, qans[x], true);
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < V; ++j) printf("%d ", qans[i][j]);
    putchar('\n');
  }
}
void upd(int p, int val[]) {
  for (int i = 0; i < V; ++i) tv[i] = val[i];
  for (int i = V - 2; i >= 0; --i) tv[i] += tv[i + 1];
  for (int i = 0; i < V; ++i) tv[i] = tv[i + 1];
  tv[V - 1] = 0;
  ast1.upd(p, tv);
  for (int i = 0; i < V; ++i) tv[i] = tv[i + 1];
  tv[V - 1] = 0;
  ast2.upd(p, tv);
}
void query(int l, int r, int ans[], bool flag) {
  for (int i = 0; i < V; ++i) ans[i] = 0;
  if (flag) {
    st1.query(l, r, ans);
    ast1.query(l, r, ans);
  } else {
    st2.query(l, r, ans);
    ast2.query(l, r, ans);
  }
}
