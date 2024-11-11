#include <bits/stdc++.h>
using namespace std;
long long k, a[1200000];
int n;
int main() {
  cin >> a[0] >> k;
  n = 0;
  while ((a[n] >= k) || (a[n] < 0)) {
    if (a[n] >= k) {
      long long x = a[n] / k;
      a[n] -= k * x;
      a[++n] = -x;
    } else {
      long long x = (-a[n] + k - 1) / k;
      a[n] += k * x;
      a[++n] = x;
    }
  }
  cout << n + 1 << endl;
  for (int i = 0; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
  return 0;
}
