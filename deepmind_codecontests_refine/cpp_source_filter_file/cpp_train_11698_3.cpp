#include <bits/stdc++.h>
using namespace std;
int n, t, x, y, a[3];
int main() {
  cin >> n;
  while (n--) cin >> t >> x >> y, a[t] += x - y;
  cout << (a[1] >= 0 ? "LIVE" : "DEAD");
  cout << (a[2] >= 0 ? "LIVE" : "DEAD");
}
