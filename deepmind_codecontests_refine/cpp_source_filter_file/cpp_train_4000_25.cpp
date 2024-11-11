#include <bits/stdc++.h>
using namespace std;
const long long N = 100000 + 77;
long long n, q, A, a[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= q; ++i) cin >> a[i] >> a[i];
  sort(a + 1, a + 1 + q);
  for (long long i = 1; i <= q; ++i) {
    long long cost = (i * (i - 1) / 2) + (i % 2 == 0 ? i / 2 : 0);
    if (cost > n) break;
    A += a[q - i + 1];
  }
  cout << A;
  return 0;
}
