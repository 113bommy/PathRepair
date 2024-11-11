#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, b = 0, s = 0, i, c = 0, m;
  cin >> k;
  b = k % 2;
  if (b == 1) {
    c++;
    k = k - 3;
    s++;
  }
  c = c + k / 2;
  cout << c;
  for (i = 0; i = k; k = k - 2) {
    cout << "2 ";
    if (k == 0) {
      break;
    }
  }
  if (s == 1) {
    cout << "3";
  }
  return 0;
}
