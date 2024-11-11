#include <bits/stdc++.h>
using namespace std;
long long int ans = 1, m, n, q1, q2, r1, r2, a[100010], m1[10], i;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if (a[i] >= ans) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
