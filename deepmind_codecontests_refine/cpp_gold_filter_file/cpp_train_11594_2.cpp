#include <bits/stdc++.h>
using namespace std;
long long s, a[105], ans[105], n = 0;
int k;
int main() {
  cin >> s >> k;
  k = min(k, 30);
  a[0] = 0, a[1] = 1;
  for (int i = 2; i <= 50; ++i)
    for (int j = 1; j <= k; ++j)
      if (i - j >= 0) a[i] += a[i - j];
  for (int i = 50; i >= 0; --i)
    if (s >= a[i]) s -= a[i], ans[++n] = a[i];
  cout << n << endl;
  for (int i = 1; i <= n; ++i)
    if (i < n)
      cout << ans[i] << " ";
    else
      cout << ans[i] << endl;
  return 0;
}
