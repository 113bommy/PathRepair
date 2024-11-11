#include <bits/stdc++.h>
using namespace std;
int sol(int a, int b, int c, int r) {
  int total_dist = b - a;
  if (((c - r) <= a) && (a <= c) && ((c - r) <= b) && (b <= c)) return 0;
  if ((c <= a) && (a <= (c + r)) && (c <= b) && (b <= (c + r))) return 0;
  if ((c - r) <= a && (c + r) >= b) return 0;
  if ((c - r) < b && (c - r) > a) {
    if (c + r >= b) {
      return total_dist - (b - (c - r));
    } else {
      return total_dist - (2 * r);
    }
  }
  if ((c + r) < b && (c + r) > a) {
    if (c - r <= a) {
      return total_dist - (c + r - a);
    } else {
      return total_dist - (2 * r);
    }
  }
  return total_dist;
}
int main() {
  int t{};
  cin >> t;
  while (t--) {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }
    cout << sol(a, b, c, r) << "\n";
  }
}
