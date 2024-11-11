#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, largest, s1, s2;
  cin >> a >> b >> c;
  if (a > b && a > c) {
    largest = a;
    s1 = b;
    s2 = c;
  }
  if (b > a && b > c) {
    largest = b;
    s1 = a;
    s2 = c;
  }
  if (c > b && c > a) {
    largest = c;
    s1 = b;
    s2 = a;
  }
  int res = 0;
  if (s1 + s2 > largest) {
    cout << res;
  } else {
    res = 1 + largest - s1 - s2;
    cout << res;
  }
}
