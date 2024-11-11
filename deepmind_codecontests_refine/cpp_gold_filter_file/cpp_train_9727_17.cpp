#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18;
const int INF = (int)1e9 + 7;
const int N = (int)1e5 + 7;
const double EPS = (double)1e-9;
const double PI = (double)3.14159265359;
const int MODULO[6] = {INF,        1000019677, 1000019393,
                       1000007521, 1000024073, 1000009667};
const int PF[5] = {77, 31, 98, 45, 67};
const int nx[4] = {0, 0, 1, -1};
const int ny[4] = {1, -1, 0, 0};
inline bool eq(const long double &a, const long double &b) {
  return fabs(a - b) < EPS;
}
int n, m, k, mod;
int val[1010][1010];
int was[1010], was1[1010];
int main() {
  srand(time(NULL));
  scanf("%d%d%d", &n, &m, &k);
  if (n % 2 != m % 2) {
    puts("0");
    return 0;
  }
  int res = 0, ans = 0, res1 = 0;
  while (k--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    val[a][b] = c;
    was[a]++;
    was1[b]++;
  }
  scanf("%d", &mod);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (was[i] != m && was1[j] != n && val[i][j]) ans++;
  for (int i = 1; i <= n; i++) {
    int c = 0, mul = 1;
    for (int j = 1; j <= m; j++) {
      c += (val[i][j] != 0);
      mul *= val[i][j];
    }
    if (mul == 1) {
      puts("0");
      return 0;
    }
    if (c < m) res++;
  }
  for (int i = 1; i <= m; i++) {
    int c = 0, mul = 1;
    for (int j = 1; j <= n; j++) {
      c += (val[j][i] != 0);
      mul *= val[j][i];
    }
    if (mul == 1) {
      puts("0");
      return 0;
    }
    if (c < n) res1++;
  }
  int tot = 1;
  for (int i = 1; i <= (res - 1) * (res1 - 1) - ans; i++) {
    tot += tot;
    tot %= mod;
  }
  cout << tot;
  return 0;
}
