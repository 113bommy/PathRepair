#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[100], arrr[100], o;
  cin >> o;
  for (int i = 0; i < o; i++) {
    cin >> arr[i];
  }
  for (int l = 0; l < o; l++) {
    int k = 0, s = 0;
    for (int i = 0; i < o; i++) {
      if (arr[l] > arr[i]) {
        k += 1;
      } else if (arr[l] == arr[i]) {
        s += 1;
      }
    }
    s -= 1;
    if (s >= 1) {
      for (int p = 1; p <= s; p++) {
        arrr[k + 1] = arr[l];
        arrr[k] = arr[l];
      }
    } else {
      arrr[k] = arr[l];
    }
  }
  for (int i = 0; i < o; i++) {
    cout << arrr[i] << ' ';
  }
  cout << endl;
  return 0;
}
