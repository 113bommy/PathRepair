#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0;
  cin >> n;
  while (n) {
    if (n % 8 == 0) x++;
    n /= 8;
  }
  cout << x;
}
