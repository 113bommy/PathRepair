#include <bits/stdc++.h>
using namespace std;
long long solve(long long x) {
  long long sum = 0, i;
  for (i = 1; i <= x; i++) {
    if (i % 2)
      sum += (x + 1) / 2;
    else
      sum += (x / 2);
  }
  return sum;
}
int main() {
  long long i, x, low, high, mid, j, k, l, m, n, ans = 1e6;
  cin >> x;
  if (x == 3) return cout << 5 << endl, 0;
  for (i = 1;; i++) {
    if (solve(i) >= x) break;
  }
  cout << i << endl;
}
