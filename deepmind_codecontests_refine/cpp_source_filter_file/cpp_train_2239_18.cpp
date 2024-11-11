#include <bits/stdc++.h>
using namespace std;
int main() {
  int t[3][3], min = 0, j;
  bool flag = true;
  cin >> t[0][1] >> t[0][2] >> t[1][2];
  if (t[0][1] < t[0][2]) {
    min += t[0][1];
    if (t[0][1] + t[0][2] < t[1][2]) {
      min += t[0][1] + t[0][2];
      if (t[1][2] + t[0][1] < t[0][2])
        min += t[1][2] + t[0][1];
      else
        min += t[0][2];
    } else {
      min += t[1][2];
      if (t[1][2] + t[0][1] < t[0][2])
        min += t[1][2] + t[0][1];
      else
        min += t[0][2];
    }
  } else {
    min += t[0][2];
    if (t[0][1] + t[0][2] < t[1][2]) {
      min += t[0][1] + t[0][2];
      if (t[1][2] + t[0][1] < t[0][2])
        min += t[1][2] + t[0][1];
      else
        min += t[0][2];
    } else {
      min += t[1][2];
      if (t[1][2] + t[0][1] < t[0][2])
        min += t[1][2] + t[0][1];
      else
        min += t[0][2];
    }
  }
  cout << min << endl;
  return 0;
}
