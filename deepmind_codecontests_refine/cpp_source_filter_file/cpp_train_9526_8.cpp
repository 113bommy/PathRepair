#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp& x) {
  x = 0;
  char tmp;
  bool key = 0;
  for (tmp = getchar(); !isdigit(tmp); tmp = getchar()) key = (tmp == '-');
  for (; isdigit(tmp); tmp = getchar()) x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
const int N = 100010;
int ch[N][26], fail[N], cnt = 1, rch[N][26];
int add(char* str, int len) {
  int ret = 1;
  for (int i = 1; i <= len; ++i) {
    if (!ch[ret][str[i] - 'a']) ch[ret][str[i] - 'a'] = ++cnt;
    ret = ch[ret][str[i] - 'a'];
  }
  return ret;
}
void build() {
  queue<int> q;
  for (int i = (1); i <= (cnt); ++i)
    for (int j = (0); j <= (25); ++j) rch[i][j] = ch[i][j];
  fail[1] = 1;
  for (int i = (0); i <= (25); ++i) {
    if (rch[1][i]) {
      fail[rch[1][i]] = 1;
      q.push(rch[1][i]);
    } else
      rch[1][i] = 1;
  }
  for (int pos; !q.empty(); q.pop()) {
    pos = q.front();
    for (int i = (0); i <= (25); ++i) {
      if (!rch[pos][i])
        rch[pos][i] = rch[fail[pos]][i];
      else {
        fail[rch[pos][i]] = rch[fail[pos]][i];
        q.push(rch[pos][i]);
      }
    }
  }
}
struct edge {
  int la, b;
} con[N];
int tot, first[N];
void add_edge(int from, int to) {
  con[++tot] = (edge){first[from], to};
  first[from] = tot;
}
int dcnt, dfn[N], sz[N], rec[N];
void dfs(int pos) {
  rec[dfn[pos] = ++dcnt] = pos;
  sz[pos] = 1;
  for (int i = first[pos]; i; i = con[i].la) {
    dfs(con[i].b);
    sz[pos] += sz[con[i].b];
  }
}
int tdfn[N], tsz[N], tdcnt;
void sdf(int pos) {
  tdfn[pos] = ++tdcnt;
  tsz[pos] = 1;
  for (int i = (0); i <= (25); ++i)
    if (ch[pos][i]) {
      sdf(ch[pos][i]);
      tsz[pos] += tsz[ch[pos][i]];
    }
}
int n, q, pla[N];
char str[N];
long long ans[N];
struct data {
  data(int v = 0, int id = 0, int sgn = 0) : v(v), id(id), sgn(sgn) {}
  int v, id, sgn;
};
vector<data> vec[N];
const int B = 300;
int mB, val[N / B + 10][N], tmp[N], tag[N / B + 10];
int sum[N / B + 10], cur[N];
void add(int p, int v) {
  cur[p] += v;
  sum[(p - 1) / B + 1] += v;
}
int ask(int p) {
  int P = (p - 1) / B + 1;
  int ret = 0;
  for (int i = ((P - 1) * B + 1); i <= (p); ++i) ret += cur[i];
  for (int i = (1); i <= (P - 1); ++i) ret += sum[i];
  return ret;
}
void fsd(int pos) {
  for (int i = (0); i <= (25); ++i)
    if (ch[pos][i]) {
      tmp[ch[pos][i]] += tmp[pos];
      fsd(ch[pos][i]);
    }
}
void prework() {
  mB = (cnt - 1) / B + 1;
  for (int i = (1); i <= (mB); ++i) {
    int l = (i - 1) * B + 1, r = min(n, i * B);
    for (int j = (1); j <= (cnt); ++j) tmp[j] = 0;
    for (int j = (l); j <= (r); ++j) ++tmp[rec[j]];
    fsd(1);
    for (int j = (1); j <= (n); ++j) val[i][j] = tmp[pla[j]];
  }
}
void doit(int i) {
  int p = rec[i];
  add(tdfn[p], 1);
  add(tdfn[p] + tsz[p], -1);
}
void modify(int l, int r) {
  int L = (l - 1) / B + 1, R = (r - 1) / B + 1;
  if (L == R) {
    for (int i = (l); i <= (r); ++i) doit(i);
  } else {
    for (int i = (l); i <= (L * B); ++i) doit(i);
    for (int i = ((R - 1) * B + 1); i <= (r); ++i) doit(i);
    for (int i = (L + 1); i <= (R - 1); ++i) ++tag[i];
  }
}
long long query(int v) {
  long long ret = ask(tdfn[pla[v]]);
  for (int i = (1); i <= (mB); ++i) ret += 1ll * tag[i] * val[i][v];
  return ret;
}
int main() {
  read(n), read(q);
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", str + 1);
    int l = strlen(str + 1);
    pla[i] = add(str, l);
  }
  build();
  for (int i = (2); i <= (cnt); ++i) add_edge(fail[i], i);
  dfs(1);
  sdf(1);
  prework();
  for (int i = (1); i <= (q); ++i) {
    int l, r, k;
    read(l), read(r), read(k);
    vec[l - 1].push_back(data(k, i, -1));
    vec[r].push_back(data(k, i, 1));
  }
  for (int i = (1); i <= (n); ++i) {
    modify(dfn[pla[i]], dfn[pla[i]] + sz[pla[i]] - 1);
    for (int j = (0); j <= ((int)vec[i].size() - 1); ++j) {
      ans[vec[i][j].id] += vec[i][j].sgn * query(vec[i][j].v);
    }
  }
  for (int i = (1); i <= (q); ++i) printf("%lld\n", ans[i]);
  return 0;
}
