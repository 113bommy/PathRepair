#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int l, r, d = LONG_MAX;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    d = min(d, abs(l - r) + 1);
  }
  cout << d << endl;
  for (int i = 0; i < n; i++) cout << i % d << " ";
  return 0;
}
