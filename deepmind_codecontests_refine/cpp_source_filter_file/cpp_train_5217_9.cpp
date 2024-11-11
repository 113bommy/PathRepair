#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m = n - 10;
  if (m == 0) {
    cout << 0;
    return 0;
  }
  if (m <= 9) {
    cout << 4;
    return 0;
  }
  if (m == 10) {
    cout << 15;
    return 0;
  }
  if (m == 11) {
    cout << 4;
    return 0;
  }
  cout << 0;
  return 0;
}
