#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
int mp[maxn][maxn], n, m, a, b, q[maxn], tmp[maxn][maxn];
long long g[maxn * maxn], x, y, z;
int main() {
  scanf("%d%d%d%d", &n, &m, &a, &b);
  scanf("%I64d%I64d%I64d%I64sd", &g[0], &x, &y, &z);
  for (int i = 1; i <= n * m; ++i) g[i] = (1ll * g[i - 1] * x + y) % z;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) mp[i][j] = g[(i - 1) * m + j - 1];
  for (int i = 1; i <= n; ++i) {
    int head = 1, tail = 0;
    for (int j = 1; j <= m; ++j) {
      while (tail >= head && mp[i][j] <= mp[i][q[tail]]) --tail;
      while (tail >= head && j - q[head] > b - 1) head++;
      q[++tail] = j;
      tmp[i][j] = mp[i][q[head]];
    }
  }
  for (int j = 1; j <= m; ++j) {
    int head = 1, tail = 0;
    for (int i = 1; i <= n; ++i) {
      while (tail >= head && tmp[i][j] <= tmp[q[tail]][j]) --tail;
      while (tail >= head && i - q[head] > a - 1) ++head;
      q[++tail] = i;
      mp[i][j] = tmp[q[head]][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i >= a && j >= b) ans += mp[i][j];
    }
  }
  cout << ans << endl;
}
