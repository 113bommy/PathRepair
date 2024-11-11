#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 20, MAX2 = 20;
int n, H;
long long Pa1[MAX][MAX2];
int mins1[MAX][MAX2], maxs1[MAX][MAX2], sum1[MAX][MAX2];
long long T[MAX], co[MAX], L[MAX];
int head[MAX];
int nxt[MAX << 1];
int to[MAX << 1];
long long cost[MAX << 1];
int ent;
void addedge2(int u, int v, int c) {
  nxt[ent] = head[u], to[ent] = v, cost[ent] = c, head[u] = ent, ent++;
  nxt[ent] = head[v], to[ent] = u, cost[ent] = c, head[v] = ent, ent++;
}
void dfs(int v, int p, int level) {
  if (level > H) H = level;
  L[v] = level;
  for (int i = head[v]; ~i; i = nxt[i]) {
    int u = to[i];
    int c = cost[i];
    if (u != p) {
      T[u] = v;
      co[u] = c;
      dfs(u, v, level + 1);
    }
  }
}
void preprocessmm() {
  long long ma1, ma2, mi1, mi2;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; 1 << j <= n; j++) Pa1[i][j] = -1;
  }
  for (int i = 1; i <= n; i++) {
    maxs1[i][0] = T[i], mins1[i][0] = T[i], sum1[i][0] = T[i] == -1 ? 0 : co[i];
    Pa1[i][0] = T[i];
  }
  for (int j = 1; 1 << j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (Pa1[i][j - 1] != -1) {
        int i2 = Pa1[i][j - 1];
        ma1 = maxs1[i][j - 1], ma2 = maxs1[i2][j - 1];
        if (ma2 == -1)
          maxs1[i][j] = ma1;
        else
          maxs1[i][j] = co[ma1] < co[ma2] ? ma2 : ma1;
        mi1 = mins1[i][j - 1], mi2 = mins1[i2][j - 1];
        if (mi2 == -1)
          mins1[i][j] = mi1;
        else
          mins1[i][j] = co[mi1] < co[mi2] ? mi1 : mi2;
        sum1[i][j] = sum1[i][j - 1] + sum1[i2][j - 1];
        Pa1[i][j] = Pa1[Pa1[i][j - 1]][j - 1];
      } else
        mins1[i][j] = mins1[i][j - 1], maxs1[i][j] = maxs1[i][j - 1],
        sum1[i][j] = sum1[i][j - 1];
    }
  }
}
int lca1mm(int u, int v, long long &ma, long long &mi, long long &su) {
  int log, i;
  ma = mi = -1, su = 0;
  if (L[u] < L[v]) swap(u, v);
  if (!L[u]) return u;
  for (log = 0; 1 << log <= L[u]; log++)
    ;
  log--;
  for (i = log; i >= 0; i--) {
    if (L[u] - (1 << i) >= L[v]) {
      if (ma == -1)
        ma = maxs1[u][i];
      else if (co[ma] < co[maxs1[u][i]])
        ma = maxs1[u][i];
      if (mi == -1)
        mi = mins1[u][i];
      else if (co[mi] > co[mins1[u][i]])
        mi = mins1[u][i];
      su += sum1[u][i];
      u = Pa1[u][i];
    }
  }
  if (u == v) return u;
  for (i = log; i >= 0; i--) {
    if (Pa1[u][i] != -1 && Pa1[u][i] != Pa1[v][i]) {
      if (ma == -1)
        ma = maxs1[u][i];
      else if (co[ma] < co[maxs1[u][i]])
        ma = maxs1[u][i];
      if (co[ma] < co[maxs1[v][i]]) ma = maxs1[v][i];
      if (mi == -1)
        mi = mins1[u][i];
      else if (co[mi] > co[mins1[u][i]])
        mi = mins1[u][i];
      if (co[mi] > co[mins1[v][i]]) mi = mins1[v][i];
      su += sum1[u][i];
      su += sum1[v][i];
      u = Pa1[u][i], v = Pa1[v][i];
    }
  }
  if (ma == -1)
    ma = u;
  else if (co[ma] < co[u])
    ma = u;
  if (co[ma] < co[v]) ma = v;
  if (mi == -1)
    mi = u;
  else if (co[mi] > co[u])
    mi = u;
  if (co[mi] > co[v]) mi = v;
  su += co[u] + co[v];
  return T[u];
}
vector<int> seq, pos;
void dfs(int v, int pa) {
  seq.push_back(v);
  for (int i = head[v]; ~i; i = nxt[i]) {
    int u = to[i];
    if (u != pa) dfs(u, v);
  }
}
int main() {
  scanf("%d", &n);
  memset(head, -1, sizeof(head));
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addedge2(a, b, c);
  }
  dfs(1, -1, 0);
  preprocessmm();
  seq.reserve(n + 1);
  dfs(1, -1);
  pos.resize(n + 1), pos.shrink_to_fit();
  for (int i = 0; i < seq.size(); i++) {
    int v = seq[i];
    pos[v] = i;
  }
  int q;
  scanf("%d\n", &q);
  long long ans = 0;
  class cmp {
   public:
    cmp() {}
    bool operator()(int a, int b) const { return pos[a] < pos[b]; }
  };
  set<int, cmp> cur;
  long long mi, mx, sum;
  while (q--) {
    char c;
    scanf("%c", &c);
    int v;
    if (c == '+') {
      scanf("%d\n", &v);
      cur.insert(v);
      if (cur.size() > 1) {
        auto ite = cur.find(v);
        if (*ite == *cur.begin()) {
          int pre = *cur.rbegin(), nxt = *next(ite);
          if (pre != nxt) {
            lca1mm(pre, nxt, mx, mi, sum);
            ans -= sum;
          }
          lca1mm(pre, v, mx, mi, sum);
          ans += sum;
          lca1mm(v, nxt, mx, mi, sum);
          ans += sum;
        } else if (*ite == *cur.rbegin()) {
          int pre = *prev(ite), nxt = *cur.begin();
          if (pre != nxt) {
            lca1mm(pre, nxt, mx, mi, sum);
            ans -= sum;
          }
          lca1mm(pre, v, mx, mi, sum);
          ans += sum;
          lca1mm(v, nxt, mx, mi, sum);
          ans += sum;
        } else {
          int pre = *prev(ite), nxt = *next(ite);
          if (pre != nxt) {
            lca1mm(pre, nxt, mx, mi, sum);
            ans -= sum;
          }
          lca1mm(pre, v, mx, mi, sum);
          ans += sum;
          lca1mm(v, nxt, mx, mi, sum);
          ans += sum;
        }
      }
    } else if (c == '-') {
      scanf("%d\n", &v);
      if (cur.size() == 1)
        cur.erase(cur.find(v));
      else {
        auto ite = cur.find(v);
        if (*ite == *cur.begin()) {
          int pre = *cur.rbegin(), nxt = *next(ite);
          lca1mm(pre, v, mx, mi, sum);
          ans -= sum;
          lca1mm(v, nxt, mx, mi, sum);
          ans -= sum;
          if (pre != nxt) {
            lca1mm(pre, nxt, mx, mi, sum);
            ans += sum;
          }
        } else if (*ite == *cur.rbegin()) {
          int pre = *prev(ite), nxt = *cur.begin();
          lca1mm(pre, v, mx, mi, sum);
          ans -= sum;
          lca1mm(v, nxt, mx, mi, sum);
          ans -= sum;
          if (pre != nxt) {
            lca1mm(pre, nxt, mx, mi, sum);
            ans += sum;
          }
        } else {
          int pre = *prev(ite), nxt = *next(ite);
          lca1mm(pre, v, mx, mi, sum);
          ans -= sum;
          lca1mm(v, nxt, mx, mi, sum);
          ans -= sum;
          if (pre != nxt) {
            lca1mm(pre, nxt, mx, mi, sum);
            ans += sum;
          }
        }
        cur.erase(ite);
      }
    } else {
      getchar();
      printf("%lld\n", ans / 2);
    }
  }
  return 0;
}
