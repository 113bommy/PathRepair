#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, i;
  cin >> n >> m >> r;
  int arr1[n], arr2[m];
  for (i = 0; i < n; i++) cin >> arr1[i];
  for (i = 0; i < m; i++) cin >> arr2[i];
  int mini = *min_element(arr1, arr1 + n);
  int maxi = *max_element(arr2, arr2 + n);
  int ans = r % mini + (r / mini) * maxi;
  if (ans < r) {
    cout << r;
    return 0;
  }
  cout << ans;
}
