#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i;
  long long t = 0;
  cin >> n >> k;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long l = 0;
  long long r = n - 1;
  long long sol = a[n - 1] - a[0];
  while (l < r && k) {
    if (l - 2 < n - r) {
      l++;
      t = min(a[l] - a[l - 1], k / l);
      k = k - t * l;
    } else {
      t = min(a[r] - a[r - 1], k / (n - r));
      k = k - t * (n - r);
      r--;
    }
    sol = sol - t;
  }
  cout << sol;
}
