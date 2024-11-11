#include <bits/stdc++.h>
using namespace std;
long long a[2001];
long long t(long long n, long long k) {
  for (int i = 0; i < 2000; i++) {
    a[i] = 1;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j < n; j++) {
      a[j] = (a[j] + a[j - 1]) % 1000000007;
    }
  }
  return a[n - k];
}
int main() {
  long long n, m, k;
  cin >> m >> n >> k;
  if (2 * k > m || 2 * k > 2 * n) {
    cout << 0;
    return 0;
  }
  cout << (t(m - 1, 2 * k) * t(n - 1, 2 * k)) % 1000000007 << endl;
  return 0;
}
