#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = false;
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return f ? -x : x;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
const long long dev = 998244535;
int t, top;
char in[1005];
long long dp[1005][3][3], TMP[1005][3][3];
long long sear(int l) {
  int a = 0, A[1005];
  while (in[top++] == '(' && top < strlen(in)) {
    A[++a] = top - 1;
    sear(top - 1);
  }
  if (a == 0) {
    dp[l][0][1] = dp[l][0][2] = dp[l][1][0] = dp[l][2][0] = 1;
    return 4;
  }
  TMP[1][1][0] = dp[A[1]][1][0];
  TMP[1][2][0] = dp[A[1]][2][0];
  TMP[1][0][1] = dp[A[1]][0][1];
  TMP[1][0][2] = dp[A[1]][0][2];
  for (int i = 2; i <= a; i++) {
    TMP[i][0][0] =
        ((TMP[i - 1][0][0] + TMP[i - 1][0][2]) * dp[A[i]][1][0] % dev +
         (TMP[i - 1][0][0] + TMP[i - 1][0][1]) * dp[A[i]][2][0] % dev) %
        dev;
    TMP[i][0][1] = ((TMP[i - 1][0][0] + TMP[i - 1][0][2] + TMP[i - 1][0][1]) *
                    dp[A[i]][0][1] % dev);
    TMP[i][0][2] = ((TMP[i - 1][0][0] + TMP[i - 1][0][2] + TMP[i - 1][0][1]) *
                    dp[A[i]][0][2] % dev);
    TMP[i][1][0] =
        ((TMP[i - 1][1][0] + TMP[i - 1][1][2]) * dp[A[i]][1][0] % dev +
         (TMP[i - 1][1][0] + TMP[i - 1][1][1]) * dp[A[i]][2][0] % dev) %
        dev;
    TMP[i][1][1] = ((TMP[i - 1][1][0] + TMP[i - 1][1][2] + TMP[i - 1][1][1]) *
                    dp[A[i]][0][1] % dev);
    TMP[i][1][2] = ((TMP[i - 1][1][0] + TMP[i - 1][1][2] + TMP[i - 1][1][1]) *
                    dp[A[i]][0][2] % dev);
    TMP[i][2][0] =
        ((TMP[i - 1][2][0] + TMP[i - 1][2][1]) * dp[A[i]][2][0] % dev +
         (TMP[i - 1][2][0] + TMP[i - 1][2][2]) * dp[A[i]][1][0] % dev) %
        dev;
    TMP[i][2][1] = ((TMP[i - 1][2][0] + TMP[i - 1][2][2] + TMP[i - 1][2][1]) *
                    dp[A[i]][0][1] % dev);
    TMP[i][2][2] = ((TMP[i - 1][2][0] + TMP[i - 1][2][2] + TMP[i - 1][2][1]) *
                    dp[A[i]][0][2] % dev);
  }
  if (l < 0)
    return TMP[a][0][0] + TMP[a][0][1] + TMP[a][0][2] + TMP[a][1][0] +
           TMP[a][1][1] + TMP[a][1][2] + TMP[a][2][0] + TMP[a][2][1] +
           TMP[a][2][2];
  dp[l][0][1] = (TMP[a][1][0] + TMP[a][2][0] + TMP[a][0][2] + TMP[a][1][2] +
                 TMP[a][0][0] + TMP[a][2][2]) %
                dev;
  dp[l][0][2] = (TMP[a][1][0] + TMP[a][2][0] + TMP[a][0][1] + TMP[a][1][1] +
                 TMP[a][0][0] + TMP[a][2][1]) %
                dev;
  dp[l][1][0] = (TMP[a][0][1] + TMP[a][0][2] + TMP[a][2][0] + TMP[a][2][1] +
                 TMP[a][0][0] + TMP[a][2][2]) %
                dev;
  dp[l][2][0] = (TMP[a][0][1] + TMP[a][0][2] + TMP[a][1][0] + TMP[a][1][1] +
                 TMP[a][0][0] + TMP[a][1][2]) %
                dev;
  return 0;
}
int main() {
  t = 1;
  while (t--) {
    cin >> in;
    top = 0;
    (write(sear(-1) % dev), putchar('\n'));
  }
  return 0;
}
