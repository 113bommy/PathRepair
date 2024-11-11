#include <bits/stdc++.h>
using namespace std;
int bea[] = {1, 6, 28, 120, 496, 2016, 8128, 32640, 65408};
int main() {
  int n;
  cin >> n;
  for (int i = 8; i > -1; i--) {
    if (bea[i] <= n && n % bea[i] == 0) {
      cout << bea[i];
      break;
    }
  }
  return 0;
}
