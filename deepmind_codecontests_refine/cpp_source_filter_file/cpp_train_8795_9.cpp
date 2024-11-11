#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f, t = 6, x(0);
  cin >> n >> f;
  int arr[10001];
  x = f;
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if (x > arr[n - 1]) {
    cout << "0\n";
    return 0;
  }
  while (true) {
    f++;
    if (f > arr[n - 1]) {
      cout << f - x << "\n";
      return 0;
    }
    arr[n - 1]--;
    sort(arr, arr + n);
  }
  return 0;
}
