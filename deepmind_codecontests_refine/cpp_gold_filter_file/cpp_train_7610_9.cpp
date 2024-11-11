#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
const int N = 500005, mod = 1000000009, B = 233, M = 1000005, K = 20;
int ans, n, dp[N], in[M], out[M], f[M][K];
int pos[N], len[M], tot = 1, last = 1, ti, go[M][26], pre[M];
int tree[1 << 21 | 3];
vector<int> v[M];
char ch[N];
int ask(int l, int r, int i, int j, int nod) {
  if (l == i && r == j) return tree[nod];
  int mid = (l + r) >> 1;
  if (j <= mid)
    return ask(l, mid, i, j, nod << 1);
  else if (i > mid)
    return ask(mid + 1, r, i, j, nod << 1 | 1);
  else
    return max(ask(l, mid, i, mid, nod << 1),
               ask(mid + 1, r, mid + 1, j, nod << 1 | 1));
}
void insert(int l, int r, int pos, int de, int nod) {
  if (l == r) {
    tree[nod] = max(tree[nod], de);
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    insert(l, mid, pos, de, nod << 1);
  else
    insert(mid + 1, r, pos, de, nod << 1 | 1);
  tree[nod] = max(tree[nod << 1], tree[nod << 1 | 1]);
}
inline int get(int r, int L) {
  int t = pos[r];
  for (int i = K - 1; i >= 0; i--)
    if (f[t][i] && len[f[t][i]] >= L) t = f[t][i];
  return t;
}
bool check(int x, int y) {
  int l = x - y + 2, r = x, t = get(r, y - 1);
  if (ask(1, tot, in[t], out[t], 1) >= y - 1) return 1;
  l = x - y + 1;
  r = x - 1;
  t = get(r, y - 1);
  if (ask(1, tot, in[t], out[t], 1) >= y - 1) return 1;
  return 0;
}
void insert(int x) { insert(1, tot, in[pos[x]], dp[x], 1); }
void add(int c) {
  int np = ++tot, p = last;
  len[np] = len[p] + 1;
  last = np;
  for (; p && !go[p][c]; p = pre[p]) go[p][c] = np;
  if (!p)
    pre[np] = 1;
  else {
    int q = go[p][c];
    if (len[p] + 1 == len[q])
      pre[np] = q;
    else {
      int nq = ++tot;
      memcpy(go[nq], go[q], sizeof(go[q]));
      len[nq] = len[p] + 1;
      pre[nq] = pre[q];
      pre[np] = pre[q] = nq;
      while (go[p][c] == q) {
        go[p][c] = nq;
        p = pre[p];
      }
    }
  }
}
void dfs(int p) {
  in[p] = ++ti;
  for (auto i : v[p]) dfs(i);
  out[p] = ti;
}
int main() {
  n = read();
  scanf("%s", ch + 1);
  reverse(&ch[1], &ch[n + 1]);
  for (int i = 1; i <= n; i++) {
    add(ch[i] - 'a');
    pos[i] = last;
  }
  for (int i = 2; i <= tot; i++) v[f[i][0] = pre[i]].push_back(i);
  for (int i = 1; i < K; i++)
    for (int j = 1; j <= tot; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  dfs(1);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    while (dp[i] && !check(i, dp[i])) {
      dp[i]--;
      insert(i - dp[i]);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
