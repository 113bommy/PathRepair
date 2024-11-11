#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int sum = 0;
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) {
    if (2 * 1 < b && 4 * i < c) {
      sum = 7 * i;
    }
  }
  cout << sum;
  return 0;
}
