#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int M = 1000000007;
const double PI = atan(1) * 4;
const int oo = 1000000000;
long long A, B, n, x;
long long pw(long long x, long long p) {
  if (!p) return 1;
  long long d = pw(x, p / 2);
  d = (d * d) % M;
  if (p % 2) d = (d * x) % M;
  assert(x <= M);
  assert(d <= M);
  return d;
}
int main() {
  cin >> A >> B >> n >> x;
  if (A * x == 1) return cout << (n % M * B % M + 1) % M, 0;
  long long one = x * pw(A, n) % M;
  long long dom = pw(A, n) - 1;
  long long den = pw(A - 1, M - 2);
  cout << (one + B * ((dom * den) % M) % M) % M << endl;
}
