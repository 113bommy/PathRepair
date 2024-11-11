#include <bits/stdc++.h>
using namespace std;
const long long M = 5e5 + 100;
long long fi(long long s, long long x) {
  if ((s - x) % 2) return 0;
  if (s <= 1) {
    if (s == 1 && x == 1) return 2;
    if (s == 2 && x == 0) return 1;
    if (s == 0 && x == 0) return 1;
    return 0;
  }
  if (s % 2 == 0) {
    return fi(s / 2, x / 2) + fi((s - 2) / 2, x / 2);
  } else {
    return 2 * fi((s - 1) / 2, (x - 1) / 2);
  }
}
int main() {
  ios::sync_with_stdio(false);
  long long x, s, o;
  cin >> s >> x;
  o = fi(s, x);
  if ((0 ^ s) == x) o -= 2;
  cout << o;
  return 0;
}
