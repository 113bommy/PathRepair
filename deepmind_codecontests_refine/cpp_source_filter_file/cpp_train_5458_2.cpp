#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5 + 5;
long long t, n;
bool isprime(long long v) {
  for (long long i = 2; i * i <= v; i++)
    if (v % i == 0) return false;
  return true;
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long l = n, r = n + 1;
    while (!isprime(l)) l--;
    while (!isprime(r)) r++;
    long long p, q;
    if (l % 2) {
      p = l - 2;
      q = l * 2;
    } else {
      p = l / 2 - 1;
      q = l;
    }
    long long c = gcd(p, q);
    p /= c;
    q /= c;
    long long P, Q;
    Q = l * r;
    P = n - l + 1;
    c = gcd(Q, P);
    P /= c;
    Q /= c;
    c = q * Q / gcd(q, Q);
    p *= c / q;
    P *= c / Q;
    p += P;
    q = c;
    c = gcd(p, q);
    p /= c;
    q /= c;
    cout << p << "/" << q << "\n";
  }
  return 0;
}
