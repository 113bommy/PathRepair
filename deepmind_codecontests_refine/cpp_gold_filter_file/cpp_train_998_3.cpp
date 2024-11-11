#include <bits/stdc++.h>
using namespace std;
int x, y;
int prime[100005];
bool is_prime[100005];
int t;
int sieve(int n) {
  int p = 0;
  for (int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return p;
}
long long _sqr(long long x) {
  long long l = 1, r = 1000001;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (mid * mid * mid <= x)
      l = mid;
    else
      r = mid;
  }
  return l;
}
int main() {
  int n;
  scanf("%d", &n);
  int num = sieve(32005);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    long long s = (long long)x * y;
    long long res = _sqr(s);
    if (res * res * res != s || x % res != 0 || y % res != 0) {
      puts("No");
      continue;
    }
    long long xx = x / res, yy = y / res;
    if (xx * yy == res)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
