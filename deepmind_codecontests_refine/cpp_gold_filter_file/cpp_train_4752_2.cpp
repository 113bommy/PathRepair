#include <bits/stdc++.h>
using namespace std;
long long a, b, p, x, i, d, pos;
long long an, act, rat, k;
long long sol;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long cmmmc(long long a, long long b) { return (a * b) / gcd(a, b); }
long long poww(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return ans;
}
int main() {
  cin >> a >> b >> p >> x;
  an = a;
  for (i = 1; i <= p - 1 && i <= x; i++) {
    act = (an * i) % p;
    rat = p - an;
    rat %= p;
    k = poww(rat, p - 2);
    k = (k * (p + b - act)) % p;
    k *= (p - 1);
    pos = i + k;
    if (pos <= x) {
      sol++;
      sol += (x - pos) / ((p - 1) * p);
    }
    an = (an * a) % p;
  }
  cout << sol;
  return 0;
}
