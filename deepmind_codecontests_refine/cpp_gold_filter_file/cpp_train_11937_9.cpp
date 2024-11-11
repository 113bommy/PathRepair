#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, s[3][4], r0, r1, c0, c1, n;
  char c;
  cin >> n;
  for (int t = 0; t < 4; t++) {
    getchar();
    r0 = 0;
    c0 = 0;
    r1 = 1;
    c1 = 1;
    s[0][t] = 0;
    s[1][t] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> c;
        a = c - '0';
        if (a != r0) s[0][t]++;
        if (r0 == 0)
          r0 = 1;
        else
          r0 = 0;
        if (a != r1) s[1][t]++;
        if (r1 == 0)
          r1 = 1;
        else
          r1 = 0;
      }
      if (c0 == 0) {
        c0 = 1;
        r0 = 1;
      } else {
        c0 = 0;
        r0 = 0;
      }
      if (c1 == 0) {
        c1 = 1;
        r1 = 1;
      } else {
        c1 = 0;
        r1 = 0;
      }
    }
  }
  int x, output = 99999999;
  x = s[0][0] + s[0][1] + s[1][2] + s[1][3];
  if (x < output) output = x;
  x = s[0][0] + s[0][2] + s[1][1] + s[1][3];
  if (x < output) output = x;
  x = s[0][0] + s[0][3] + s[1][1] + s[1][2];
  if (x < output) output = x;
  x = s[0][1] + s[0][2] + s[1][0] + s[1][3];
  if (x < output) output = x;
  x = s[0][1] + s[0][3] + s[1][0] + s[1][2];
  if (x < output) output = x;
  x = s[0][2] + s[0][3] + s[1][0] + s[1][1];
  if (x < output) output = x;
  cout << output << endl;
  return 0;
}
