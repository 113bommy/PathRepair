#include <bits/stdc++.h>
using namespace std;
int n, k, a[5000], ans, i, l, m, t;
int main() {
  cin >> n;
  cin >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  ans = 0;
  sort(a, a + n);
  while (a[(n - 1) / 2] != k) {
    a[n++] = k;
    sort(a, a + n);
    ans++;
  }
  cout << ans;
}
