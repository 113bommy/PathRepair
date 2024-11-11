#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, a = 0;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int j = 0; j < n; j++) {
    cout << arr[j] << " ";
  }
  return 0;
}
