#include <bits/stdc++.h>
int d[1 << 20], m;
long long p[20], v[200009], u[200009];
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline void desc(long long q) {
  for (int i = 2; i <= 1000000; i++) {
    if (q % i == 0) {
      p[m++] = i;
      while (q % i == 0) q /= i;
    }
  }
  if (q == 1) return;
  for (int i = 1; i <= v[0] + u[0]; i++) {
    long long d = 1;
    if (i <= v[0])
      d = gcd(q, v[i]);
    else
      d = gcd(q, u[i - v[0]]);
    if (d != 1 && d != q) {
      p[m++] = d;
      p[m++] = q / d;
      return;
    }
  }
  p[m++] = q;
}
inline void deenamik() {
  for (int i = 1; i <= v[0]; i++) {
    int x = 0;
    for (int j = 0; j < m; j++)
      if (v[i] % p[j] == 0) x += 1 << j;
    d[x]++;
  }
  for (int i = 0; i < m; i++)
    for (int j = (1 << m) - 1; j >= 0; j--)
      if (j & (1 << i)) d[j] += d[j - (1 << i)];
}
int main() {
  int n;
  long long X, Y;
  fscanf(stdin, "%d%I64d%I64d", &n, &X, &Y);
  if (Y % X) {
    fprintf(stdout, "0\n");
    return 0;
  }
  Y /= X;
  for (int i = 0; i < n; i++) {
    long long x;
    fscanf(stdin, "%I64d", &x);
    long long d = gcd(x, X);
    x /= d;
    if (d == X) v[++v[0]] = x;
    if (Y % x == 0) u[++u[0]] = Y / x;
  }
  desc(Y);
  deenamik();
  long long ans = 0;
  for (int i = 1; i <= u[0]; i++) {
    int x = (1 << m) - 1;
    for (int j = 0; j < m; j++)
      if (u[i] % p[j] == 0) x -= 1 << j;
    ans += d[x];
  }
  fprintf(stdout, "%I64d\n", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
