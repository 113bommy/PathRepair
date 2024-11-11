#include <bits/stdc++.h>
using namespace std;
const int maxk = 10;
const int maxn = 1000 + 5;
int k, n;
int ax[maxk], ay[maxk];
int mx[maxn], my[maxn];
bool flag;
bool inq[maxn];
bool vis[maxk];
vector<int> pos;
vector<int> r[maxk][maxn];
inline long long det(int x0, int y0, int x1, int y1) {
  return (long long)x0 * y1 - (long long)y0 * x1;
}
inline long long dot(int x0, int y0, int x1, int y1) {
  return (long long)x0 * x1 + (long long)y0 * y1;
}
inline long long norm(int x, int y) { return dot(x, y, x, y); }
inline bool check(int x0, int y0, int x1, int y1) {
  if (det(x0, y0, x1, y1)) return 0;
  if (dot(x0, y0, x1, y1) < 0) return 0;
  if (norm(x0, y0) < norm(x1, y1)) return 0;
  return 1;
}
void dfs(int step) {
  if (step == pos.size()) flag = 1;
  if (flag) return;
  int u = pos[step], rec = pos.size();
  for (int i = 1; i <= k; ++i)
    if (!vis[i]) {
      vis[i] = 1;
      for (int j = 0; j < r[i][u].size(); ++j) {
        int x = r[i][u][j];
        if (!inq[x]) {
          inq[x] = 1;
          pos.push_back(x);
          if (pos.size() > k) break;
        }
      }
      if (pos.size() <= k) {
        dfs(step + 1);
        if (flag) return;
      }
      while (pos.size() > rec) {
        int x = pos.back();
        pos.pop_back();
        inq[x] = 0;
      }
      vis[i] = 0;
    }
}
int sol() {
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        if (j != k)
          if (check(mx[j] - ax[i], my[j] - ay[i], mx[k] - ax[i], my[k] - ay[i]))
            r[i][j].push_back(k);
  int an = 0;
  for (int i = 1; i <= n; ++i) {
    flag = 0;
    pos.clear(), pos.push_back(i);
    memset(vis, 0, sizeof(vis));
    memset(inq, 0, sizeof(inq));
    dfs(0);
    if (flag) ++an;
  }
  return an;
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= k; ++i) scanf("%d%d", &ax[i], &ay[i]);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &mx[i], &my[i]);
  printf("%d\n", sol());
  return 0;
}
