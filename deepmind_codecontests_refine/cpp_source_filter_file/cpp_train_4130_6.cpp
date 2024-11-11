#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[100] = {}, cou = 0, arr2[100];
  cin >> n;
  bool x[100] = {false};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!x[arr[i]]) {
      x[arr[i]] = true;
      arr2[cou] = arr[i];
      cou++;
    }
  }
  cout << cou << endl;
  for (int i = cou - 1; i > 0; i--) {
    cout << arr2[i] << ' ';
  }
  cout << arr2[0] << endl;
  return 0;
}
