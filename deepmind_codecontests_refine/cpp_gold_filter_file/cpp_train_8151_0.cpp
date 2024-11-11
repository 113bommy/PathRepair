#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return (a < b); }
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int slices = c * d;
  int mili = (k * l) / nl;
  int salt = p / np;
  int ans = std::min({slices, salt, mili}, comp);
  cout << ans / n;
  return 0;
}
