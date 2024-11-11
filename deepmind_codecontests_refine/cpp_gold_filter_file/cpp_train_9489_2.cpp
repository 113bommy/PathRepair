#include <bits/stdc++.h>
using namespace std;
int kar(int *arr, int n) {
  if (n == 1) return 1;
  int flag = 0;
  int first, second;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    first = kar(arr, n / 2);
    second = kar(arr + n / 2, n / 2);
    return first > second ? first : second;
  }
  return n;
}
int main() {
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << kar(arr, n);
  return 0;
}
