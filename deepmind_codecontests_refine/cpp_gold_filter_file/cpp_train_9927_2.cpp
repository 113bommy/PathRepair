#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  cin >> n;
  int *arr = new int[n];
  int *arr1 = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr1[i] = arr[i];
  }
  sort(arr1, arr1 + n);
  for (int i = 0; i < n; i++) {
    if (arr1[i] != arr[i]) k++;
  }
  if (k <= 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
