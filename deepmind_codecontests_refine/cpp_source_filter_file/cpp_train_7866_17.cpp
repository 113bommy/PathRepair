#include <bits/stdc++.h>
long long m;
long long n, inv;
long long a[100010];
long long x, d;
long long S1, S2;
long long A, B;
long long b[100010];
bool exist[100010];
long long power(long long k, long long p) {
  if (k == 0) return 0;
  if (p == 0) return 1;
  if (p == 1) return k;
  long long r = power(k * k % m, p / 2);
  if (p % 2 == 1) {
    r = r * k;
    r %= m;
  }
  return r;
}
std::pair<long long, long long> power_IR(long long a, long long b, long long c,
                                         long long p) {
  if (a == 0 || b == 0) return std::make_pair(0, 0);
  if (p == 0) return std::make_pair(1, 0);
  if (p == 1) return std::make_pair(a, b);
  long long A = a * a;
  A %= m;
  long long t = b * b;
  t %= m;
  t = t * c;
  t %= m;
  A = A + t;
  A %= m;
  long long B = a * b;
  B %= m;
  B = 2 * B;
  B %= m;
  std::pair<long long, long long> r = power_IR(A, B, c, p / 2);
  if (p % 2 == 1) {
    A = r.first;
    B = r.second;
    r.first = a * A;
    r.first %= m;
    t = b * B;
    t %= m;
    t = t * c;
    t %= m;
    r.first = r.first + t;
    r.first %= m;
    r.second = a * B;
    r.second %= m;
    t = A * b;
    t %= m;
    r.second = r.second + t;
    r.second %= m;
  }
  return r;
}
int main() {
  scanf("%I64d%I64d", &m, &n);
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    S1 += a[i];
    S1 %= m;
    S2 += a[i] * a[i];
    S2 %= m;
  }
  if (n == 1)
    printf("%I64d 0\n", a[0]);
  else if (n > m)
    printf("-1\n");
  else if (n == m)
    printf("0 1\n");
  else if (n + 1 == m) {
    for (int i = 0; i < n; i++) exist[a[i]] = true;
    for (int k = 0; k < m; k++)
      if (!exist[k]) {
        printf("%I64d 1\n", (k + 1) % m);
        break;
      }
  } else {
    inv = power(n, m - 2);
    long long tmp;
    tmp = n * (n - 1) / 2;
    tmp %= m;
    tmp = tmp * tmp;
    tmp %= m;
    tmp = tmp * inv;
    tmp %= m;
    A = tmp;
    tmp = n * (n - 1) / 2;
    tmp %= m;
    tmp = tmp * (n - 1);
    tmp %= m;
    A = A - tmp + m;
    A %= m;
    long long t1 = n - 1;
    long long t2 = n;
    long long t3 = 2 * n - 1;
    if (t1 % 2 == 0)
      t1 /= 2;
    else
      t2 /= 2;
    if (t1 % 3 == 0)
      t1 /= 3;
    else if (t2 % 3 == 0)
      t2 /= 3;
    else
      t3 /= 3;
    tmp = t1 * t2;
    tmp %= m;
    tmp = tmp * t3;
    tmp %= m;
    A = A + tmp;
    A %= m;
    tmp = inv * S1;
    tmp %= m;
    tmp = tmp * S1;
    tmp %= m;
    B = S2 - tmp + m;
    B %= m;
    tmp = power(A, m - 2);
    B = B * tmp;
    B %= m;
    tmp = power(B, (m - 1) / 2);
    if (tmp == -1)
      printf("-1\n");
    else if (tmp == 0)
      printf("-1\n");
    else {
      srand(time(NULL));
      for (;;) {
        t1 = rand() * (RAND_MAX + 1) + rand();
        t1 %= m;
        if (t1 == 0) continue;
        t2 = t1 * t1;
        t1 %= m;
        t2 = t2 - B + m;
        t2 %= m;
        t3 = power(t2, (m - 1) / 2);
        if (t3 == m - 1) break;
      }
      std::pair<long long, long long> r = power_IR(t1, 1, t2, (m + 1) / 2);
      d = r.first;
      x = inv * S1;
      x %= m;
      tmp = n * (n - 1) / 2;
      tmp %= m;
      tmp = tmp * inv;
      tmp %= m;
      tmp = tmp * d;
      tmp %= m;
      x = x - tmp + m;
      x %= m;
      for (int i = 0; i < n; i++) {
        b[i] = i * d;
        b[i] %= m;
        b[i] = b[i] + x;
        b[i] %= m;
      }
      std::sort(a, a + n);
      std::sort(b, b + n);
      bool check1 = true;
      for (int i = 0; i < n && check1; i++)
        if (a[i] != b[i]) check1 = false;
      if (check1) printf("%I64d %I64d\n", x, d);
      d = m - r.first;
      x = inv * S1;
      x %= m;
      tmp = n * (n - 1) / 2;
      tmp %= m;
      tmp = tmp * inv;
      tmp %= m;
      tmp = tmp * d;
      tmp %= m;
      x = x - tmp + m;
      x %= m;
      for (int i = 0; i < n; i++) {
        b[i] = i * d;
        b[i] %= m;
        b[i] = b[i] + x;
        b[i] %= m;
      }
      std::sort(a, a + n);
      std::sort(b, b + n);
      bool check2 = true;
      for (int i = 0; i < n && check2; i++)
        if (a[i] != b[i]) check2 = false;
      if (check2 && !check1) printf("%I64d %I64d\n", x, d);
      if (!check1 && !check2) printf("-1\n");
    }
  }
  return 0;
}
