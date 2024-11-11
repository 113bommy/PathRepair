#include <bits/stdc++.h>
using namespace std;
constexpr int kMod = int(1E9 + 7), kN = int(100);
struct Matrix {
  long long int val[kN][kN];
  Matrix() { memset(val, 0, sizeof(val)); }
  void operator*=(Matrix a) {
    long long int tmp[kN][kN];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < kN; i++)
      for (int j = 0; j < kN; j++)
        for (int k = 0; k < kN; k++)
          tmp[i][j] += val[i][k] * a.val[k][j] % kMod;
    for (int i = 0; i < kN; i++)
      for (int j = 0; j < kN; j++) val[i][j] = tmp[i][j] % kMod;
    return;
  }
};
Matrix Pow(Matrix a, long long int b) {
  Matrix ans;
  for (int i = 0; i < kN; i++) ans.val[i][i] = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
  }
  return ans;
}
long long int Pow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return ans;
}
long long int Rev(long long int n) { return Pow(n, kMod - 2); }
long long int f[kN], inf[kN];
void pre() {
  f[0] = f[1] = inf[0] = inf[1] = 1;
  for (int i = 2; i < kN; i++) f[i] = f[i - 1] * i % kMod;
  inf[kN - 1] = Rev(f[kN - 1]);
  for (int i = kN - 1; i > 2; i--) inf[i - 1] = inf[i] * i % kMod;
}
long long int C(int n, int m) {
  return f[n] * inf[m] % kMod * inf[n - m] % kMod;
}
int main() {
  pre();
  long long int n, k, tmp;
  Matrix A, ans;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= i; j++) A.val[k - i][k - j] = C(i, j);
  for (int i = 0; i <= k; i++)
    for (int j = k + 1; j <= k * 2 + 1; j++) A.val[i][j] = A.val[i][j - k - 1];
  for (int i = k + 1; i <= k * 2 + 1; i++)
    for (int j = 0; j <= k; j++) A.val[i][j] = A.val[i - k - 1][j];
  A.val[k * 2 + 2][0] = A.val[k * 2 + 2][k * 2 + 2] = 1;
  ans = Pow(A, n);
  tmp = 0;
  for (int i = 0; i < k * 2 + 2; i++) tmp += ans.val[k * 2 + 2][i];
  printf("%lld\n", tmp % kMod);
}
