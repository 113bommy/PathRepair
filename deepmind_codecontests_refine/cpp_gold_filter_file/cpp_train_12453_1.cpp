#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int mo = 1e9 + 7;
long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
long long dec(long long x, long long y) { return x < y ? x - y + mo : x - y; }
long long quickmi(long long x, long long tim) {
  long long ret = 1;
  x = (x + mo) % mo;
  for (; tim; tim /= 2, x = x * x % mo)
    if (tim & 1) ret = ret * x % mo;
  return ret;
}
struct number {
  long long a, b;
  number(const long long a_ = 0, const long long b_ = 0) {
    a = a_;
    b = b_;
  }
};
number operator*(number a, number b) {
  return number(a.a * b.a % mo, (a.a * b.b + a.b) % mo);
}
number operator+(number a, number b) {
  return number(add(a.a, b.a), add(a.b, b.b));
}
number operator-(number a, number b) {
  return number(dec(a.a, b.a), dec(a.b, b.b));
}
number Inv(number a) {
  long long tmp = quickmi(a.a, mo - 2);
  return number(tmp, (mo - tmp * a.b % mo) % mo);
}
number quickmi(number x, long long tim) {
  number ret = number(1, 0);
  for (; tim; tim /= 2, x = x * x)
    if (tim & 1) ret = x * ret;
  return ret;
}
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
number sum(number S, number A, long long n) {
  if (!n) return number(0, 0);
  if (A.a == 1 && A.b == 0) return number(S.a * n % mo, S.b * n % mo);
  if (A.a == 1) {
    number tmp = number(n % mo, n * (n + 1) / 2 % mo * A.b % mo);
    return number(S.a * tmp.a % mo, (S.a * tmp.b + S.b * n) % mo);
  }
  number tmp = number((A.a + mo - 1) % mo, A.b * n % mo);
  number v = Inv(tmp) * (quickmi(A, n + 1) - A);
  return number(S.a * v.a % mo, (S.a * v.b + S.b * n) % mo);
}
long long solve(long long n, long long k, number A, number B, number S1,
                number S2) {
  if (!k) {
    long long tmp = A.b * quickmi(mo + 1 - A.a, mo - 2) % mo;
    return (S2.a * tmp + S2.b) % mo;
  }
  long long k_ = n % k, p = n / k;
  number S1_ = S1 + sum(S2, A, p), S2_ = S1 + sum(S2, A, p - 1);
  number B_ = Inv(B * quickmi(A, p)), A_ = Inv(B * quickmi(A, p - 1));
  return solve(k, k_, A_, B_, S1_, S2_);
}
long long solve(long long n, long long k) {
  return solve(n, k, number(1, 1), number((mo + 1) / 2, 1), number(1, 0),
               number(1, 0));
}
int main() {
  for (int T = get(); T; T--) {
    int n = get(), k = get();
    int d = gcd(n, k);
    n /= d, k /= d;
    cout << solve(n, k) * quickmi(n, mo - 2) % mo << endl;
  }
  return 0;
}
