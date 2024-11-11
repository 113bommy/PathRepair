#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B;
long long dpf(long long x) {
  if (x < k) return (x - 1) * A;
  long long r, a;
  r = x % k;
  x -= r;
  a = (x - x / k) * A;
  return dpf(x / k) + r * A + min(a, B);
}
int main() {
  cin >> n >> k >> A >> B;
  k > 1 ? cout << dpf(n) << "\n" : cout << (n - 1) * A << "\n";
}
