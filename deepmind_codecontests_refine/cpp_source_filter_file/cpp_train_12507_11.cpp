#include <bits/stdc++.h>
using namespace std;
int cl(int n) {
  if (n % 2 == 0)
    return n / 2;
  else
    return (n + 1) / 2;
}
int main() {
  int n, i, k;
  cin >> n;
  int arr[500];
  for (i = 0; i < n * 2; i++) cin >> arr[i];
  cin >> k;
  sort(arr, arr + (n * 2));
  for (i = 0; i < n * 2; i++) {
    if (arr[i] == k) {
      cout << n - cl(i / 2) << "\n";
      break;
    } else if (arr[i] < k && k < arr[i + 1]) {
      cout << n - ((i) / 2) << "\n";
      break;
    }
  }
}
