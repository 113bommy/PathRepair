#include <bits/stdc++.h>
using namespace std;
int main() {
  array<int, 4> asd;
  for (int i = 0; i < 4; i++) {
    cin >> asd[i];
  }
  int tol, ig;
  cin >> tol >> ig;
  if (tol == 0 && ig == 0) {
    cout << 1;
    return 0;
  }
  if (tol == ig) {
    cout << 0;
    return 0;
  }
  sort(asd.begin(), asd.end());
  if (asd[0] - tol > 0 && asd[0] < ig)
    cout << asd[0] - tol;
  else if (asd[0] - tol > 0 && asd[0] >= ig)
    cout << ig - tol + 1;
  else
    cout << 0;
  return 0;
}
