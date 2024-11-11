#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, long long> p1, pair<string, long long> p2) {
  if (p1.second > p2.second)
    return true;
  else if (p1.second == p2.second)
    return p1.first < p2.first;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  float l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  cout << setprecision(9);
  cout << fixed;
  if ((d / v) < g)
    cout << l / v;
  else if (d / v < r + g) {
    cout << (l - d) / v + g + r;
  } else {
    int p = (d / v) / (g + r);
    double rem = d / v - p * (g + r);
    if (rem < g)
      cout << l / v;
    else if (rem < r + g) {
      cout << l / v + g + r - rem;
    }
  }
  return 0;
}
