#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int base = 31337;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;
int n;
char niz[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int pref[maxn][maxn];
int get(int a, int b, int c, int d) {
  c++, d++;
  return pref[c][d] - pref[a][d] - pref[c][b] + pref[a][b];
}
int f(int a, int b, int c, int d) {
  int &ret = dp[a][b][c][d];
  if (ret != -1) return ret;
  ret = (!!get(a, b, c, d)) * max(c - a + 1, d - b + 1);
  for (int i = a; i < c; i++) {
    ret = min(ret, f(a, b, i, d) + f(i + 1, b, c, d));
  }
  for (int i = b; i < d; i++) {
    ret = min(ret, f(a, b, c, i) + f(a, i + 1, c, d));
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", niz + i);
  }
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pref[i + 1][j + 1] = (niz[i][j] == '#');
      pref[i + 1][j + 1] += pref[i + 1][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pref[i + 1][j + 1] += pref[i][j + 1];
    }
  }
  printf("%lld\n", f(0, 0, n - 1, n - 1));
  return 0;
}
