#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n;
  for (int i = 9; i >= 1; i--) {
    if (n % i == 0) {
      d = i;
      break;
    }
  }
  int x = n / d;
  cout << x << endl;
  for (int i = 1; i <= x; i++) {
    cout << d << " ";
  }
  return 0;
}
