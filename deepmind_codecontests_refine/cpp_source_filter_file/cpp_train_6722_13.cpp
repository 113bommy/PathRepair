#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b, d = INT_MAX;
  int fa, fb;
  for (int a = 1; a <= n / 2; a++) {
    if (n % a == 0) {
      b = n / a;
      if (b - a < d && b - a >= 0) {
        d = b - a;
        fa = a;
        fb = b;
      }
    }
  }
  cout << fa << " " << fb;
  return 0;
}
