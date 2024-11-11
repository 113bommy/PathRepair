#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int min, mid, max;
  if (a < b && a < c) {
    min = a;
    if (b < c) {
      mid = b;
      max = c;
    } else {
      mid = c;
      max = b;
    }
  } else if (b < a && b < c) {
    min = b;
    if (a < c) {
      mid = a;
      max = c;
    } else {
      mid = c;
      max = a;
    }
  } else {
    min = c;
    if (a < b) {
      mid = a;
      max = b;
    } else {
      mid = b;
      max = a;
    }
  }
  int sum = 0;
  if (mid - min < d) {
    sum += d - (mid - min);
  }
  if (max - mid < d) {
    sum += d - (max - mid);
  }
  cout << sum << endl;
  return 0;
}
