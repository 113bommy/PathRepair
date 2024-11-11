#include <bits/stdc++.h>
using namespace std;
long long a[3][3], b[3][3], c[3][3], m, k, n, ans, ans_fin;
int l;
long long sqr(long long x) { return x * x; }
void pan() {
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++) {
      c[i][j] = ((b[i][1] * b[1][j]) % m + (b[i][2] * b[2][j]) % m) % m;
    }
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++) b[i][j] = c[i][j];
}
void pan1() {
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++) {
      c[i][j] = ((b[i][1] * a[1][j]) % m + (b[i][2] * a[2][j]) % m) % m;
    }
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 2; j++) b[i][j] = c[i][j];
}
void powmatrix(long long x) {
  if (x == 1)
    return;
  else if (x % 2 == 0) {
    powmatrix(x / 2);
    pan();
  } else {
    powmatrix(x / 2);
    pan();
    pan1();
  }
}
long long pow(long long x) {
  if (x == 1)
    return 2 % m;
  else if (x % 2 == 0)
    return sqr(pow(x / 2)) % m;
  else if (x % 2 == 1)
    return (sqr(pow(x / 2)) % m) * 2 % m;
}
int main() {
  scanf("%lld%lld%d%lld", &n, &k, &l, &m);
  if (l == 0) {
    if (k == 0)
      printf("%d\n", 1 % m);
    else
      printf("%d\n", 0);
    exit(0);
  }
  a[1][1] = 1;
  a[1][2] = 1;
  a[2][1] = 1;
  a[2][2] = 0;
  b[1][1] = 1;
  b[1][2] = 1;
  b[2][1] = 1;
  b[2][2] = 0;
  powmatrix(n + 1);
  ans = pow(n);
  ans = (ans - b[1][1] + m) % m;
  ans_fin = 1;
  for (int i = 1; i <= l; i++) {
    if (k % 2 == 0)
      ans_fin = (ans_fin * b[1][1]) % m;
    else
      ans_fin = (ans_fin * ans) % m;
    k /= 2;
  }
  while (k > 0) {
    if (k % 2 == 1) {
      printf("%d\n", 0);
      exit(0);
    }
    ans_fin = (ans_fin * b[1][1]) % m;
    k /= 2;
  }
  printf("%lld", ans_fin);
}
