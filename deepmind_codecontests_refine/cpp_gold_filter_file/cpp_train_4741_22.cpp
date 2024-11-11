#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int main() {
  int n;
  cin >> n;
  if (n < 3) {
    if (n == 1) {
      cout << 1;
      return 0;
    }
    if (n == 2) {
      cout << 1;
      return 0;
    }
  }
  int x = (2 * n) / 3;
  if (n % 3 == 1) {
    x++;
  }
  cout << x;
  return 0;
}
