#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  long long a, b, c, i, j, k;
  cin >> a >> b >> c;
  k = (a + c - b) / 2;
  i = a - k;
  j = c - k;
  if ((a + c - b) % 2 != 0 || i < 0 || j < 0) {
    cout << "Impossible" << endl;
  } else {
    cout << i << " " << j << " "
         << " " << k << endl;
  }
  return 0;
}
