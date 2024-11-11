#include <bits/stdc++.h>
using namespace std;
int ans, k;
char a[111111], b[111111];
int main() {
  int i, n;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  int l = 1, r = n;
  while (a[l] == b[l]) l++;
  while (a[r] == b[r]) r--;
  int k = l;
  while (a[k] == b[k + 1] && k < n) k++;
  if (k == r) ans++;
  k = l + 1;
  while (a[k] == b[k - 1] && k <= n) k++;
  if (k == r + 1) ans++;
  cout << ans << endl;
  return 0;
}
