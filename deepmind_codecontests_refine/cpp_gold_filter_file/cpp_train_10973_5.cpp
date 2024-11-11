#include <bits/stdc++.h>
using namespace std;
const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
int _MINUS;
const int MXN = 2010;
const int C = 262144;
const int INF = 1000000001;
const int MOD = 1000000007;
char str[MXN];
int D[MXN][MXN];
int n, K;
int sum[MXN][MXN];
void test() {
  scanf("%d %d", &n, &K);
  scanf("%s", str + 1);
  D[0][0] = 1;
  sum[0][0] = 1;
  for (int i = (1); i <= (n); i++)
    for (int k = (0); k <= (K); k++) {
      for (int j = (i - 1); j >= (0); j--) {
        int d = (n - i + 1);
        if ((i - j) * d > k) break;
        D[i][k] = (D[i][k] + ((long long int)D[j][k - d * (i - j)] *
                              ('z' - str[i]) % MOD)) %
                  MOD;
      }
      D[i][k] =
          (D[i][k] + ((long long int)sum[i - 1][k] * (str[i] - 'a') % MOD)) %
          MOD;
      sum[i][k] = (sum[i - 1][k] + D[i][k]) % MOD;
    }
  int res = 0;
  for (int i = (0); i <= (n); i++) res = (res + D[i][K]) % MOD;
  printf("%d\n", res);
}
int main() {
  int te = 1;
  while (te--) test();
  return 0;
}
