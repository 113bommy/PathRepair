#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, k, sum = 0;
  cin >> n >> k >> x;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = n - 1; i > 0; i--) {
    if (k == 0) {
      break;
    }
    arr[i] = x;
    k--;
  }
  for (int i = 0; i < n; i++) sum += arr[i];
  cout << sum;
  return 0;
}
