#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int div = 0;
  for (int i = 1; i <= n; i++) {
    if (x % i == 0 && x / i <= n) {
      div++;
    }
  }
  cout << div;
  return 0;
}
