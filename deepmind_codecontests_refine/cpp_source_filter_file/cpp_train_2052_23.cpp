#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int N = 3005;
int f[N][N];
int n, D;
vector<int> e[N];
void DP(int x) {
  for (int i = (1); i <= (int)n + 3; i++) f[x][i] = 1;
  for (int i = (0); i <= (int)e[x].size() - 1; i++) {
    int to = e[x][i];
    DP(to);
    for (int j = (1); j <= (int)n + 3; j++)
      f[x][j] = 1ll * f[x][j] * f[to][j] % mo;
  }
  for (int i = (1); i <= (int)n + 3; i++)
    (((f[x][i]) += (f[x][i - 1])) >= mo ? f[x][i] -= mo : 233);
}
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
int inv[N];
void lag() {
  int ans = 0;
  inv[1] = 1;
  for (int i = (2); i <= (int)n + 3; i++)
    inv[i] = inv[mo % i] * (mo - mo / i) % mo;
  for (int i = (1); i <= (int)n + 3; i++) {
    int tmp = 1;
    for (int j = (1); j <= (int)n + 3; j++)
      if (j != i)
        tmp = 1ll * tmp * (mo + D - j) % mo *
              (i > j ? inv[i - j] : mo - inv[j - i]) % mo;
    (((ans) += (1ll * tmp * f[1][i] % mo)) >= mo ? ans -= mo : 233);
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d%d", &n, &D);
  for (int i = (2); i <= (int)n; i++) {
    int x;
    scanf("%d", &x);
    e[x].push_back(i);
  }
  DP(1);
  lag();
}
