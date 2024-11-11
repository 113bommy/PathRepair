#include <bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 6;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int lo = 0, hi = 2000;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    int load = mid * b;
    if (load / (a - b) >= c)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo;
  return 0;
}
