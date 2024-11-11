#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int arr1[a], arr2[b];
  for (int i = 0; i < a; i++) cin >> arr1[i];
  for (int i = 0; i < b; i++) cin >> arr2[i];
  sort(arr1, arr1 + a);
  sort(arr2, arr2 + b);
  bool chk = false, chk1 = true;
  int p = arr1[a - 1];
  for (int i = 0; i < a; i++) {
    if (arr1[i] * 2 <= arr1[a - 1]) {
      chk = true;
      chk1 = false;
    } else {
      if (chk1) {
        p = arr1[i] * 2;
        chk1 = false;
      }
    }
  }
  if (p < arr2[0])
    cout << p << '\n';
  else
    cout << -1 << '\n';
}
