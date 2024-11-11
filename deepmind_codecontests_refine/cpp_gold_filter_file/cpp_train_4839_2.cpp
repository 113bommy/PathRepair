#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int mod = 1e9 + 7;
const int inf = 2e9;
int n, m;
char s[2][N][N];
bool p;
int reachU[N][N], reachD[N][N];
int reachL[N][N], reachR[N][N];
int sumD[N][N], sumU[N][N];
long long ans;
inline int get_sum(int sum[N], int L, int R) {
  if (L > R) return 0;
  return sum[R] - sum[L - 1];
}
void solve() {
  memset(reachU, 0, sizeof(reachU));
  memset(reachD, 0, sizeof(reachD));
  memset(reachL, 0, sizeof(reachL));
  memset(reachR, 0, sizeof(reachR));
  memset(sumD, 0, sizeof(sumD));
  memset(sumU, 0, sizeof(sumU));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (s[p][i][j] == '#') continue;
      reachU[i][j] = reachU[i - 1][j] + 1;
      reachL[i][j] = reachL[i][j - 1] + 1;
    }
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j) {
      if (s[p][i][j] == '#') continue;
      reachD[i][j] = reachD[i + 1][j] + 1;
      reachR[i][j] = reachR[i][j + 1] + 1;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      sumD[i][j] = sumD[i][j - 1] + (reachD[i][j] == n - i + 1);
      sumU[i][j] = sumU[i][j - 1] + (reachU[i][j] == i);
    }
  for (int j = 2; j < m; ++j) {
    for (int i = 2; i < n; ++i) {
      if (reachU[i][j] != i) continue;
      if (reachL[i][j] == j) ans++;
      if (reachR[i][j] == m - j + 1) ans++;
      ans += get_sum(sumD[i], j + 1, min(m - 1, j + reachR[i][j] - 1));
      ans += get_sum(sumD[i], max(2, j - reachL[i][j] + 1), j - 1);
      ans += get_sum(sumU[i], j + 2, min(m - 1, j + reachR[i][j] - 1));
      ans += get_sum(sumU[i], max(2, j - reachL[i][j] + 1), j - 2);
    }
    if (reachU[n][j] == n) ans++;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[p][i] + 1);
  for (int iter = 0; iter < 4; ++iter) {
    p ^= 1;
    swap(n, m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) s[p][i][j] = s[p ^ 1][j][n - i + 1];
    solve();
  }
  cout << ans / 2 << endl;
  return 0;
}
