#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, m, mx, mn, d;
  while (cin >> n >> m) {
    mn = min(n, m);
    mx = max(n, m);
    cout << (mx - 1) << mn << endl;
  }
  return 0;
}
