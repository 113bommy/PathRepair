#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int f = 0;
  int a[502] = {0,   1,   3,   6,   10,  15,  21,  28,  36,  45,  55,
                66,  78,  91,  105, 120, 136, 153, 171, 190, 210, 231,
                253, 276, 300, 325, 351, 378, 406, 435, 465, 496};
  for (int i = 0; i < 32; i++) {
    if (a[i] == n) {
      cout << "Yes";
      f = 1;
    }
  }
  if (f == 0) cout << "No";
}
