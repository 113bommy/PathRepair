#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, k, a[100001], mini[100001];
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  mini[n - 1] = a[n - 1];
  for (i = n - 2; i >= 0; i--) mini[i] = min(mini[i + 1], a[i]);
  for (i = 0; i < n; i++) {
    k = lower_bound(mini + i + 1, mini + n, a[i]) - (mini + i + 1);
    cout << k - 1 << " ";
  }
  return 0;
}
