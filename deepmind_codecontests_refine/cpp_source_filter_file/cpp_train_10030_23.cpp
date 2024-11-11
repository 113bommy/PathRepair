#include <bits/stdc++.h>
using namespace std;
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
long long modularExponentiation(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long binaryExponentiation(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x;
    x = x * x;
    n = n / 2;
  }
  return result;
}
long long modInverse(long long A, long long M) {
  return modularExponentiation(A, M - 2, M);
}
long long const BITMAX = 100000;
long long BIT[BITMAX];
void update(long long pos, long long x) {
  for (; pos < BITMAX; pos += pos & (-pos)) BIT[pos] += x;
}
long long Query(long long x) {
  long long sum = 0;
  for (; x < BITMAX; x -= x & (-x)) sum += BIT[x];
  return sum;
}
int main() {
  long long a, b, r;
  cin >> a >> b >> r;
  if (2 * r <= min(a, b))
    cout << "first";
  else
    cout << "second" << endl;
}
