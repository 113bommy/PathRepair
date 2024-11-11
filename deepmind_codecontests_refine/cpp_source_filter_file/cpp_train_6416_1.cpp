#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int x = n % 10;
  n = n / 10;
  int z = n % 10;
  n = n / 10;
  if (z != 0) {
    if (x < 5) {
      z = z;
    } else if (x > 5) {
      z = z + 1;
    }
    if (x == 5) {
      z = z;
    }
  }
  n = n * 10 + z;
  n = n * 10;
  cout << n;
}
