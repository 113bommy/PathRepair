#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int z = k1 + k2;
  int arr[n];
  int arr2[n];
  int arr_dif[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }
  for (int i = 0; i < n; i++) {
    arr_dif[i] = abs(arr[i] - arr2[i]);
  }
  sort(arr_dif, arr_dif + n);
  while (z--) {
    arr_dif[n - 1]--;
    if (arr_dif[n - 1] < 0) arr_dif[n - 1] *= -1;
    sort(arr_dif, arr_dif + n);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += arr_dif[i] * arr_dif[i];
  }
  cout << ans;
}
