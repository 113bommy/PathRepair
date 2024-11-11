#include <bits/stdc++.h>
using namespace std;
clock_t __START, __END;
double __TOTALTIME;
void _MS() { __START = clock(); }
void _ME() {
  __END = clock();
  __TOTALTIME = (double)(__END - __START) / CLOCKS_PER_SEC;
  cout << "Time: " << __TOTALTIME << " s" << endl;
}
const double E = 2.718281828;
const double PI = acos(-1.0);
const long long INF = (1LL << 60);
const int inf = (1 << 30);
const double ESP = 1e-9;
const int mod = (int)1e9 + 7;
const int N = (int)2e3 + 10;
long long sq[N][N];
long long sum[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (m < 2) {
    printf("0\n");
    return 0;
  }
  for (int i = 2; i <= m; ++i) sq[i][1] = 1;
  for (int i = 2; i <= n; ++i) {
    sq[2][i] = 1;
    sum[2] = 1;
    for (int j = 3; j <= m; ++j)
      sum[j] = sq[j][i - 1] + sum[j - 1], sum[j] %= mod;
    long long temp = 1;
    for (int j = 3; j <= m; ++j) temp += sum[j], temp %= mod, sq[j][i] = temp;
  }
  for (int j = 2; j <= m; ++j)
    for (int i = 2; i <= n; ++i) {
      sq[j][i] += sq[j][i - 1];
      sq[j][i] %= mod;
    }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) sum[j] = sq[j][n - i];
    for (int j = 3; j <= m; ++j) sum[j] += sum[j - 1], sum[j] %= mod;
    ans += sq[2][i] * (m - 2 + 1) % mod;
    ans %= mod;
    long long temp = 0;
    for (int j = 3; j <= m; ++j)
      ans += sq[j][i] * (m - j + 1) % mod, ans %= mod;
    for (int j = 3; j <= m; ++j) {
      temp += sum[j - 1];
      temp %= mod;
      temp += sq[j - 1][n - i];
      temp %= mod;
      ans += sq[j][i] * temp % mod * (m - j + 1) % mod;
      ans %= mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
