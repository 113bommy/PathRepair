#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  int arr[n];
  for (i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);
  int price = 0, k = 1, ans[100000], t = 0;
  i = 0;
  while (price + k <= m) {
    if (arr[i] != k) {
      price += k;
      ans[t++] = k;
    } else
      i++;
    k++;
  }
  cout << t << "\n";
  while (t--) {
    cout << ans[t] << " ";
  }
}
