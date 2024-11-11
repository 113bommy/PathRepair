#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-' && t != EOF; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  if (t == EOF) return false;
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
  return true;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int maxn = 200111;
vector<int> g[maxn];
int n, m;
bool use[maxn];
int fa[maxn], dfn[maxn], edfn[maxn], timer, cnt[maxn];
vector<int> getp(int u, int v) {
  bool rev = 0;
  if (dfn[u] < dfn[v]) {
    rev = 1;
    swap(u, v);
  }
  vector<int> ret;
  while (u != v) {
    ret.push_back(u);
    u = fa[u];
  }
  ret.push_back(u);
  if (rev) reverse(ret.begin(), ret.end());
  return ret;
}
void find_path(int piv1) {
  pair<int, int> e1 = make_pair(0, 0), e2 = make_pair(0, 0);
  for (int x = 1; x <= n; x++)
    if (dfn[x] >= dfn[piv1] && dfn[x] <= edfn[piv1]) {
      for (auto v : g[x])
        if (dfn[v] < dfn[piv1] && (x != piv1 || v != fa[piv1])) {
          if (!e1.first)
            e1 = make_pair(x, v);
          else
            e2 = make_pair(x, v);
        }
    }
  if (dfn[e1.second] > dfn[e2.second]) swap(e1, e2);
  int piv2 = e1.second;
  vector<int> v1, v2, v3, tmp;
  v1 = getp(piv1, piv2);
  v2 = getp(piv1, e1.first);
  v2.push_back(piv2);
  v3 = getp(piv1, e2.first);
  tmp = getp(e2.second, piv2);
  for (auto v : tmp) v3.push_back(v);
  puts("YES");
  printf("%d ", (int)v1.size());
  for (int i = 0; i < (int)v1.size(); i++)
    printf("%d%c", v1[i], i == (int)v1.size() - 1 ? '\n' : ' ');
  printf("%d ", (int)v2.size());
  for (int i = 0; i < (int)v2.size(); i++)
    printf("%d%c", v2[i], i == (int)v2.size() - 1 ? '\n' : ' ');
  printf("%d ", (int)v3.size());
  for (int i = 0; i < (int)v3.size(); i++)
    printf("%d%c", v3[i], i == (int)v3.size() - 1 ? '\n' : ' ');
  exit(0);
}
void dfs(int x, int f = 0) {
  fa[x] = f;
  dfn[x] = ++timer;
  use[x] = 1;
  for (auto v : g[x]) {
    if (!use[v]) {
      dfs(v, x);
      cnt[x] += cnt[v];
    } else if (v != f && dfn[v] < dfn[x]) {
      cnt[x]++;
      cnt[v]--;
    }
  }
  edfn[x] = timer;
  if (cnt[x] > 1) find_path(x);
}
int main() {
  (get_int(n) && get_int(m));
  for (int i = 1, u, v; i <= m; i++) {
    (get_int(u) && get_int(v));
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!use[i]) dfs(i);
  puts("NO");
  return 0;
}
