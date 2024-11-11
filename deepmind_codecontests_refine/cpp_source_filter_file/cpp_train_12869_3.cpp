#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 11;
long long c[N][N];
void init() {
  int i, j;
  for (i = 0; i < N; ++i) c[0][i] = 1;
  for (i = 1; i < N; ++i)
    for (j = i; j < N; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1] * j) % mod;
}
int main() {
  init();
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  if (x > y) swap(x, y);
  if (x > z) swap(x, z);
  if (y > z) swap(y, z);
  printf("%lld\n", (((c[x][y] * c[x][z]) % mod) * c[y][z]) % mod);
  return 0;
}
