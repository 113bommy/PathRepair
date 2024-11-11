#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int power(long long int a, long long int b, long long int m) {
  long long int r = 1;
  while (b) {
    if (b & 1) r = r * a % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return r;
}
long long int power(long long int a, long long int b) {
  long long int r = 1;
  while (b) {
    if (b & 1) r = r * a;
    a = a * a;
    b >>= 1;
  }
  return r;
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int modularInverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int ceill(int a, int b) { return ((a + b - 1) / b); }
int mini(int a, int b) { return a < b ? a : b; }
int maxi(int a, int b) { return a > b ? a : b; }
int a[505][505];
int cas = 0;
int main() {
  int i, j, k, t, n, te;
  t = 1;
  while (t--) {
    scanf("%lld", &n);
    scanf("%lld", &k);
    int c = 1;
    for (int i = (0); i < (n); i++) {
      for (int j = (0); j < (k - 1); j++) {
        a[i][j] = c;
        c++;
      }
    }
    for (int i = (0); i < (n); i++) {
      for (int j = (k - 1); j < (n); j++) {
        a[i][j] = c;
        c++;
      }
    }
    int ans = 0;
    for (int i = (0); i < (n); i++) ans = ans + a[i][k - 1];
    printf("%d\n", ans);
    for (int i = (0); i < (n); i++) {
      for (int j = (0); j < (n - 1); j++) {
        printf("%d ", a[i][j]);
      }
      printf("%d", a[i][n - 1]);
      printf("\n");
    }
  }
  return 0;
}
