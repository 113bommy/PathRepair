#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int res = 0;
  if (x % 2 == 0) {
    x = n - x + 1;
  }
  cout << (x - 1) / 2 + 1;
  return 0;
}
