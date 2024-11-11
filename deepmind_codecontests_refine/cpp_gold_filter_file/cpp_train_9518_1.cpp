#include <bits/stdc++.h>
using namespace std;
const int maxn = 90;
const int maxx = 10000;
const int MOd = 1e9 + 7;
int add(int &n, int x) {
  n += x;
  if (n >= MOd) n -= MOd;
}
int mul(int x, int y) { return (long long)x * y % MOd; }
int ar[maxn][maxn], ans[maxn][maxn], a, K;
int H[maxn][maxn];
void f(int ar[maxn][maxn], int bs[maxn][maxn]) {
  for (int i = 0; i <= K; i++)
    for (int j = 0; j <= K; j++) {
      H[i][j] = 0;
      for (int k = 0; k <= K; k++) {
        add(H[i][j], mul(ar[i][k], bs[k][j]));
      }
    }
  for (int i = 0; i <= K; i++)
    for (int j = 0; j <= K; j++) ar[i][j] = H[i][j];
}
int com[maxn][maxn];
int us[maxn];
int main() {
  long long a;
  cin >> a;
  scanf("%d", &K);
  if (a == 1) {
    printf("1\n");
    return 0;
  }
  com[0][0] = 1;
  for (int i = 1; i <= K + 3; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0)
        com[i][j] = 1;
      else
        com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOd;
    }
  us[0] = 1;
  for (int i = 1; i <= K + 5; i++) us[i] = mul(us[i - 1], 2);
  K = (K + 1) << 1;
  for (int i = 0; i < K; i += 2) {
    for (int j = 0; j <= i + 1; j++) {
      ar[j][i + 1] = com[i / 2][j / 2];
      if (~j & 1) ar[j][i + 1] = mul(ar[j][i + 1], us[(i - j) / 2]);
    }
    ar[i + 1][i] = 1;
  }
  ar[K][K] = ar[K - 1][K] = 1;
  for (int i = 0; i < K; i++) {
    if (~i & 1)
      ans[0][i] = 1;
    else
      ans[0][i] = us[i / 2 + 1];
  }
  ans[0][K] = 1;
  a -= 2;
  while (a) {
    if (a & 1) {
      f(ans, ar);
    }
    f(ar, ar);
    a >>= 1;
  }
  cout << (ans[0][K] + ans[0][K - 1]) % MOd << endl;
  return 0;
}
