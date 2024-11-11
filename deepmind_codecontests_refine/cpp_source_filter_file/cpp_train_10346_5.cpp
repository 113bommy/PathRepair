#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int c = 0, d = -100000000;
  while (n--) {
    int f, t;
    cin >> f >> t;
    if (t > k) {
      c = f - (t - k);
    } else {
      c = f;
    }
    d = max(c, d);
  }
  cout << d;
}
