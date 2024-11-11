#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10, mod = 1e9 + 7, inf = 1e18;
int a[maxn], n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int x;
  a[0] = 1;
  int d1 = 1, d2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x > 0)
      a[i] = a[i - 1];
    else
      a[i] = -a[i - 1];
    if (a[i] == 1)
      d1++;
    else
      d2++;
  }
  cout << d1 * d2 << " " << d1 * (d1 - 1) / 2 + d2 * (d2 - 1) / 2;
  return 0;
}
