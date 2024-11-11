#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int a = 0;
  int b = 0;
  for (int k = 0; k < n; k++) cin >> arr[k];
  int i = 0;
  int j = n - 1;
  int count = 1;
  while (i != j) {
    if (count % 2 != 0) {
      if (arr[i] >= arr[j]) {
        a += arr[i];
        i++;
        count++;
      } else {
        a += arr[j];
        j--;
        count++;
      }
    } else {
      if (arr[i] >= arr[j]) {
        b += arr[i];
        i++;
        count++;
      } else {
        b += arr[j];
        j--;
        count++;
      }
    }
  }
  if (count % 2 != 0)
    a += arr[i];
  else
    b = arr[i];
  cout << a << " " << b;
  return 0;
}
