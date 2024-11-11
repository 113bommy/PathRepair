#include <bits/stdc++.h>
int q, I[200010];
long long inv(int a, int p) {
  return a == 1 ? 1 : (1 + p * (a - inv(p % a, a))) / a % p;
}
int f(int a, int b) {
  int s = 0;
  for (int i = 0; i < a + b - 1; i++)
    s = (s + ((i + 1 < a ? i + 1 : a) - (i - b + 1 > 0 ? i - b + 1 : 0)) * 1ll *
                 i % q * I[i + 2]) %
        q;
  return (q + 1ll) / 2 * s % q;
}
int main() {
  int n, k;
  scanf("%d%d%d", &n, &k, &q);
  --k;
  if (k > 18) k = 18;
  int a = n >> k, b = a + 1, x, y;
  if (a)
    x = (b << k) - n, y = (1 << k) - x;
  else
    x = 0, y = n;
  for (int i = *I = 1; i <= a + b; i++) I[i] = I[i - 1] * 1ll * i % q;
  long long P = inv(I[a + b], q);
  for (int i = a + b; i; i--) I[i] = I[i - 1] * P % q, P = P * i % q;
  int s = (x * (x - 1ll) / 2 % q * f(a, a) + 1ll * x * y % q * f(a, b) +
           y * (y - 1ll) / 2 % q * f(b, b) +
           a * (a - 1ll) / 2 % q * (q + 1 >> 1) % q * x +
           b * (b - 1ll) / 2 % q * (q + 1 >> 1) % q * y) %
          q;
  printf("%d\n", s);
}
