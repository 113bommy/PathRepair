#include <bits/stdc++.h>
using namespace std;
const int MAXN = 80;
int n, r, m;
int ans;
int ansx[10], ansy[10];
vector<int> x, y;
int xx(int x) { return x * x; }
int a[10];
int dis(int i, int j) { return xx(x[i] - x[j]) + xx(y[i] - y[j]); }
void dfs(int now, int p) {
  if (now == n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) sum += dis(a[i], a[j]);
    if (ans < sum) {
      ans = sum;
      for (int i = 1; i <= n; i++) ansx[i] = x[a[i]], ansy[i] = y[a[i]];
    }
    return;
  }
  for (int i = p; i <= m - 1; i++) {
    a[now + 1] = i;
    dfs(now + 1, i);
  }
}
int from0(int id) { return xx(x[id]) + xx(y[id]); }
int main() {
  while (scanf("%d%d", &n, &r) != EOF) {
    x.clear(), y.clear();
    for (int i = -r; i <= r; i++) {
      int j = r;
      while (i * i + j * j > r * r) j--;
      x.push_back(i), y.push_back(j);
      if (j != 0) x.push_back(i), y.push_back(-j);
    }
    m = x.size();
    for (int i = 0; i <= m - 1; i++)
      for (int j = i + 1; j <= m - 1; j++) {
        if (from0(i) < from0(j)) {
          swap(x[i], x[j]);
          swap(y[i], y[j]);
        }
      }
    ans = -1;
    m = min(20, m);
    dfs(0, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", ansx[i], ansy[i]);
    }
  }
  return 0;
}
