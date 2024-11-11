#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
int car[62][62][62];
int memo[62][62][76];
int n;
int solve(int s, int t, int k) {
  if (s == t) return 0;
  if (k < 0) return 100000000;
  return memo[s][t][k];
}
int main() {
  int i, j, l, k, r, m, s, t;
  scanf("%d %d %d", &n, &m, &r);
  for (l = 0; l < m; l++) {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) scanf("%d", &car[l][i][j]);
    for (k = 0; k < n; k++)
      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          car[l][i][j] = min(car[l][i][j], car[l][i][k] + car[l][k][j]);
  }
  for (l = 0; l < m; l++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) car[0][i][j] = min(car[0][i][j], car[l][i][j]);
  for (k = 0; k <= 62; k++)
    for (s = 0; s < n; s++)
      for (t = 0; t < n; t++) {
        int &r = memo[s][t][k];
        r = INT_MAX;
        for (i = 0; i < n; i++) r = min(r, car[0][s][i] + solve(i, t, k - 1));
      }
  for (i = 0; i < r; i++) {
    scanf("%d %d %d", &s, &t, &k);
    printf("%d\n", solve(s - 1, t - 1, min(k, 62)));
  }
}
