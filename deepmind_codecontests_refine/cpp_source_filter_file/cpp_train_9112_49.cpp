#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main() {
  int n;
  double k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  double l = 0;
  double r = 1000;
  double mid;
  double b;
  for (int i = 0; i < 500; i++) {
    b = 0;
    mid = (l + r) / 2;
    for (int j = n - 1; j >= 0; j--) {
      if (arr[j] >= mid)
        b += double(arr[j] - mid) * (1 - k / 100);
      else
        b -= mid - arr[j];
    }
    if (b < 0)
      r = mid;
    else
      l = mid;
  }
  cout << setprecision(10) << endl;
  return 0;
}
