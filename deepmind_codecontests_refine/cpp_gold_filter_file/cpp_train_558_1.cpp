#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, t = 0, k = 0;
  int arr[1000] = {0};
  int brr[1000];
  cin >> y;
  bool beeb = 0, zero = 0, ten = 0, big = 0;
  for (int i = 0; i < y; i++) {
    cin >> x;
    brr[i] = x;
    if (y == 1) {
      cout << y << endl << x;
      return 0;
    }
    if (x == 0 && zero == 0) {
      t++;
      arr[t] = x;
      zero = 1;
    } else if (x == 10 || x == 20 || x == 30 || x == 40 || x == 50 || x == 60 ||
               x == 70 || x == 80 || x == 90) {
      if (ten == 0) {
        t++;
        arr[t] = x;
        ten = 1;
      }
    } else if (x == 100 && big == 0) {
      t++;
      arr[t] = x;
      big = 1;
    } else if (beeb == 0 && x < 10) {
      t++;
      arr[t] = x;
      beeb = 1;
    }
  }
  if (ten == 0 && t - y != 0 && beeb == 0) {
    t++;
    for (int i = 0; i < y; i++) {
      if (brr[i] % 10 != 0) {
        arr[t] = brr[i];
      }
    }
  }
  if (t - y == 0) {
    cout << t << endl;
    for (int i = 1; i <= t; i++) {
      cout << arr[i] << " ";
    }
  } else {
    cout << t << endl;
    for (int i = 1; i <= t; i++) {
      cout << arr[i] << " ";
    }
  }
  return 0;
}
