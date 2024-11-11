#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
long long Gcd(long long a, long long b) { return b ? Gcd(b, a % b) : a; }
int k = 0, p[N / 10];
bool ip[N + 10];
void Init() {
  for (int i = 2; i <= N - 10; ++i) {
    if (!ip[i]) p[++k] = i;
    for (int j = 1, tmp; (tmp = i * p[j]) <= N; ++j) {
      ip[tmp] = 1;
      if (!(i % p[j])) break;
    }
  }
  return;
}
bool Check(int x) {
  for (int i = 1, t = sqrt(x); p[i] <= t; ++i)
    if (!(x % p[i])) return 0;
  return 1;
}
int Upper(int x) {
  for (; !Check(++x);)
    ;
  return x;
}
int Lower(int x) {
  for (; !Check(x); --x)
    ;
  return x;
}
int main() {
  Init();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long p = Lower(n), q = Upper(n);
    long long x = p * q - 2 * p - 2 * q + 2 * n + 2, y = p * q * 2,
              g = Gcd(x, y);
    x /= g;
    y /= g;
    printf("%lld/%lld\n", x, y);
  }
  return 0;
}
