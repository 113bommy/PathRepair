#include <bits/stdc++.h>
namespace IO {
template <class T>
void Read(T &x) {
  x = 0;
  char ch = getchar();
  bool f(0);
  while (ch < '0' || '9' < ch) {
    if (ch == '-') {
      f = 1;
    }
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
}
template <class T>
void Write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (9 < x) {
    Write(x / 10);
  }
  putchar(x % 10 ^ 48);
}
template <class T>
void Writeln(T x) {
  Write(x);
  puts("");
}
void Writeln() { puts(""); }
}  // namespace IO
using namespace IO;
using namespace std;
const int MAXN = 1e6 + 5;
const long long MOD = 998244353;
long long Pow(long long a, long long b) {
  long long result = 1;
  while (b) {
    if (b & 1) {
      result = result * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return result;
}
int n;
int n1, n2;
long long fac[MAXN], inv[MAXN];
long long C(const int n, const int m) {
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int main() {
  Read(n);
  fac[0] = 1;
  for (int i(1); i <= (n); ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  inv[n] = Pow(fac[n], MOD - 2);
  for (int i(n - 1); (0) <= i; --i) {
    inv[i] = inv[i + 1] * (i + 1) % MOD;
  }
  int num;
  for (int i(1); i <= (n); ++i) {
    Read(num);
    n1 += num == 1;
    n2 += num == 2;
  }
  long long answer = 0;
  for (int i(0); i <= (n1 >> 1); ++i) {
    answer = (answer + fac[i << 1] * C(n1, i << 1) % MOD *
                           Pow(Pow(2, i), MOD - 2) % MOD * inv[i]) %
             MOD;
  }
  long long sum = 1;
  for (int i(n1 + 1); i <= (n); ++i) {
    sum = sum * i % MOD;
  }
  Writeln(answer * sum % MOD);
  return 0;
}
