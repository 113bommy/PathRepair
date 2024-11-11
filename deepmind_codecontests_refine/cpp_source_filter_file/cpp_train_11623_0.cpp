#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, vm, flag = 0;
  cin >> v1 >> v2 >> v3 >> vm;
  int smallh = v3 * 2, medh, largeh;
  if (vm > smallh) flag = 1;
  if (2 * vm < v3) flag = 1;
  if (vm > v2 || vm > v1) flag = 1;
  if (vm > v3)
    smallh = vm;
  else
    smallh = v3;
  if (vm * 2 >= v2)
    medh = vm * 2 + 1;
  else
    medh = v2;
  if (medh == smallh) {
    if (medh + 1 <= 2 * v2)
      medh++;
    else
      flag = 1;
  }
  if (vm * 2 >= v1)
    largeh = vm * 2 + 1;
  else
    largeh = v1;
  if (medh == largeh) {
    if (largeh + 1 <= 2 * v1)
      largeh++;
    else
      flag = 1;
  }
  if (flag == 0) {
    cout << largeh << endl << medh << endl << smallh;
  } else {
    cout << -1;
  }
}
