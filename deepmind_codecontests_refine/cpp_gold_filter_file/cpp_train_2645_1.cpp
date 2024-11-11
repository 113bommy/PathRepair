#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long gcd(long long a, long long b) {
  return a % b == 0 ? a : gcd(b, a % b) + a / b;
}
void doit() { printf("%I64d\n", gcd(n, m)); }
int main() {
  while (scanf("%I64d%I64d", &n, &m) != EOF) doit();
}
