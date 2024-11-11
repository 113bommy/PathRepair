#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int r, b, ctr = 0;
  cin >> r >> b;
  if (r < b) {
    swap(r, b);
  }
  while (b > 0 && r > b) {
    ctr++;
    r--;
    b--;
  }
  cout << ctr << " " << r / 2 << endl;
  return 0;
}
