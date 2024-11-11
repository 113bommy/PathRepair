#include <bits/stdc++.h>
using namespace std;
const int Maxn = 50000;
int a[100];
bool u[100][Maxn][2];
long long f[100][Maxn][2];
long long dfs(int dep, long long n, int flag) {
  if (!n) return 0;
  if (dep < 0) return flag ? n : -n;
  if (n < Maxn && u[dep][n][flag]) return f[dep][n][flag];
  long long tmp = dfs(dep - 1, n, flag) + dfs(dep - 1, n / a[dep], !flag);
  if (n < Maxn) u[dep][n][flag] = true, f[dep][n][flag] = tmp;
  return tmp;
}
int main() {
  long long n;
  int k;
  scanf("%I64d%d", &n, &k);
  for (int i = 0; i < k; ++i) scanf("%d", a + i);
  sort(a, a + k);
  printf("%I64d\n", dfs(k - 1, n, 1));
  return 0;
}
