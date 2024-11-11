#include <bits/stdc++.h>
using namespace std;
const int inf = ((1 << 30) - 1);
const long long linf = ((1ll << 62) - 1);
long long a, b;
int f(long long p, long long q) {
  if (p == 1 && q == 1) return 1;
  if (p > q) {
    if (p % q == 0) {
      assert(q == 1);
      return f(1, q) + (p - 1) / q;
    }
    return f(p % q, q) + p / q;
  }
  return f(q - p, p) + 1;
}
int main() {
  cin >> a >> b;
  cout << f(a, b) << '\n';
  return 0;
}
