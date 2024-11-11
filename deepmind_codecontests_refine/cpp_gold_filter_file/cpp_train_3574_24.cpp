#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans;
  cin >> ans;
  int arr[10000];
  int c = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  while (arr[(n - 1) / 2] != ans) {
    arr[n++] = ans;
    c++;
    sort(arr, arr + n);
  }
  cout << c;
  return 0;
}
