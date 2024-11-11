#include <bits/stdc++.h>
using namespace std;
long long int factorial[10000001] = {0};
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int powerFunction(long long int x, long long int y) {
  long long int res = 1;
  long long int p = 1000000007;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void factorialFunction(long long int maxLimit) {
  factorial[0] = 1;
  for (long long int i = 1; i <= maxLimit; i++)
    factorial[i] = (factorial[i - 1] * i) % 1000000007;
  return;
}
long long int nCr(long long int n, long long int r) {
  if (r < 0 || r > n) {
    return 0;
  }
  long long int temp = factorial[n];
  temp *= (powerFunction(factorial[r], 1000000007 - 2) % 1000000007);
  temp %= 1000000007;
  temp *= (powerFunction(factorial[n - r], 1000000007 - 2) % 1000000007);
  temp %= 1000000007;
  return temp;
}
long long int prime[10000007];
void sieveFunction(long long int maxL) {
  memset(prime, -1, sizeof(prime));
  prime[0] = 0;
  prime[1] = 1;
  for (long long int i = 2; i <= maxL; i++) {
    if (prime[i] == -1)
      for (long long int j = i; j <= maxL; j += i) prime[j] = i;
  }
}
long long int na, nb, nc;
long long int ea, eb, ec;
long long int a = 0, b = 0, c = 0;
long long int r;
bool ispos(long long int cnt) {
  long long int cnta = cnt, cntb = cnt, cntc = cnt;
  cnta *= a;
  cntb *= b;
  cntc *= c;
  cnta = max((long long int)0, cnta - na);
  cntb = max((long long int)0, cntb - nb);
  cntc = max((long long int)0, cntc - nc);
  if (cnta * ea + cntb * eb + cntc * ec <= r)
    return true;
  else
    return false;
}
signed main() {
  string s;
  cin >> s;
  for (long long int i = 0; i < (long long int)s.size(); i++)
    if (s[i] == 'B')
      a++;
    else if (s[i] == 'S')
      b++;
    else
      c++;
  cin >> na >> nb >> nc;
  cin >> ea >> eb >> ec;
  cin >> r;
  long long int ans = 0;
  long long int l = 0, r = 10000000000000;
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    if (ispos(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << "\n";
}
