#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int N = 2010;
const int mod = 1e9 + 7;
int a[N], b[N];
int dp[N][N];
int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  sort(b, b + m);
  int mi = INF;
  for (int j = 0; j <= m - n; j++) {
    int mx = 0;
    for (int i = 0; i < n; i++)
      mx = max(mx, abs(a[i] - b[j + i]) + abs(b[j + i] - p));
    mi = min(mi, mx);
  }
  printf("%d\n", mi);
  return 0;
}
