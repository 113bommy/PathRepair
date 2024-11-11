#include <bits/stdc++.h>
using namespace std;
const long long mx = 2e6 + 10;
int mark[mx];
int main() {
  int n, ma;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    if (c > ma) ma = c;
    for (int j = c; j < mx; j += c) mark[j] = 1;
  }
  bool t = 1;
  for (int i = 1; i < 2 * ma + 1; i++) {
    if (mark[i] == 0) {
      cout << i;
      t = 0;
      break;
    }
  }
  if (t) cout << -1;
  return 0;
}
