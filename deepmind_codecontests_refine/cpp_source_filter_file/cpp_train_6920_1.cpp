#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n, sum = 0;
  cin >> x >> n;
  if (x * 2 < n) {
    cout << x << endl;
  } else {
    sum = (x + n) / 3;
    if (x == 0 || n == 0) {
      sum = 0;
    }
    if (n < x) {
      sum = n;
    }
    cout << sum << endl;
  }
}
