#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
int S[1000010], n, prod, pw2;
int main() {
  scanf("%d", &n);
  n -= 2;
  prod = 1;
  pw2 = 2;
  for (int i = 2; i <= n; i++) {
    pw2 = add(pw2, pw2);
    prod = mult(prod, dec(pw2, 3));
    S[i] = add(S[i - 1], mult(4, prod));
  }
  printf("%d\n", add(add(10, mult(8, S[n])), mult(2, mult(S[n], S[n]))));
  return 0;
}
