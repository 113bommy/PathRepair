#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, z, a[5005], b[50005], ans, val;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (long long i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  cout << a[n - 1] << " " << b[m - 1];
  return 0;
}
