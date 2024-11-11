#include <bits/stdc++.h>
using namespace std;
int n, x = 1;
void updatex() {
  if (x % 2 == 0)
    x += (x + 1);
  else
    x += (x + 2);
}
int main() {
  cin >> n;
  while (x <= n) {
    if (n == x or n == x + 1) {
      cout << 1;
      return 0;
    }
    updatex();
  }
  cout << 0;
  return 0;
}
