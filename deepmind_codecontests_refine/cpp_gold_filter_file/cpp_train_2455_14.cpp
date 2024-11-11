#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int arr[a];
  for (int i = 0; i < a; i++) {
    cin >> arr[i];
  }
  int k = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + k);
  if (a == 1) {
    cout << arr[0];
  } else {
    cout << arr[a / 2];
  }
}
