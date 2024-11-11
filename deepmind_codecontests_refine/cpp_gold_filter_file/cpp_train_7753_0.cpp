#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 18;
const int inf = 1e9;
const int N = 21;
int n, m, ans[N][N], a[N], b[N];
vector<int> v[N];
short dp[21][11][11][11][11][11][11];
short way[21][11][11][11][11][11][11];
short f(int x, int s1, int s2, int s3, int s4, int s5, int last) {
  if (0 > s1 || 0 > s2 || 0 > s3 || 0 > s4 || 0 > s5) return 0;
  if (x == m + 1 && s1 + s2 + s3 + s4 + s5 == 0) return 1;
  if (x > m) return 0;
  short &r = dp[x][s1][s2][s3][s4][s5][last];
  if (r != -1) return r;
  r = 0;
  for (int i = 0; i <= (int)v[b[x]].size() - 1; i++) {
    int t = v[b[x - 1]][last], c = v[b[x]][i], t1 = s1, t2 = s2, t3 = s3,
        t4 = s4, t5 = s5;
    if (!(t & 1) && (c & 1)) t1--;
    if (!(t & 2) && (c & 2)) t2--;
    if (!(t & 4) && (c & 4)) t3--;
    if (!(t & 8) && (c & 8)) t4--;
    if (!(t & 16) && (c & 16)) t5--;
    way[x][s1][s2][s3][s4][s5][last] = i;
    if (f(x + 1, t1, t2, t3, t4, t5, i)) return r = 1;
  }
  return r;
}
int calc(int x) {
  int ans = 0;
  for (int i = 0; i <= n; i++)
    if ((x & (1 << i)) && !(x & (1 << i + 1))) ans++;
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 0; i <= (1 << n) - 1; i++) {
    v[calc(i)].push_back(i);
  }
  memset(dp, -1, sizeof dp);
  f(1, a[1], a[2], a[3], a[4], a[5], 0);
  int s1 = a[1], s2 = a[2], s3 = a[3], s4 = a[4], s5 = a[5], last = 0;
  for (int x = 1; x <= m; x++) {
    int mask = v[b[x]][way[x][s1][s2][s3][s4][s5][last]];
    for (int j = 0; j <= n - 1; j++)
      if (mask & (1 << j))
        ans[j + 1][x] = '*';
      else
        ans[j + 1][x] = '.';
    int t = v[b[x - 1]][last], c = mask;
    last = way[x][s1][s2][s3][s4][s5][last];
    if (!(t & 1) && (c & 1)) s1--;
    if (!(t & 2) && (c & 2)) s2--;
    if (!(t & 4) && (c & 4)) s3--;
    if (!(t & 8) && (c & 8)) s4--;
    if (!(t & 16) && (c & 16)) s5--;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%c", ans[i][j]);
    printf("\n");
  }
}
