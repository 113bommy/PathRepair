#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int n;
long long l = -1000 * 1000 * 1000 * 2, r = 1000 * 1000 * 2;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string c, h;
    long long x;
    cin >> c >> x >> h;
    if (c == ">=") h == "Y" ? l = max(l, x - 1) : r = min(r, x);
    if (c == ">") h == "Y" ? l = max(l, x) : r = min(r, x + 1);
    if (c == "<=") h == "Y" ? r = min(r, x + 1) : l = max(l, x);
    if (c == "<") h == "Y" ? r = min(r, x) : l = max(l, x - 1);
  }
  if (l + 2 <= r)
    cout << l + 1 << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}
