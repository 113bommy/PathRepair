#include <bits/stdc++.h>
using namespace std;
int n, i, j, inv_old, inv_new, ans;
int a[2048];
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] = abs(a[i]);
  for (int i = 1; i <= n; i++) {
    inv_old = 0;
    for (int j = 1; j <= n; j++)
      if ((j < i && a[j] > a[i]) || (j > i && a[j] < a[i])) inv_old++;
    inv_new = 0;
    for (int j = 1; j <= n; j++)
      if ((j < i && a[j] > -a[i]) || (j > i && a[j] < -a[i])) inv_new++;
    if (inv_new < inv_old) a[i] *= -1;
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] > a[j]) ans++;
  cout << ans << "\n";
  return 0;
}
