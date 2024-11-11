#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return a | b;
  return a > b ? gcd(a % b, b) : gcd(a, b % a);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long p, q, b;
    scanf("%lld%lld%lld", &p, &q, &b);
    long long temp;
    temp = gcd(p, q);
    q /= temp;
    for (temp = gcd(q, b), b /= temp; temp != q && temp != 1;) {
      q /= temp;
      temp = gcd(q, b);
    }
    if (temp == q)
      printf("Finite\n");
    else
      printf("Infinite\n");
  }
  return 0;
}
