#include <bits/stdc++.h>
using namespace std;
int a[1000000], t[1000000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  int sum = 0;
  for (int i = 0; i < n; i++)
    if (t[i] == 1) sum += a[i];
  int l = 0, maxi = 0;
  for (int i = 1; i <= k; i++)
    if (t[i] == 0) l += a[i];
  maxi = max(maxi, l);
  for (int i = k + 1; i <= n; i++) {
    if (t[i - k] == 0) l -= a[i - k];
    if (t[i] == 0) l += a[i];
    maxi = max(maxi, l);
  }
  cout << maxi + sum;
  return 0;
}
