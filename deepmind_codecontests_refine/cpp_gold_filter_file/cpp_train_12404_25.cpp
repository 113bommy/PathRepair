#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;
int n, m, r;
int main() {
  cin >> n >> m >> r;
  int mi = 1e9, ma = -1, x;
  for (int i = 1; i <= (n); i++) cin >> x, mi = min(mi, x);
  for (int i = 1; i <= (m); i++) cin >> x, ma = max(ma, x);
  int r1 = r;
  int p = r / mi;
  r = r - p * mi;
  r += p * ma;
  cout << max(r, r1) << endl;
  return 0;
}
