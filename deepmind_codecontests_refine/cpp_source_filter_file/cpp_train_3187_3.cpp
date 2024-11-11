#include <bits/stdc++.h>
using namespace std;
long long cnt, prime[100], pcnt;
long long flg;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long search(long long a, long long b) {
  if (!b) return 0;
  long long d = gcd(a, b);
  a /= d;
  b /= d;
  long long minn = 1 << 30;
  for (int i = 1; i <= cnt; i++)
    if (a % prime[i] == 0) minn = min(minn, b % prime[i]);
  if (minn == 1 << 30) return b;
  return minn + search(a, b - minn);
}
int main() {
  long long a, b;
  scanf("%I64d%I64d", &a, &b);
  long long A = a;
  for (long long i = 2; i * i <= A; i++) {
    if (a % i == 0) {
      while (a % i == 0) {
        a /= i;
      }
      prime[++cnt] = i;
    }
  }
  if (a > prime[cnt]) prime[++cnt] = a;
  if (a == A) {
    printf("%I64d", A > b ? b : b % A + (b - b % A) / A);
    return 0;
  }
  long long ans = search(A, b);
  printf("%I64d", ans);
}
