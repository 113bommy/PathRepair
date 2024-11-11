#include <bits/stdc++.h>
using namespace std;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
const int MAX_PRIME = 1000000;
int PrimeTable[1000000 >> 1];
int IsPrime[MAX_PRIME + 1];
int PrimeCnt = 0;
void get_prime() {
  memset(IsPrime, 1, sizeof(IsPrime));
  IsPrime[0] = IsPrime[1] = 0;
  for (int i = 2; i < MAX_PRIME; i++)
    if (IsPrime[i]) {
      for (long long j = (PrimeTable[PrimeCnt++] = i) * (long long)i;
           j < MAX_PRIME; j += i)
        IsPrime[j] = 0;
    }
}
int isprime(long long n) {
  for (int i = 0;; ++i) {
    long long t = PrimeTable[i];
    if (t * t > n) return 1;
    if (n % t == 0) return 0;
  }
  return 1;
}
long long N;
long long f(long long div, int i) {
  long long ret = N / div;
  for (int j = 0; j < i; ++j) {
    long long next = PrimeTable[j] * div;
    if (next <= N) ret -= f(next, j);
  }
  return ret;
}
int cal1(long long n, long long k) {
  if (k > n) return 1;
  int id =
      lower_bound(PrimeTable, PrimeTable + PrimeCnt, (long long)k) - PrimeTable;
  ::N = n;
  long long ans = f(1, id);
  return ans;
}
int cal(long long n, long long k) {
  if (k > n) return 0;
  if (k == 2) return n >> 1;
  return cal1(n / k, k);
}
int main() {
  get_prime();
  int a = Rint(), b = Rint(), k = Rint();
  if (!isprime(k)) {
    puts("0");
    return 0;
  }
  int ans = cal(b, k) - cal(a - 1, k);
  printf("%d\n", ans);
  return 0;
}
