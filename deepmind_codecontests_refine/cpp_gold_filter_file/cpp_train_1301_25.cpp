#include <bits/stdc++.h>
using namespace std;
long long a[100100];
int main() {
  long long n, k, res = 0;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    res += a[i] / 10;
    a[i] = a[i] % 10;
  }
  sort(a + 1, a + n + 1, greater<long long>());
  for (long long i = 1; i <= n && k > 0; i++) {
    if (10 - a[i] <= k) {
      k -= (10 - a[i]);
      res++;
    }
  }
  res += k / 10;
  long long tt = n * 10;
  cout << min(res, tt);
}
