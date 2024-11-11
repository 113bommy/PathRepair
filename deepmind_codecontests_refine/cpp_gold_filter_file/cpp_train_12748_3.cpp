#include <bits/stdc++.h>
using namespace std;
int n, x = 1;
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    x = (x + i) % n;
    if (x == 0) {
      x = n;
    }
    cout << x << " ";
  }
  return 0;
}
