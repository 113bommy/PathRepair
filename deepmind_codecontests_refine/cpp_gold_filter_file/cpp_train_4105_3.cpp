#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], i;
  for (i = 0; i < n; i++) cin >> arr[i];
  int ind = 0, price;
  int max = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      ind = i;
    }
  }
  sort(arr, arr + n);
  price = arr[n - 2];
  cout << ind + 1 << " " << price;
  return 0;
}
