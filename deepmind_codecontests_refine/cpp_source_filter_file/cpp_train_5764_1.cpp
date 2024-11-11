#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long mod(long long a) { return a % m; }
long long st(long long a, long long b) {
  if (b == 0) return 1LL;
  long long c = st(a, b / 2);
  if (b % 2 != 0)
    return mod(mod(a * c) * c);
  else
    return mod(c * c);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cout << st(3LL, n) - 1 << '\n';
  return 0;
}
