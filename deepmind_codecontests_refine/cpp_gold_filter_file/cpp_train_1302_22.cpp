#include <bits/stdc++.h>
using namespace std;
long long q = 1000000007;
long long P(long long a, long long b) {
  long long i = 1;
  for (long long j = 0; j < b; j++) {
    i = ((i * a) % q);
  }
  return i;
}
int main() {
  long long n, p, k;
  cin >> p >> k;
  if (k == 0) {
    cout << P(p, p - 1);
    return 0;
  }
  long long t = 1;
  long long i = k % p;
  while (i != 1) {
    i = ((i * k) % p);
    t += 1;
  }
  t = (p - 1) / t;
  long long b = P(p, t);
  if ((k % p) == 1) {
    b = ((b * p) % q);
  }
  cout << b;
  return 0;
}
