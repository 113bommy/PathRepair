#include <bits/stdc++.h>
using namespace std;
int n, m, N, k;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) N += i / 2;
  if (m > N) {
    cout << -1;
    return 0;
  }
  N = 0;
  for (int i = 1; i <= n; ++i) {
    N += (i - 1) / 2;
    if (N + i / 2 > m) {
      k = i;
      break;
    }
  }
  for (int i = 1; i <= k; ++i) cout << i << ' ';
  m -= N;
  if (m) {
    cout << k + k - m - m << ' ';
    ++k;
  }
  for (int i = 1; k < n; ++k, ++i) {
    cout << 100000000 + i * 10000 << ' ';
  }
  return 0;
}
