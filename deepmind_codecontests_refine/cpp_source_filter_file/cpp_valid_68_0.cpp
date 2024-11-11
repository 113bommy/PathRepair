#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i = i + 1) {
    int a;
    cin >> a;
    int n = sqrt(a) + 1;
    if (a >= n * n - n + 1) {
      cout << n << ' ' << n * n + 1 - a << endl;
    } else if (a < n * n - n + 1) {
      cout << -n * n + 2 * n - 1 + a << ' ' << n << endl;
    }
  }
  return 0;
}
