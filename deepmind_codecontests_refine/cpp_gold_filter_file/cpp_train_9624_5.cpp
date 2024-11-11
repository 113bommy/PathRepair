#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long F(long long x) {
  if (x < 0) return -1;
  if (x > k) return -1;
  if (x > n - 1) return -1;
  if (k - x > m - 1) return -1;
  return (n / (x + 1)) * (m / (k - x + 1));
}
int main() {
  cin >> n >> m >> k;
  if (n < m) swap(n, m);
  if (n + m - 2 < k) {
    cout << "-1" << endl;
    return 0;
  }
  if (k <= m - 1) {
    cout << max(n * (m / (k + 1)), m * (n / (k + 1))) << endl;
    return 0;
  }
  if (k <= n - 1) {
    cout << m * (n / (k + 1)) << endl;
    return 0;
  }
  cout << max(m / (k - n + 2), n / (k - m + 2));
  return 0;
}
