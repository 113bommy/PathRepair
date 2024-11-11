#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  int x, y;
  int cntr = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i > 0) {
      if ((x - y) <= c) {
        cntr++;
      } else {
        cntr = 1;
      }
    }
    y = x;
  }
  if (n == 1) cntr = 1;
  cout << cntr << endl;
  return 0;
}
