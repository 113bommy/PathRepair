#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, x[5];
  for (i = 0; i < 5; i++) {
    cin >> x[i];
  }
  x[2] /= 2;
  x[3] /= 7;
  x[4] /= 4;
  sort(x, x + 5);
  cout << x[i] << endl;
}
