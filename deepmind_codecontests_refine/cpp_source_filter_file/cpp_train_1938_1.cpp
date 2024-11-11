#include <bits/stdc++.h>
using namespace std;
int main() {
  int R, d, n;
  int xi, yi, ri, count = 0;
  int pyth;
  cin >> R >> d;
  int aux = R - d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> xi >> yi >> ri;
    pyth = (xi * xi) + (yi * yi);
    pyth = sqrt(pyth);
    if ((pyth >= (aux + ri)) && ((pyth + ri) <= R)) {
      count++;
    }
  }
  cout << count;
  return 0;
}
