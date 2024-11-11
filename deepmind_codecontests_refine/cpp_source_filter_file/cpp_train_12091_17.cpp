#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[202020], m1, m2, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m1)
      m1 = a[i];
    else if (a[i] > m2)
      m2 = a[i];
  }
  long long rund = m / (k + 1), yu = m % (k + 1);
  ans += rund * (k * m1 + m2);
  ans += yu * m1;
  cout << ans;
  return 0;
}
