#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000007;
int n;
int sum[maxn][5];
long long sqr(long long x) { return x * x; }
int SG(long long x) {
  if (x <= 3) return 0;
  if (x <= 15) return 1;
  if (x <= 81) return 2;
  if (x <= 6723) return 0;
  if (x <= 50625) return 3;
  if (x <= 1000000) return 1;
  long long R = (long long)(sqrt((double)x)), L = (long long)(sqrt((double)R));
  while (sqr(sqr(L)) < x) L++;
  while (sqr(R) > x || R == x) R--;
  for (int j = 0; j < 5; j++)
    if (sum[R][j] - sum[L][j] == 0) return j;
}
int main() {
  memset(sum, 0, sizeof(sum));
  sum[0][0] = 1;
  for (int i = 1; i <= 1000000; i++)
    for (int j = 0; j < 5; j++) sum[i][j] = sum[i - 1][j] + (SG(i) == j);
  scanf("%d", &n);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    res ^= SG(x);
  }
  puts((res) ? "Furlo" : "Rublo");
  return 0;
}
