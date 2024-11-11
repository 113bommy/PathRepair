#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, chst = 0, bi = 0, bck = 0, i, x, cntr = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    if (cntr == 1)
      chst += x;
    else if (cntr == 2)
      bi += x;
    else if (cntr == 3)
      bck += x;
    cntr++;
    if (cntr == 4) cntr = 0;
  }
  if (chst > bi && chst > bck)
    cout << "chest";
  else if (bi > chst && bi > bck)
    cout << "biceps";
  else if (bck > chst && bck > bi)
    cout << "back";
  return 0;
}
