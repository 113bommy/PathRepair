#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, a, b, c;
  cin >> n >> a >> b;
  a = a - 1;
  b = b - 1;
  int st = 1, z = 0;
  while (st < n) {
    st *= 2;
    z++;
  }
  c = 1;
  for (i = 1; i < z; i++) {
    c++;
    if (a / c == b / c) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "Final!" << endl;
  return 0;
}
