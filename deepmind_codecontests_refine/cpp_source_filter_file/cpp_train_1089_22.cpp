#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 + 10;
long long nn, hh;
long long solve(long long h, char dir, long long n) {
  if (h == 0) return 1;
  int t = pow(2, h - 1);
  if (n <= t && dir == 'L') {
    return 1 + solve(h - 1, 'R', n);
  } else if (n <= t && dir == 'R') {
    return 2 * t + solve(h - 1, 'R', n);
  } else if (n > t && dir == 'L') {
    return 2 * t + solve(h - 1, 'L', n - t);
  } else if (n > t && dir == 'R') {
    return 1 + solve(h - 1, 'L', n - t);
  }
}
int main() {
  cin >> hh >> nn;
  cout << solve(hh, 'L', nn) - 1;
  return 0;
}
