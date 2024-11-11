#include <bits/stdc++.h>
const unsigned long long inf = 1LL << 61;
const double eps = 1e-5;
using namespace std;
bool cmp(int a, int b) { return a > b; }
int a[100000 + 10];
int main() {
  int n;
  while (cin >> n) {
    a[3] = 1;
    a[4] = 4;
    a[5] = 9;
    if (n <= 5)
      cout << a[n] << endl;
    else {
      for (int i = 4; i <= n; i++) {
        a[i] = a[i - 1] + 2 * (i - 2) - 1;
      }
      cout << a[n] << endl;
    }
  }
  return 0;
}
