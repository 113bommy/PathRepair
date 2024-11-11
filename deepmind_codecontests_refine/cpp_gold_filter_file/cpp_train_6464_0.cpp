#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
inline int read() {
  int res = 0, fl = 1;
  char r = getchar();
  for (; !isdigit(r); r = getchar())
    if (r == '-') fl = -1;
  for (; isdigit(r); r = getchar()) res = (res << 3) + (res << 1) + r - 48;
  return res * fl;
}
const int Maxn = 2e5 + 10;
vector<pair<int, int> > g[Maxn];
long double val[Maxn];
int siz[Maxn];
void dfs(int now, int pa) {
  siz[now] = 1;
  for (int i = g[now].size() - 1; i >= 0; --i) {
    int nxt = g[now][i].first;
    if (pa == nxt) continue;
    val[nxt] += g[now][i].second;
    dfs(nxt, now);
    val[now] += val[nxt];
    siz[now] += siz[nxt];
  }
}
long long Time, t[Maxn];
bool cmp(pair<int, int> A, pair<int, int> B) {
  return val[A.first] > val[B.first];
}
void Dfs(int now, int pa) {
  for (int i = g[now].size() - 1; i >= 0; --i) {
    int nxt = g[now][i].first;
    if (nxt == pa) continue;
    val[nxt] = 10000.00 * val[nxt] / siz[nxt];
  }
  sort(g[now].begin(), g[now].end(), cmp);
  t[now] = Time;
  for (int i = g[now].size() - 1; i >= 0; --i) {
    int nxt = g[now][i].first;
    if (pa == nxt) continue;
    Time += g[now][i].second;
    Dfs(nxt, now);
    Time += g[now][i].second;
  }
}
int main() {
  int n = read();
  for (int i = 1; i < n; ++i) {
    int x = read(), y = read(), z = read();
    g[x].push_back(make_pair(y, z));
    g[y].push_back(make_pair(x, z));
  }
  dfs(1, 0);
  Dfs(1, 0);
  long double ans = 0;
  for (int i = 1; i <= n; ++i) ans += t[i];
  printf("%.6Lf\n", 1.00 * ans / (n - 1));
  return 0;
}
