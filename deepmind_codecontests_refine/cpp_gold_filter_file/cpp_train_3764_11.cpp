#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x[4];
  long long a, b, c;
  for (int i = 0; i < 4; i++) {
    cin >> x[i];
  }
  sort(x, x + 4);
  a = x[3] - x[0];
  b = x[3] - x[1];
  c = x[3] - x[2];
  cout << a << " " << b << " " << c << endl;
  return 0;
}
