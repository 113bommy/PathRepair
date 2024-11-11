#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, num;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if (k > n)
    cout << -1;
  else {
    cout << arr[k - 1] << " " << 0;
  }
}
