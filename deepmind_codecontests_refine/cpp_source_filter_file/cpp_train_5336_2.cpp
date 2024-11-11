#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    int a = 0;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        a = i;
        break;
      }
    }
    if (a == 0)
      cout << 1 << " " << n - 1 << endl;
    else
      cout << a << " " << n - a << endl;
  }
  return 0;
}
