#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, arr[100], c1 = 0, c2 = 1, c3 = 0, temp, n = 0;
  int temp2 = 0;
  cin >> x;
  arr[1] = 0;
  arr[2] = 1;
  for (int i = 3; i < 100; i++) {
    c3 = c1 + c2;
    temp = c3;
    c1 = c2;
    c2 = temp;
    arr[i] = c3;
  }
  for (int i = 1; i < 100; i++) {
    if (x == arr[i]) {
      temp2 = i;
    }
  }
  if (x == 2) {
    cout << 1 << " " << 1 << " " << 0;
  } else if (x == 1) {
    cout << 1 << " " << 0 << " " << 0;
  } else if (x == 0) {
    cout << 0 << " " << 0 << " " << 0;
  } else
    cout << setprecision(13) << arr[temp2 - 1] << " " << arr[temp2 - 3] << " "
         << arr[temp2 - 4];
}
