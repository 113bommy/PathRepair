#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    if (i == n)
      arr[i] = k;
    else if (k >= i) {
      arr[i] = i;
      k -= i;
    } else if (k < i) {
      arr[i] = k;
      k = 0;
    } else if (k <= 0) {
      arr[i] = k;
      k = 0;
    }
  }
  int l = n + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = l; j <= n; j++) {
      cout << arr[j] << " ";
    }
    for (int m = 1; m < l; m++) cout << arr[m] << " ";
    l--;
    cout << endl;
  }
  return 0;
}
