#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int maxn = 1e5 + 10;
const int maxm = 2e5 + 10;
int h[maxn], e[maxm], ne[maxm], idx, w[maxm];
void add(int a, int b, int c) {
  w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int siz[maxn], dfn[maxn], dfs_clock;
void dfs(int x, int fa) {
  dfn[x] = ++dfs_clock;
  for (int i = h[x]; ~i; i = ne[i]) {
    int j = e[i];
    if (j == fa) continue;
    dfs(j, x);
  }
}
struct EDGE {
  int a, b;
  int id;
  int w;
  int seq;
  bool operator<(const EDGE &x) const {
    if (w != x.w) return w < x.w;
    return seq > x.seq;
  }
} edg[maxn];
int tot;
int f[maxn];
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
int cot[maxn];
int n;
void sol() {
  cin >> n;
  memset(h, -1, sizeof(h));
  for (int i = (1); i <= (n); i++) f[i] = i, siz[i] = 1;
  for (int i = (1); i <= (n - 1); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edg[tot++] = {a, b, i, c};
    add(a, b, c);
    add(b, a, c);
  }
  dfs(1, -1);
  for (int i = (0); i < (tot); i++) {
    int a = edg[i].a, b = edg[i].b;
    if (dfn[a] < dfn[b]) swap(a, b);
    edg[i].seq = dfn[a];
  }
  sort(edg, edg + tot);
  vector<pair<long long, long long> > ans;
  long long mx = 0;
  for (int i = (0); i < (tot); i++) {
    int w = edg[i].w;
    int j = i;
    while (j < tot && edg[j].w == w) {
      int a, b;
      a = edg[j].a;
      b = edg[j].b;
      if (dfn[a] < dfn[b]) swap(a, b);
      int A = find(a);
      cot[a] = siz[A];
      int B = find(b);
      if (A != B) {
        f[A] = B;
        siz[B] += siz[A];
      }
      j++;
    }
    for (int k = (i); k < (j); k++) {
      int a, b;
      a = edg[k].a;
      b = edg[k].b;
      if (dfn[a] < dfn[b]) swap(a, b);
      int A = find(a);
      int B = find(b);
      long long sum = (long long)2 * cot[a] * (siz[A] - cot[a]);
      ckmax(mx, sum);
      ans.push_back({sum, edg[k].id});
    }
    i = j - 1;
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  vector<int> v;
  for (int i = (0); i < ((int)ans.size()); i++) {
    if (ans[i].first == mx) v.push_back(ans[i].second);
  }
  sort(v.begin(), v.end());
  cout << mx << ' ' << (int)v.size() << '\n';
  for (auto x : v) cout << x << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sol();
  return 0;
}
