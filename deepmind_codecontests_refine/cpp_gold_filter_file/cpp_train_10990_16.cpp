#include <bits/stdc++.h>
using namespace std;
int main() {
  int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int m, d;
  cin >> m >> d;
  if (month[m - 1] == 31) {
    if (d > 5) {
      cout << 6;
    } else {
      cout << 5;
    }
  } else if (month[m - 1] == 30) {
    if (d > 6) {
      cout << 6;
    } else {
      cout << 5;
    }
  } else {
    if (d > 1) {
      cout << 5;
    } else {
      cout << 4;
    }
  }
  return 0;
}
