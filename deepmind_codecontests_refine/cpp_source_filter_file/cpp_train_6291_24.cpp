#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, Min = 101;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i) {
    x = arr[i];
    int sum = 15 * x;
    for (int j = 0; j < x; ++j) {
      cin >> y;
      sum += y * 5;
    }
    Min = min(Min, sum);
  }
  cout << Min;
  return 0;
}
