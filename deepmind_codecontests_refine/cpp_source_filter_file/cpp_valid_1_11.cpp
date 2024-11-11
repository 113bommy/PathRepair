#include <bits/stdc++.h>
using namespace std;
void run_case() {
  long long n;
  cin >> n;
  vector<long long> h(4);
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    if (x % 4 != 0 && y % 4 != 0) {
      h[0]++;
    } else if (x % 4 != 0) {
      h[1]++;
    } else if (y % 4 != 0) {
      h[2]++;
    } else {
      h[3]++;
    }
  }
  auto choose = [&](long long n, long long r) {
    if (r == 2) {
      return n * (n - 1) / 2;
    }
    if (r == 3) {
      return n * (n - 1) * (n - 2) / 3;
    }
  };
  auto calc = [&](long long x, long long y, long long z) {
    return (choose(x, 2) + choose(y, 2)) * z;
  };
  long long res = 0;
  for (long long i = 0; i < 3; i++) {
    res += choose(h[i], 3);
    res += h[3 - i] * choose(h[i], 2);
  }
  res += calc(h[0], h[3], h[1] + h[2]);
  res += calc(h[1], h[2], h[0] + h[3]);
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T = 1;
  for (long long t = 1; t <= T; t++) {
    run_case();
  }
  return 0;
}
