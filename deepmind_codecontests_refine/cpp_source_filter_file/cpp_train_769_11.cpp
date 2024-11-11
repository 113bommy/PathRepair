#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  int lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    bool check = true;
    for (int i = 0, j = n - mid; i < mid; ++i, ++j) {
      if (2 * arr[i] > arr[j]) check = false;
    }
    if (check)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  cout << n - (lo - 1) << endl;
  return 0;
}
