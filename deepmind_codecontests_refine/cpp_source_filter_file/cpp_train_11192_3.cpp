#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long int arr[n], brr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) cin >> brr[i];
  sort(arr, arr + n);
  for (int i = 0; i < m; i++) {
    int x = upper_bound(arr, arr + n, brr[i]) - arr;
    cout << x << " ";
  }
  return 0;
}
