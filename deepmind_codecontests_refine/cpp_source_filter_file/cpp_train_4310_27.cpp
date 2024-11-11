#include <bits/stdc++.h>
using namespace std;
unsigned long long mod = 1000000007;
int main() {
  int nop, k;
  cin >> nop >> k;
  int max_possi = nop * (nop - 1);
  max_possi /= 2;
  if (k >= max_possi)
    cout << "no solution"
         << "\n";
  else {
    int x = 0, y = 0;
    while (nop--) cout << x++ << " " << y++ << "\n";
  }
  return 0;
}
