#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  int total = 0;
  int win = n * m - k;
  if (win > 0) {
    while (win) {
      if (c <= ((n) < (win) ? (n) : (win)) * d) {
        total += c;
        win -= ((n) < (win) ? (n) : (win));
      } else {
        total += ((n) < (win) ? (n) : (win));
        win -= ((n) < (win) ? (n) : (win));
      }
    }
  }
  cout << total << endl;
  return 0;
}
