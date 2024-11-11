#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int car_1 = a;
  int car_2 = b;
  int car_3 = c;
  if (d <= 2 * c && 2 * d >= c) {
    if (d > c)
      car_3 = d;
    else
      car_3 = c;
    if (d * 2 >= car_2) car_2 = d * 2 + 1;
    if (car_2 > b * 2) {
      cout << "-1";
      return 0;
    }
    if (car_2 < b) car_2 = b;
    if (car_2 >= car_1) car_1 = car_2 + 1;
    cout << car_1 << endl << car_2 << endl << car_3;
  } else {
    cout << "-1";
  }
  return 0;
}
