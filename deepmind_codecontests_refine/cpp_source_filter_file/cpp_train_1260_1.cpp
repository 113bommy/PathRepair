#include <bits/stdc++.h>
using namespace std;
namespace Input {
const int BUF = 65536;
char buf[BUF + 1];
char *head = buf, *tail = buf;
inline char inputchar() {
  if (head == tail) *(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
  return *head++;
}
inline void inputnum(int &ret) {
  char ch = inputchar();
  while (ch < '0' || ch > '9') ch = inputchar();
  for (ret = 0; ch >= '0' && ch <= '9'; ch = inputchar())
    ret = ret * 10 + ch - '0';
}
inline void inputstr(char *s) {
  char ch = inputchar();
  while (ch < 'a' || ch > 'z') ch = inputchar();
  for (; ch >= 'a' && ch <= 'z'; ch = inputchar()) *s++ = ch;
  *s = '\0';
}
}  // namespace Input
using Input::inputnum;
using Input::inputstr;
const int MAXN = 100005;
const int MAXH = 20;
const int MAXL = 100;
const int MOD = 1e9 + 7;
const int HSH = 14228239;
char s[MAXL + 5];
int n, u, v, Q;
char c;
vector<pair<int, char> > g[MAXN];
inline void addE(int u, int v, int c) { g[u].emplace_back(make_pair(v, c)); }
unsigned long long Hash[MAXN][MAXL + 5];
char cf[MAXN];
int f[MAXN][MAXH + 5], depth[MAXN];
void process(int u, int fa = 0, int v = 0) {
  if (fa != 0) {
    depth[u] = depth[fa] + 1;
    f[u][0] = fa;
    cf[u] = (char)('a' + v);
    for (int j = 1; j <= MAXH; j++) f[u][j] = f[f[u][j - 1]][j - 1];
    for (int j = 1; j <= depth[u] && j <= MAXL; j++)
      Hash[u][j] = (Hash[fa][j - 1] * HSH + v) % MOD;
  }
  for (auto x : g[u])
    if (x.first != fa) process(x.first, u, x.second - 'a');
}
unordered_map<unsigned long long, int> cnt;
vector<tuple<unsigned long long, int, int> > qry[MAXN];
int qry_len[MAXN];
unsigned long long pref[MAXL + 5], suf[MAXL + 5];
inline int up(int x, int d) {
  for (int j = MAXH; j >= 0; j--)
    if (d >= (1 << j)) x = f[x][j], d -= (1 << j);
  return x;
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int j = MAXH; j >= 0; j--)
    if (f[u][j] != 0 && depth[f[u][j]] >= depth[v]) u = f[u][j];
  if (u == v) return u;
  for (int j = MAXH; j >= 0; j--)
    if (f[u][j] != f[v][j]) u = f[u][j], v = f[v][j];
  return f[u][0];
}
int res[MAXN];
int kmp(const string &t) {
  static int next[MAXL + 5];
  int N = strlen(s + 1), M = t.size(), ret = 0;
  next[1] = 0;
  for (int i = 1; i < N; i++) {
    int j = next[i];
    while (j && s[j + 1] != s[i + 1]) j = next[j];
    if (s[j + 1] == s[i + 1]) ++j;
    next[i + 1] = j;
  }
  for (int i = 0, j = 0; i < M; i++) {
    while (j && t[i] != s[j + 1]) j = next[j];
    if (t[i] == s[j + 1]) ++j;
    if (j == N) ++ret, j = next[j];
  }
  return ret;
}
void dfs(int u, int len) {
  if (depth[u] >= len) ++cnt[Hash[u][len]];
  unsigned long long val;
  int sgn, id;
  for (auto x : qry[u]) {
    tie(val, sgn, id) = x;
    if (qry_len[id] == len) {
      res[id] += sgn * cnt[val];
    }
  }
  for (auto x : g[u])
    if (x.first != f[u][0]) dfs(x.first, len);
  if (depth[u] >= len) --cnt[Hash[u][len]];
}
int main() {
  inputnum(n);
  for (int i = 1; i < n; i++) {
    inputnum(u), inputnum(v), inputstr(s);
    addE(u, v, s[0]);
    addE(v, u, s[0]);
  }
  process(1);
  inputnum(Q);
  for (int i = 1; i <= Q; i++) {
    inputnum(u), inputnum(v), inputstr(s + 1);
    int N = strlen(s + 1);
    qry_len[i] = N, pref[0] = 0, suf[N + 1] = 0;
    for (int i = 1; i <= N; i++) pref[i] = (pref[i - 1] * HSH + s[i] - 'a');
    for (int i = N; i >= 1; i--) suf[i] = (suf[i + 1] * HSH + s[i] - 'a');
    int w = lca(u, v);
    qry[u].emplace_back(make_tuple(suf[1], 1, i)),
        qry[v].emplace_back(make_tuple(pref[N], 1, i));
    u = up(u, depth[u] - depth[w] - N + 1),
    v = up(v, depth[v] - depth[w] - N + 1);
    qry[u].emplace_back(make_tuple(suf[1], -1, i)),
        qry[v].emplace_back(make_tuple(pref[N], -1, i));
    string s1 = "", s2 = "";
    while (u != w) s1 += cf[u], u = f[u][0];
    while (v != w) s2 += cf[v], v = f[v][0];
    reverse(s2.begin(), s2.end());
    s1 += s2;
    res[i] += kmp(s1);
  }
  for (int i = 1; i <= MAXL; i++) {
    cnt.clear();
    dfs(1, i);
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", res[i]);
  return 0;
}
