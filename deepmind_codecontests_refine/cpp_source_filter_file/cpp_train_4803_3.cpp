#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(int x) {
  static const long long maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  long long len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (long long i = len - 1; i >= 0; --i) putchar(s[i]);
}
inline void read(long long &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(long long x) {
  static const long long maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  long long len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (long long i = len - 1; i >= 0; --i) putchar(s[i]);
}
const int MAXN = 1e5 + 100;
const int MAX_edge = 1e5 + 100;
int pre[MAX_edge], now[MAXN], son[MAX_edge], v[MAXN], tot;
int n, m;
void build(int a, int b, int c) {
  pre[++tot] = now[a];
  now[a] = tot;
  son[tot] = b;
  v[tot] = c;
}
int dfn[MAXN], low[MAXN], cnt;
bool IN[MAXN];
int d[MAXN], top;
int color[MAXN], color_tot;
bool flag = 0;
void dfs(int x, int lim) {
  dfn[x] = low[x] = ++cnt;
  d[++top] = x;
  IN[x] = 1;
  for (int p = now[x]; p; p = pre[p])
    if (v[p] > lim)
      if (dfn[son[p]] == 0) {
        dfs(son[p], lim);
        low[x] = min(low[x], low[son[p]]);
      } else if (IN[son[p]])
        low[x] = min(low[x], dfn[son[p]]);
  if (low[x] == dfn[x]) {
    ++color_tot;
    int tmp = 0;
    while (d[top] != x) {
      color[d[top]] = color_tot;
      tmp++;
      IN[d[top]] = 0;
      --top;
    }
    --top;
    IN[x] = 0;
    color[x] = color_tot;
    tmp++;
    if (tmp >= 2) flag = 0;
  }
}
bool check(int lim) {
  flag = 1;
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  cnt = 0;
  top = 0;
  memset(IN, 0, sizeof(IN));
  color_tot = 0;
  for (int i = 1; i <= n; i++)
    if (dfn[i] == 0) dfs(i, lim);
  return flag;
}
struct Edge {
  int a, b, c;
} E[MAX_edge];
int du[MAXN];
int val[MAXN];
queue<int> Q;
void get_val(int lim) {
  for (int i = 1; i <= m; i++)
    if (E[i].c > lim) du[E[i].b]++;
  for (int i = 1; i <= n; i++)
    if (du[i] == 0) Q.push(i);
  int C_id = n;
  while (Q.size()) {
    int x = Q.front();
    Q.pop();
    val[x] = C_id;
    C_id--;
    for (int p = now[x]; p; p = pre[p])
      if (v[p] > lim) {
        du[son[p]]--;
        if (du[son[p]] == 0) Q.push(son[p]);
      }
  }
}
vector<int> ans_v;
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    read(a);
    read(b);
    read(c);
    E[i].a = a;
    E[i].b = b;
    E[i].c = c;
    build(a, b, c);
  }
  int l = 1, r = 1e9;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  get_val(ans);
  int cnt = 0;
  for (int i = 1; i <= m; i++)
    if (val[E[i].a] < val[E[i].b]) ans_v.push_back(i);
  int tmp = ans_v.size();
  printf("%d %d\n", ans, tmp);
  if (ans_v.size()) printf("%d", ans_v[0]);
  for (int i = 1; i < ans_v.size(); i++) printf(" %d", ans_v[i]);
  puts("");
  return 0;
}
