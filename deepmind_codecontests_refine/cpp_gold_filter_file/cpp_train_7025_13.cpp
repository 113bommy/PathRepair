#include <bits/stdc++.h>
using namespace std;
const int NR = 1e6 + 10;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int n, m;
string a[NR];
int tot;
int en[NR];
int val[NR];
int tr[NR][30];
int fail[NR];
void ins(string& s, int x) {
  int len = s.length(), now = 0;
  for (int i = 0; i < len; i++) {
    int c = s[i] - 'a' + 1;
    if (!tr[now][c]) tr[now][c] = ++tot;
    now = tr[now][c];
  }
  en[x] = now;
}
int to[NR], nxt[NR], h[NR], tot_ = 1;
void add(int x, int y) {
  to[tot_] = y, nxt[tot_] = h[x];
  h[x] = tot_++;
}
int head = 1, tail = 1;
int q[NR];
void build() {
  for (int i = 1; i <= 26; i++)
    if (tr[0][i]) q[tail++] = tr[0][i];
  while (head < tail) {
    int x = q[head++];
    add(fail[x], x);
    for (int i = 1; i <= 26; i++) {
      if (tr[x][i])
        q[tail++] = tr[x][i], fail[tr[x][i]] = tr[fail[x]][i];
      else
        tr[x][i] = tr[fail[x]][i];
    }
  }
}
int cnt, id[NR], fid[NR], siz[NR];
void dfs(int x) {
  id[x] = ++cnt;
  fid[cnt] = x;
  siz[x] = 1;
  for (int i = h[x]; i; i = nxt[i]) dfs(to[i]), siz[x] += siz[to[i]];
}
struct BIT {
  int c[NR];
  void clear() { memset(c, 0, sizeof(c)); }
  int lowbit(int x) { return x & -x; }
  void add(int x, int val) {
    while (x <= tot + 1) c[x] += val, x += lowbit(x);
  }
  int query(int x) {
    int res = 0;
    while (x) res += c[x], x -= lowbit(x);
    return res;
  }
} T;
void insert(string& s) {
  int len = s.length(), now = 0;
  for (int i = 0; i < len; i++) {
    int c = s[i] - 'a' + 1;
    now = tr[now][c], T.add(id[now], 1);
  }
}
int all;
struct Query {
  int id, t, k, op;
  bool operator<(const Query& A) const { return t < A.t; }
} Q[NR];
int ans[NR];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) cin >> a[i], ins(a[i], i);
  build();
  dfs(0);
  for (int i = 1; i <= m; i++) {
    int l = read(), r = read(), k = read();
    all++;
    Q[all].t = l - 1, Q[all].id = i, Q[all].k = k, Q[all].op = -1;
    all++;
    Q[all].t = r, Q[all].id = i, Q[all].k = k, Q[all].op = 1;
  }
  sort(Q + 1, Q + all + 1);
  int now = 0;
  T.clear();
  for (int i = 1; i <= all; i++) {
    while (Q[i].t > now) now++, insert(a[now]);
    ans[Q[i].id] += Q[i].op * (T.query(id[en[Q[i].k]] + siz[en[Q[i].k]] - 1) -
                               T.query(id[en[Q[i].k]] - 1));
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
