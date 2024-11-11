#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000, MAX = 83;
const long long mod = 1000000007;
struct Matrix {
  long long a[MAX + 3][MAX + 3];
  Matrix() {
    for (int i = 1; i <= MAX; i++)
      for (int j = 1; j <= MAX; j++) a[i][j] = 0;
  }
  long long* operator[](int x) { return a[x]; }
};
long long sz, n, k, comb[45][45], pw[45] = {1};
Matrix operator*(Matrix a, Matrix b) {
  Matrix res;
  for (int i = 1; i <= sz; i++) {
    for (int j = 1; j <= sz; j++) {
      for (int k = 1; k <= sz; k++) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return res;
}
int main() {
  cin >> n >> k;
  if (n == 1) {
    puts("1");
    return 0;
  }
  sz = 2 * k + 3;
  Matrix a;
  for (int i = 1; i <= 40; i++) pw[i] = (pw[i - 1] << 1ll) % mod;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k; j++) {
      if (j == 0)
        comb[i][j] = 1;
      else if (i != 0)
        comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 1; i <= k + 1; i++) {
    for (int j = i; j <= k + 1; j++) {
      a[i][j] = comb[k - i + 1][j - i];
    }
    for (int j = k + i + 1; j <= 2 * k + 2; j++) {
      a[i][j] = (comb[k - i + 1][j - k - i - 1] * pw[j - k - i - 1]) % mod;
    }
  }
  for (int i = k + 2; i <= 2 * k + 2; i++) {
    a[i][i - k - 1] = 1;
  }
  for (int i = 1; i <= 2 * k + 2; i++) a[sz][i] = a[1][i];
  a[sz][sz] = 1;
  Matrix ans;
  for (int i = 1; i <= sz; i++) ans[i][i] = 1;
  for (n -= 2; n; n >>= 1) {
    if (n & 1) ans = ans * a;
    a = a * a;
  }
  long long res = 0;
  for (int i = 1; i <= k + 1; i++)
    res = (res + ans[sz][i] * pw[k - i + 2]) % mod;
  for (int i = k + 2; i <= 2 * k + 2; i++) res = (res + ans[sz][i]) % mod;
  res = (res + ans[sz][sz] * (1 + pw[k + 1])) % mod;
  cout << res << endl;
  return 0;
}
