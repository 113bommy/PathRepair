#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, a[N], id[N], p[N], sum[N];
vector<int> e[N];
bool flag[N];
double ans;
bool cmp(int x, int y) { return a[x] > a[y]; }
int find_set(int x) {
  if (p[x] == x) return x;
  return p[x] = find_set(p[x]);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmp);
  for (int i = 0, x, y; i < m; ++i) {
    scanf("%d %d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) p[i] = i, sum[i] = 1;
  ans = 0;
  for (int it = 1; it <= n; ++it) {
    int x = id[it];
    flag[x] = true;
    for (int i = 0; i < e[x].size(); ++i) {
      int y = e[x][i];
      if (flag[y]) {
        int px = find_set(x), py = find_set(y);
        if (px == py) continue;
        ans += a[px] * 2 * (1.0 * sum[px] * sum[py]);
        sum[px] += sum[py];
        p[py] = px;
      }
    }
  }
  printf("%.6f\n", ans / (n * (n - 1)));
  return 0;
}
