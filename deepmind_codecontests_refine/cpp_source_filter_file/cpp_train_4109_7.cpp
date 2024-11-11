#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3], total = 0, i, j, for1[3] = {0};
  for (i = 0; i < 3; i++) {
    cin >> a[i];
  }
  if (a[0] == 1 && a[1] == 1 && a[2] == 1)
    total = a[0] + a[1] + a[2];
  else if (a[0] == 1 && a[1] == 1 && a[2] != 1)
    total = (a[0] + a[1]) * a[2];
  else if (a[0] == 1 && a[1] != 1 && a[2] == 1)
    total = a[0] + a[1] + a[2];
  else if (a[0] == 1 && a[1] != 1 && a[2] != 1)
    total = (a[0] + a[1]) * a[2];
  else if (a[0] != 1 && a[1] == 1 && a[2] == 1)
    total = a[0] * (a[1] + a[2]);
  else if (a[0] != 1 && a[1] == 1 && a[2] != 1) {
    if (a[0] > a[2])
      total = a[0] * (a[1] + a[2]);
    else
      total = (a[0] * a[1]) * a[2];
  } else if (a[0] != 1 && a[1] != 1 && a[2] == 1)
    total = a[0] * (a[1] + a[2]);
  else
    total = a[0] * a[1] * a[2];
  cout << total;
  return 0;
}
