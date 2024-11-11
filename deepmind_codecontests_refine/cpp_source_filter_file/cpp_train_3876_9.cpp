#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline long long squ(T x) {
  return (long long)x * x;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T read() {
  T sum = 0, fg = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fg = -1;
  for (; isdigit(c); c = getchar()) sum = (sum << 3) + (sum << 1) + (c ^ 0x30);
  return fg * sum;
}
const int maxn = 300 + 10;
const int maxm = 2e6 + 10;
const int maxv = 2e6 + 10;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
struct opt {
  int x, y, t;
  opt() {}
  opt(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};
vector<opt> G[maxv], D[maxv];
int n, m, q, C, id[maxn][maxn], a[maxn][maxn], ans[maxm];
bitset<maxn> vis[maxn];
namespace DSU {
const int maxn = ::maxn * ::maxn;
int fa[maxn];
inline void init(int N) {
  for (int i = 1; i <= N; i++) fa[i] = i;
}
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return 0;
  fa[x] = y;
  return 1;
}
}  // namespace DSU
int main() {
  n = read<int>(), m = read<int>(), q = read<int>();
  for (int i = 1; i <= q; i++) {
    int x = read<int>(), y = read<int>(), v = read<int>();
    opt now(x, y, i);
    D[a[x][y]].push_back(now);
    G[v].push_back(now), a[x][y] = C = v;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) D[a[i][j]].push_back(opt(i, j, q + 1));
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) id[i][j] = ++cnt;
  ans[0] = 1;
  for (int i = 0; i <= C; i++) {
    DSU::init(n * m);
    for (auto tt : G[i]) {
      vis[tt.x][tt.y] = 1, ++ans[tt.t];
      for (int k = 0; k < 4; k++) {
        int tx = tt.x + dx[k], ty = tt.y + dy[k];
        if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if (vis[tx][ty]) {
          if (DSU::merge(id[tt.x][tt.y], id[tx][ty])) --ans[tt.t];
        }
      }
    }
    for (auto tt : G[i]) vis[tt.x][tt.y] = 0;
    DSU::init(n * m), reverse(D[i].begin(), D[i].end());
    for (auto tt : D[i]) {
      vis[tt.x][tt.y] = 1, --ans[tt.t];
      for (int k = 0; k < 4; k++) {
        int tx = tt.x + dx[k], ty = tt.y + dy[k];
        if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if (vis[tx][ty]) {
          if (DSU::merge(id[tt.x][tt.y], id[tx][ty])) ++ans[tt.t];
        }
      }
    }
    for (auto tt : D[i]) vis[tt.x][tt.y] = 0;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i] += ans[i - 1]);
  return 0;
}
