#include <bits/stdc++.h>
using namespace std;
long long mod(long long a, long long b) { return (a > b) ? (a - b) : (b - a); }
int main() {
  long long n, mn = 0, i, sum = 0, prev = 0;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    prev += a[i];
    if (sum - prev <= prev) break;
  }
  if (sum == 2 * prev)
    cout << "1\n";
  else {
    mn = min(mod(2 * prev, sum), mod(sum, 2 * (prev - a[i])));
    cout << mn + 1;
  }
  return 0;
}
