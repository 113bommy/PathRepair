#include <bits/stdc++.h>
using namespace std;
const long long N = 7;
const long long md = 1e9 + 7;
int main() {
  long long m, i, j, q, w, r = 0, x, l, n, R = 0, k, t;
  cin >> n;
  vector<long long> a(n), b(n);
  vector<pair<long long, long long> > c(n);
  for (long long i = 0; i < (n); i++) {
    cin >> a[i];
    if (a[i] != 0) c[a[i] - 1] = {i, 1};
  }
  for (long long i = 0; i < (n); i++) {
    cin >> b[i];
    if (b[i] != 0) c[b[i] - 1] = {i, 2};
  }
  k = c[0].first;
  long long z = 0;
  for (long long j = k + 1; j < (n); j++)
    if (b[j] != b[j - 1] + 1) z = -1;
  if (z == 0 && c[0].second == 2) {
    long long f = 0;
    for (long long j = 0; j < (k); j++)
      if (b[j] != 0) f = max(f, j - b[j] + b[n - 1] + 2);
    if (f > 0)
      cout << n + k + 1;
    else
      cout << k;
  } else {
    if (c[0].second == 1) k = -1;
    long long f = 0;
    for (long long i = k + 1; i < (n); i++)
      if (b[i] != 0) {
        f = max(f, i - k - b[i] + 1);
      }
    cout << f + n + k + 1;
  }
}
namespace {
auto fast_io = [] {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
}
