#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int max;
    if (a >= b && a >= c) {
      max = a;
    }
    if (b >= a && b >= c) max = b;
    if (c >= a && c >= b) max = c;
    int sum = 0;
    sum = max - a + max - b + max - c;
    if (sum > n) {
      cout << "NO" << endl;
    } else if (sum == n) {
      cout << "YES" << endl;
    } else {
      n = n - sum;
      if (n % 3 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
