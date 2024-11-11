#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, flag = 0, r;
  cin >> n;
  for (i = 1; i <= 100; i++) {
    r = (i * (i + 1)) / 2;
    if (r == n) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
