#include <bits/stdc++.h>
using namespace std;
constexpr double eps = 1e-13;
constexpr long long M = 1e9 + 7;
constexpr int N = 5e5 + 100;
long long qpower(long long x, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * x % M;
    x = x * x % M;
    p >>= 1;
  }
  return ans;
}
auto print = [](int x) { cout << x << " "; };
int a[N], sz = 0;
int main() {
  ios::sync_with_stdio(false);
  long long p, k;
  cin >> p >> k;
  long long a0 = p, a1 = p;
  while (a1 != 0) {
    a1 = (-1) * (a0 / k);
    if (a0 < 0 && a0 % k != 0) a1++;
    a0 = a0 + a1 * k;
    a[sz++] = a0;
    a0 = a1;
  }
  cout << sz << endl;
  for (int i = 0; i < sz; ++i) {
    cout << a[i];
    if (i < sz - 1)
      cout << " ";
    else
      cout << endl;
  }
}
