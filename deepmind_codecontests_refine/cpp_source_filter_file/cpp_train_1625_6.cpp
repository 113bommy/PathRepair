#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
struct eT {
  void setd(int _u, int _v, int _l) { u = _u, v = _v, last = _l; }
  int u, v, last;
} edge[MAXN];
int n;
int ke, la[MAXN];
int pf[MAXN], st[MAXN];
bool vis[MAXN], ins[MAXN];
int stk[MAXN], top;
int kc, cn[MAXN], ci[MAXN];
vector<int> cyc[MAXN];
pair<int, int> dp[MAXN][2];
int md[MAXN];
pair<int, int> dp2[2][MAXN][2];
int md2[2][MAXN][2];
vector<pair<int, int> > ans;
void init();
void input();
void work();
void findcyc(int now);
void dfs(int now);
void getans(int now, int cb);
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
void operator+=(pair<int, int> &a, const pair<int, int> &b) { a = a + b; }
pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
void operator-=(pair<int, int> &a, const pair<int, int> &b) { a = a - b; }
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &pf[i], &st[i]);
}
void work() {
  ke = 0;
  memset(la, -1, sizeof(la));
  for (int i = 1; i <= n; ++i) {
    edge[ke].setd(pf[i], i, la[pf[i]]);
    la[pf[i]] = ke++;
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) findcyc(i);
  for (int i = 1; i <= n; ++i)
    if (cn[i]) dfs(i);
  int size, beg, en, nt, cb;
  pair<int, int> nans = make_pair(0, 0), stbs;
  for (int i = 1; i <= kc; ++i) {
    size = cyc[i].size() - 1;
    for (int j = 0; j < 2; ++j) {
      if (j && size == 2) {
        dp2[j][1][1] = dp[cyc[i][1]][0] + dp[cyc[i][2]][0] +
                       make_pair(1, st[cyc[i][1]] != st[cyc[i][2]]);
      } else {
        beg = j ? 2 : 1;
        en = j ? (size - 1) : size;
        dp2[j][beg][0] = dp[cyc[i][beg]][0],
        dp2[j][beg][1] = dp[cyc[i][beg]][1];
        md2[j][beg][1] = 0;
        if (j) {
          stbs = dp[cyc[i][1]][0] + dp[cyc[i][size]][0] +
                 make_pair(1, st[cyc[i][1]] != st[cyc[i][size]]);
          dp2[j][beg][0] += stbs, dp2[j][beg][1] += stbs;
        }
        for (int k = beg + 1; k <= en; ++k) {
          dp2[j][k][1] = dp2[j][k - 1][0] + dp[cyc[i][k]][0] +
                         make_pair(1, st[cyc[i][k]] != st[cyc[i][k - 1]]);
          md2[j][k][1] = -1;
          if (dp2[j][k - 1][0] > dp2[j][k - 1][1])
            dp2[j][k][0] = dp2[j][k - 1][0], md2[j][k][0] = 0;
          else
            dp2[j][k][0] = dp2[j][k - 1][1], md2[j][k][0] = 1;
          if (dp2[j][k][0] + dp[cyc[i][k]][1] > dp2[j][k][1]) {
            dp2[j][k][1] = dp2[j][k][0] + dp[cyc[i][k]][1];
            md2[j][k][1] = md2[j][k][0];
          }
          dp2[j][k][0] += dp[cyc[i][k]][0];
        }
      }
    }
    if ((((dp2[0][size][0]) > (dp2[0][size][1])) ? (dp2[0][size][0])
                                                 : (dp2[0][size][1])) >
        (((dp2[1][size - 1][0]) > (dp2[1][size - 1][1]))
             ? (dp2[1][size - 1][0])
             : (dp2[1][size - 1][1])))
      nt = 0;
    else
      nt = 1;
    beg = nt ? 2 : 1;
    en = nt ? (size - 1) : size;
    if (dp2[nt][en][0] > dp2[nt][en][1])
      cb = 0;
    else
      cb = 1;
    nans += dp2[nt][en][cb];
    for (int j = en; j >= beg; --j) {
      if (cb) {
        if (md2[nt][j][cb] == -1)
          ans.push_back(make_pair(cyc[i][j], cyc[i][j - 1])),
              getans(cyc[i][j], 0), cb = 0;
        else
          getans(cyc[i][j], 1), cb = md2[nt][j][cb];
      } else {
        getans(cyc[i][j], 0), cb = md2[nt][j][cb];
      }
    }
    if (nt)
      getans(cyc[i][1], 0), getans(cyc[i][size], 0),
          ans.push_back(make_pair(cyc[i][1], cyc[i][size]));
  }
  printf("%d %d\n", nans.first, nans.second);
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
}
void findcyc(int now) {
  if (ins[now]) {
    ++kc;
    stk[top] = -1;
    int ti = 0;
    cyc[kc].push_back(0);
    while (stk[top] ^ now) {
      --top;
      ins[stk[top]] = false;
      cn[stk[top]] = kc, ci[stk[top]] = ++ti;
      cyc[kc].push_back(stk[top]);
    }
  }
  if (vis[now]) return;
  vis[now] = ins[now] = true;
  stk[top++] = now;
  findcyc(pf[now]);
  if (ins[now]) {
    --top;
    ins[now] = false;
  }
}
void dfs(int now) {
  pair<int, int> ans = make_pair(0, 0), maxi = make_pair(-INF, -INF), cur;
  int v, mp = -1;
  for (int i = la[now]; ~i; i = edge[i].last) {
    v = edge[i].v;
    if (!cn[v]) {
      dfs(v);
      ans += dp[v][1];
      cur = dp[v][0] - dp[v][1] + make_pair(1, st[now] != st[v]);
      if (cur > maxi) maxi = cur, mp = v;
    }
  }
  dp[now][0] = ans, dp[now][1] = ans + maxi;
  md[now] = mp;
  if (dp[now][0] > dp[now][1]) dp[now][1] = dp[now][0], mp = -1;
}
void getans(int now, int cb) {
  if (cb && (~md[now])) {
    getans(md[now], 0);
    ans.push_back(make_pair(now, md[now]));
  }
  int v;
  for (int i = la[now]; ~i; i = edge[i].last) {
    v = edge[i].v;
    if (!cn[v] && (!cb || (v ^ md[now]))) getans(v, 1);
  }
}
