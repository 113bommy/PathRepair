#include <bits/stdc++.h>
long long P = 1000000007, k, inv2 = (P + 1ll) >> 1ll, C[201][201];
long long l, r;
inline long long mul(long long a, long long b) { return 1ll * a * b % P; }
std::vector<long long> operator*(std::vector<long long> A,
                                 std::vector<long long> B) {
  std::vector<long long> C(A.size() + B.size() - 1);
  for (long long i = A.size() - 1; ~i; --i)
    for (long long j = B.size() - 1; ~j; --j)
      (C[i + j] += mul(A[i], B[j])) %= P;
  return C;
}
long long qsm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
std::vector<long long> solve(long long l, long long r) {
  if (l == r) {
    std::vector<long long> A;
    A.push_back((P - l) % P);
    A.push_back(1);
    return A;
  }
  return solve(l, (l + r) >> 1) * solve(((l + r) >> 1) + 1, r);
}
struct num {
  long long a, b;
  num operator*(num rhs) {
    return (num){(mul(a, rhs.a) + mul(5, mul(b, rhs.b))) % P,
                 (mul(b, rhs.a) + mul(a, rhs.b)) % P};
  }
  num operator*(long long n) { return (num){mul(a, n), mul(b, n)}; }
  num operator+(num rhs) { return (num){(a + rhs.a) % P, (b + rhs.b) % P}; }
  num operator+(long long n) { return (num){(a + n) % P, b}; }
  num operator-(num rhs) {
    return (num){(a + P - rhs.a) % P, (b + P - rhs.b) % P};
  }
  num operator-(long long n) { return (num){(a + P - n) % P, b}; }
  num operator/(num rhs) {
    long long x = (mul(rhs.a, rhs.a) + P - mul(5, mul(rhs.b, rhs.b))) % P;
    rhs.b = P - rhs.b;
    num ans = ((*this) * rhs) * qsm(x, P - 2);
    return ((*this) * rhs) * qsm(x, P - 2);
  }
  bool operator==(num rhs) { return a == rhs.a && b == rhs.b; }
  void print() { printf("%I64d %I64d\n", a, b); }
} tema[201], temb[201], temc[201];
num qsm(num a, long long b) {
  num ans = (num){1, 0};
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
num sequence(num x, long long l, long long r) {
  if (x == (num){1, 0}) return (num){(r - l + 1) % P, 0};
  return (qsm(x, r + 1) - qsm(x, l)) / (x - 1);
}
long long getans(long long k) {
  num ans = (num){0, 0};
  for (long long j = 0; j <= k; j++)
    ans = ans + sequence(tema[j] * temb[k - j], l, r) * C[k][j] *
                    (((k - j) % 2 == 1) ? (P - 1) : 1);
  return (ans * temc[k]).a;
}
signed main() {
  scanf("%I64d%I64d%I64d", &k, &l, &r);
  l += 2, r += 2;
  std::vector<long long> A = solve(0, k - 1);
  long long tem = 1;
  for (long long i = 1; i <= k; i++) tem = mul(tem, i);
  tem = qsm(tem, P - 2);
  tema[0] = temb[0] = temc[0] = (num){1, 0};
  tema[1] = (num){inv2, inv2};
  temb[1] = (num){inv2, P - inv2};
  temc[1] = (num){0, qsm(5, P - 2)};
  for (long long i = 2; i <= k; i++)
    tema[i] = tema[i - 1] * tema[1], temb[i] = temb[i - 1] * temb[1],
    temc[i] = temc[i - 1] * temc[1];
  for (long long i = 0; i <= k; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
  }
  long long ans = 0;
  for (long long i = 0; i <= k; i++) {
    (ans += mul(A[i], getans(i))) %= P;
  }
  printf("%I64d\n", mul(ans, tem));
}
