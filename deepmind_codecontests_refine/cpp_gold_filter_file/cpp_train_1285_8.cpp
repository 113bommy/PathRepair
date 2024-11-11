#include <bits/stdc++.h>
using namespace std;
int64_t exp(int64_t a, int64_t b) {
  if (b == 0) return 1;
  int64_t c = exp(a, b / 2);
  c = c * c;
  if (b % 2) c = c * a;
  return c;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t k, b, n, t;
  cin >> k >> b >> n >> t;
  int cur = 0;
  int64_t total = 1;
  while (total <= t) {
    cur += 1;
    total = total * k + b;
  }
  if (n - cur < 0)
    cout << 0;
  else
    cout << n - cur + 1;
}
