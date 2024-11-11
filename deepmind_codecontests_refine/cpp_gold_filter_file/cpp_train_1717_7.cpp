#include <bits/stdc++.h>
using namespace std;
long long int N, k, l, mod;
int n;
long long int a[5][5];
long long int mat[5][5], pomocna[5][5];
long long int p2 = 1;
void mnozi() {
  memset(pomocna, 0, sizeof pomocna);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        pomocna[i][j] += (mat[i][k] * a[k][j]) % mod;
        pomocna[i][j] %= mod;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) mat[i][j] = pomocna[i][j];
}
void pot() {
  memset(pomocna, 0, sizeof pomocna);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        pomocna[i][j] += (a[i][k] * a[k][j]) % mod;
        pomocna[i][j] %= mod;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = pomocna[i][j];
}
void potenciranje() {
  mat[0][0] = 1;
  mat[0][1] = 1;
  mat[1][0] = 1;
  mat[1][1] = 0;
  a[0][0] = 1;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = 0;
  n = 2;
  long long int K = N + 1;
  while (K) {
    if (K % 2) mnozi();
    K /= 2;
    pot();
  }
  K = N;
  long long int baza = 2;
  p2 = 1;
  while (K) {
    if (K % 2) p2 = (p2 * baza) % mod;
    K /= 2;
    baza = (baza * baza) % mod;
  }
}
void rijesi() {
  potenciranje();
  long long int nule = mat[1][0] % mod;
  long long int jedinice = (p2 + mod - nule) % mod;
  long long int sol = 1;
  if (l < 63 && (1LL * 1 << l) <= k) {
    cout << 0 << endl;
    return;
  }
  if (l == 0 && k == 0) {
    cout << 1 % mod;
    return;
  }
  if (l == 0 && k != 0) {
    cout << 0;
    return;
  }
  for (int i = 0; i < l; i++) {
    long long int tmp = 1 << i;
    if (k & (1LL) * 1 << i)
      sol = (sol * jedinice) % mod;
    else
      sol = (sol * nule) % mod;
  }
  if (sol < 0) sol += mod;
  cout << sol % mod << endl;
}
int main(void) {
  cin >> N >> k >> l >> mod;
  rijesi();
  return 0;
}
