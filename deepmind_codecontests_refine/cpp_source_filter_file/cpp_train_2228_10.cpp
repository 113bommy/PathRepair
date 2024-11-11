#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int arr[51];
  int min = 10000000;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + m);
  for (int i = 0; i < m - n; i++) {
    if (min > arr[i + n - 1] - arr[i]) {
      min = arr[i + n - 1] - arr[i];
    }
  }
  cout << min << endl;
  return 0;
}
