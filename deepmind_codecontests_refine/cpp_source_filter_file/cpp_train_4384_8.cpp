#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  while (t--) {
    vector<long long> w;
    long long x, h, k, s = 0;
    cin >> x >> h >> k;
    while (x > 1 && h > 1 && k > 0) {
      s += 2 * x + 2 * h - 4;
      x -= 2;
      h -= 2;
      k--;
    }
    cout << s;
    cout << "\n";
  }
}
