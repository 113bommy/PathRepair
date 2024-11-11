#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535;
bool isMask(int a, int b) {
  string mask;
  while (a) {
    if (a % 10 == 7 || a % 10 == 4) mask.push_back(a % 10 + '0');
    a /= 10;
  }
  int res = 0;
  for (int i = mask.size() - 1; i >= 0; i--) {
    res = res * 10 + mask[i] - '0';
  }
  return res == b;
}
int main() {
  int a, b;
  cin >> a >> b;
  if (b > a) {
    cout << b << endl;
    return 0;
  }
  int res = 0;
  for (int i = a + 1; i <= 200001; i++) {
    if (isMask(i, b)) {
      res = i;
      break;
    }
  }
  cout << res << endl;
  return 0;
}
