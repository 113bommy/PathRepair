#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  string col;
  cout << 0 << ' ' << 1 << endl;
  cin >> col;
  auto c = col;
  int lb = 0, ub = 1e9 + 1;
  for (int i = 1; i < n; i++) {
    int m = (lb + ub) >> 1;
    cout << m << ' ' << 1 << endl;
    cin >> col;
    if (col == c) {
      lb = m;
    } else {
      ub = m;
    }
  }
  cout << lb << ' ' << 0 << ' ' << ub << ' ' << 2 << endl;
  return 0;
}
