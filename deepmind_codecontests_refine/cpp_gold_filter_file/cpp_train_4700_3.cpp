#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 7, M = 2e6;
const long long mod = 1e9 + 7;
inline int read() {
  int ret = 0;
  char ch = getchar();
  bool f = 1;
  for (; !isdigit(ch); ch = getchar()) f ^= !(ch ^ '-');
  for (; isdigit(ch); ch = getchar()) ret = (ret << 1) + (ret << 3) + ch - 48;
  return f ? ret : -ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b, long long mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
int head[N], NEXT[M], ver[M], tot;
void link(int u, int v) {
  ver[++tot] = v;
  NEXT[tot] = head[u];
  head[u] = tot;
}
int indeg[N], in[N], out[N], lazy[N], a[N];
int ant;
struct node {
  int l, r, mid;
  int val;
  int maxn;
} tree[N];
void dfs(int x) {
  in[x] = ++ant;
  for (int i = head[x]; i; i = NEXT[i]) {
    int y = ver[i];
    dfs(y);
  }
  out[x] = ant;
}
void build(int x, int l, int r) {
  tree[x].l = l;
  tree[x].r = r;
  lazy[x] = 0;
  if (l == r) {
    tree[x].maxn = 0;
    return;
  }
  int mi = tree[x].mid = l + r >> 1;
  build(x << 1, l, mi);
  build(x << 1 | 1, mi + 1, r);
  tree[x].maxn = max(tree[x << 1].maxn, tree[x << 1 | 1].maxn);
}
void down(int x) {
  if (lazy[x] != 0) {
    lazy[x << 1] += lazy[x];
    lazy[x << 1 | 1] += lazy[x];
    tree[x << 1].maxn += lazy[x];
    tree[x << 1 | 1].maxn += lazy[x];
    lazy[x] = 0;
  }
}
void change(int x, int l, int r, int num) {
  if (l > tree[x].r || r < tree[x].l) return;
  if (l <= tree[x].l && r >= tree[x].r) {
    tree[x].maxn += num;
    lazy[x] += num;
    return;
  } else {
    down(x);
    if (l <= tree[x].mid) change(x << 1, l, r, num);
    if (r > tree[x].mid) change(x << 1 | 1, l, r, num);
    tree[x].maxn = max(tree[x << 1].maxn, tree[x << 1 | 1].maxn);
  }
}
int ask(int x, int l, int r) { return tree[x].maxn; }
int main() {
  int n, k;
  int ant = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  stack<int> s;
  for (int i = 1; i <= n; i++) {
    if (s.empty())
      s.push(i);
    else {
      while (!s.empty() && a[s.top()] < a[i]) {
        link(i, s.top());
        indeg[s.top()]++;
        s.pop();
      }
      s.push(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (indeg[i]) continue;
    link(n + 1, i);
  }
  dfs(n + 1);
  build(1, in[n + 1], out[n + 1]);
  for (int i = 1; i <= n; i++) {
    if (i > k) {
      change(1, in[i - k], out[i - k], -1);
      change(1, in[i], out[i], 1);
      printf(" %d", ask(1, in[n + 1], out[n + 1]));
    } else {
      change(1, in[i], out[i], 1);
      if (i == k) printf("%d", ask(1, in[n + 1], out[n + 1]));
    }
  }
  puts("");
  return 0;
}
