#include <bits/stdc++.h>
using namespace std;
const long long maxs = 1e5 + 3;
const long long maxs1 = 1e3 + 4;
const long long mod = 1e9 + 7;
long long in(long long n) {
  cin >> n;
  return n;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n = in(n);
  long long m = in(m);
  long long a[n];
  long long b[m];
  for (int i = 0; i < n; i++) a[i] = in(a[i]);
  for (int j = 0; j < m; j++) b[j] = in(b[j]);
  sort(a, a + n);
  sort(b, b + m);
  if (abs(a[n - 1] < b[0])) {
    cout << "-1";
    return 0;
  }
  if (a[n - 1] >= 2 * a[0]) {
    cout << a[n - 1];
    return 0;
  }
  for (long long i = a[n - 1]; i < b[0]; i++) {
    if (a[0] * 2 <= i) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
