#include <bits/stdc++.h>
using namespace std;
int n, k, mx, i, a[100005];
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  k = 1;
  for (i = 1; i <= n; i++) {
    if (a[i] != a[i + 1])
      k++;
    else
      k = 1;
    if (k > mx) mx = k;
  }
  cout << mx;
  return 0;
}
