#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN];
int32_t main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n - 1; i++)
    if (a[i] % 2 != a[i + 1] % 2 && a[i] % 2 != a[i - 1] % 2)
      return cout << i + 1, 0;
  if (a[0] % 2 != a[1] % 2)
    cout << 1;
  else if (a[n - 1] % 2 != a[n - 2] % 2)
    cout << n;
}
