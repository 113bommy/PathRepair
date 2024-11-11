#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MaxSize = 1e5 + 10086;
int n, m, l, r, k;
long long ans[MaxSize][105], C[MaxSize][105], sum[MaxSize];
long long add(long long a, long long b) {
  return a + b >= mod ? a + b - mod : a + b;
}
long long ADD(long long &a, long long b) {
  return a + b >= mod ? a = a + b - mod : a = a + b;
}
long long del(long long a, long long b) {
  return a - b <= 0 ? a - b + mod : a - b;
}
long long DEL(long long &a, long long b) {
  return a - b <= 0 ? a = a - b + mod : a = a - b;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &sum[i]);
  for (int i = 0; i <= n; i++) C[i][0] = 1;
  for (int i = 1; i <= n + 25; i++)
    for (int j = 1; j <= 101; j++) C[i][j] = add(C[i][j - 1], C[i - 1][j]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &l, &r, &k);
    ans[l][k]++;
    for (int j = k; j >= 0; j--) DEL(ans[r + 1][j], C[r - l + 1][k - j]);
  }
  for (int j = 101; j >= 0; j--)
    for (int i = 1; i <= n; i++)
      ADD(ans[i][j], ans[i][j + 1]), ADD(ans[i][j], ans[i - 1][j]);
  for (int i = 1; i <= n; i++) printf("%lld\n", ADD(sum[i], ans[i][0]));
}
