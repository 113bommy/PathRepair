#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[200001], l, r;
  long long max, sum_l, sum_r;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  max = 0;
  l = 0;
  r = n - 1;
  sum_l = arr[l];
  sum_r = arr[r];
  while (l < r) {
    if (sum_l == sum_r) max = sum_l;
    if (sum_l <= sum_r) {
      l++;
      sum_l += arr[l];
    } else {
      r--;
      sum_r += arr[r];
    }
  }
  cout << max << endl;
  return 0;
}
