#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int MAXN = 1e5 + 5;
const int MAXM = 2e6 + 5;
const int MOD = 1e9 + 7;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
long long pw(long long a, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void inc(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
void dec(long long &a, long long b) {
  a -= b;
  if (a < 0) a += MOD;
}
int mul(int a, int b) {
  long long c = 1ll * a * b;
  return c - c / MOD * MOD;
}
int n, m, rt, a[MAXN], L[MAXN], R[MAXN];
vector<int> G[MAXN];
bool cmp(int x, int y) { return a[x] < a[y]; }
void dfs(int u) {
  if (!((int)(G[u]).size())) {
    L[u] = R[u] = a[u];
    return;
  }
  dfs(G[u][0]);
  L[u] = L[G[u][0]];
  dfs(G[u][1]);
  R[u] = R[G[u][1]];
}
pair<int, int> q[MAXN];
double s[MAXN], c[MAXN], ans[MAXN];
void upd(int l, int r, int v) {
  if (l > r) return;
  s[l] += v;
  s[r + 1] -= v;
  c[l] += 1;
  c[r + 1] -= 1;
}
void dfs2(int u, int l, int r) {
  if (l > r || !((int)(G[u]).size())) return;
  int mid = upper_bound(q + 1 + l, q + 1 + r, make_pair(a[u], 0)) - q - 1;
  upd(l, mid, L[G[u][1]]);
  upd(mid + 1, r, R[G[u][0]]);
  dfs2(G[u][0], l, mid);
  dfs2(G[u][1], mid + 1, r);
}
int main() {
  scanf("%d", &n);
  int x;
  for (int i = 1; i < n + 1; i++) {
    scanf("%d%d", &x, &a[i]);
    if (x == -1)
      rt = i;
    else
      G[x].push_back(i);
  }
  for (int i = 1; i < n + 1; i++) sort((G[i]).begin(), (G[i]).end(), cmp);
  dfs(rt);
  scanf("%d", &m);
  for (int i = 1; i < m + 1; i++) {
    scanf("%d", &x);
    q[i] = make_pair(x, i);
  }
  sort(q + 1, q + 1 + m);
  dfs2(rt, 1, m);
  for (int i = 1; i < m + 1; i++) {
    s[i] += s[i - 1];
    c[i] += c[i - 1];
    ans[q[i].second] = s[i] / c[i];
  }
  for (int i = 1; i < m + 1; i++) printf("%.12f\n", ans[i]);
}
