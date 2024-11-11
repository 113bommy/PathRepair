#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {0, 1, 0, -1, 0, -1, -1, 1, 1};
const int dy[9] = {0, 0, -1, 0, 1, -1, 1, -1, 1};
const double pi = acos(-1.0);
const int N = 30 + 5;
struct point {
  long long x, y;
};
int n, du[N];
vector<int> G[N];
point ans[N];
void dfs(int v, int fa, long long x0, long long y0, long long len, int fx) {
  ans[v].x = x0, ans[v].y = y0;
  int l = G[v].size();
  int now = 0;
  for (int i = 0; i <= l - 1; i++) {
    if (G[v][i] == fa) continue;
    now++;
    int tnow = now + 2;
    if (tnow > 4) tnow -= 4;
    if (tnow == fx) now++;
    long long x1 = x0 + 1LL * dx[now] * len;
    long long y1 = y0 + 1LL * dy[now] * len;
    dfs(G[v][i], v, x1, y1, len >> 1, now);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d", &x), scanf("%d", &y);
    du[x]++, du[y]++;
    G[x].push_back(y), G[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (du[i] > 4) return puts("NO"), 0;
  puts("YES");
  dfs(1, 0, 0, 0, 1 << 30, 0);
  for (int i = 1; i <= n; i++) cout << ans[i].x << ' ' << ans[i].y << endl;
  return 0;
}
