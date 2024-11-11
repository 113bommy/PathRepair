#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int x1, y1, z1;
  cin >> x1 >> y1 >> z1;
  int a[6];
  for (int i = 0; i < 6; i++) cin >> a[i];
  int sum = 0;
  if (x < 0)
    if (y < 0)
      if (z < 0)
        sum = a[0] + a[2] + a[4];
      else if (z <= z1)
        sum = a[0] + a[4];
      else
        sum = a[0] + a[4] + a[3];
    else if (y <= y1)
      if (z < 0)
        sum = a[2] + a[4];
      else if (z <= z1)
        sum = a[4];
      else
        sum = a[4] + a[3];
    else if (z < 0)
      sum = a[1] + a[2] + a[4];
    else if (x <= z1)
      sum = a[1] + a[4];
    else
      sum = a[1] + a[3] + a[4];
  else if (x <= x1)
    if (y < 0)
      if (z < 0)
        sum = a[0] + a[2];
      else if (z <= z1)
        sum = a[0];
      else
        sum = a[0] + a[3];
    else if (y <= y1)
      if (z < 0)
        sum = a[2];
      else
        sum = a[3];
    else if (z < 0)
      sum = a[1] + a[2];
    else if (x <= z1)
      sum = a[1];
    else
      sum = a[1] + a[3];
  else if (y < 0)
    if (z < 0)
      sum = a[0] + a[2] + a[5];
    else if (z <= z1)
      sum = a[0] + a[5];
    else
      sum = a[0] + a[5] + a[3];
  else if (y <= y1)
    if (z < 0)
      sum = a[2] + a[5];
    else if (z <= z1)
      sum = a[5];
    else
      sum = a[5] + a[3];
  else if (z < 0)
    sum = a[1] + a[2] + a[5];
  else if (x <= z1)
    sum = a[1] + a[5];
  else
    sum = a[1] + a[3] + a[5];
  cout << sum << endl;
  return 0;
}
