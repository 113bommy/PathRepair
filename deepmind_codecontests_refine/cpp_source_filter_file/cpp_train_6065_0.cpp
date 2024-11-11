#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, arr[5000], k = 0, m = 0;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + x);
  if (x == 1 && arr[0] == 1)
    k = 0;
  else if (x == 1 && arr[0] != 1)
    k = 1;
  else if (x > 1) {
    for (int i = 0; i < x; i++) {
      if (arr[i] > x) m++;
    }
    if (m == x) {
      k = m;
    } else if (m == 0) {
      for (int i = 0; i <= x - 2; i++) {
        if (arr[i] == arr[i + 1]) k++;
      }
    } else if (m != 0) {
      for (int i = 0; i <= x - 2; i++) {
        if (arr[i] == arr[i + 1] && arr[i] < x && arr[i + 1] < x) k++;
      }
      k += m;
    }
  }
  cout << k << endl;
}
