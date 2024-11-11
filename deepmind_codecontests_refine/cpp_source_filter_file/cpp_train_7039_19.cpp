#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int INF = 1e9 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long l, r;
  cin >> l >> r;
  auto f = [](long long n) {
    long long res = 0;
    for (long long p = 1; n; n /= 10, p *= 10) {
      res += p * (9 - n % 10);
    }
    return res;
  };
  long long res = max(f(l) * l, f(r) * r);
  for (long long p = 1; p < r; p *= 10) {
    if (5 * p > l) {
      res = max(res, f(5 * p) * 5 * p);
    }
  }
  cout << res;
}
