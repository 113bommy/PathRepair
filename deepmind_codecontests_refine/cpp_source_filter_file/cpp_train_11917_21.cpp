#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int sum = 0;
  int z = 1;
  int a;
  while (1) {
    a = (z * (z + 1)) / 2;
    sum = sum + a;
    if (a == x) {
      cout << z;
      break;
    }
    if (sum > x) {
      cout << z - 1;
      break;
    }
    z++;
  }
}
