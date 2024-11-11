#include <bits/stdc++.h>
using namespace std;
int nextPerfectSquare(int N) {
  int nextN = floor(sqrt(N)) + 1;
  return nextN * nextN;
}
int main() {
  long long t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    long long x, y;
    if (floor(sqrt(k * 1.0)) == ceil(sqrt(k * 1.0))) {
      x = sqrt(k);
      y = 1;
    } else {
      long long a = nextPerfectSquare(k);
      long long b = sqrt(a);
      a = a - (b - 1);
      if (k < a) {
        x = b - (a - k);
        y = b;
      } else {
        x = b;
        y = x - (k - a);
      }
    }
    cout << x << " " << y << endl;
  }
}
