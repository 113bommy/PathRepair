#include <bits/stdc++.h>
using namespace std;
int main() {
  int d1, d2, d3;
  int x = 0;
  int s1, s2, s3, s4, s5;
  cin >> d1 >> d2 >> d3;
  s1 = d1 + d1 + d2 + d2;
  s2 = d2 + d3 + d1;
  s3 = d2 + d2 + d1 + d1;
  s4 = (d2 * 2) + (d3 * 2);
  s5 = (d3 * 2) + d1 + d2;
  if (s1 > s2) {
    x = s2;
  } else {
    x = s1;
  }
  if (x > s3) {
    x = s3;
  }
  if (x > s4) {
    x = s4;
  } else {
    x = x;
  }
  if (x > s5) {
    x = s5;
  } else {
    x = x;
  }
  cout << x << endl;
  return 0;
}
