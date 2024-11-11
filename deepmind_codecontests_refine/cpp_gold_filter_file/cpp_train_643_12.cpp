#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const long long LIM = 2e5 + 5;
const long long MOD = 1e9 + 7;
const long long inf = 1e10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> r(4, 0);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x = x - a;
    y = y - b;
    if (x >= 1) r[0]++;
    if (y >= 1) r[1]++;
    if (x <= (-1)) r[2]++;
    if (y <= (-1)) r[3]++;
  }
  int maxsofar = 0;
  for (int i = 0; i < 4; i++) {
    maxsofar = max(r[i], maxsofar);
  }
  cout << maxsofar << endl;
  int j;
  for (int i = 0; i < 4; i++) {
    if (maxsofar == r[i]) j = i;
  }
  switch (j) {
    case 0:
      cout << a + 1 << " " << b;
      break;
    case 1:
      cout << a << " " << b + 1;
      break;
    case 2:
      cout << a - 1 << " " << b;
      break;
    case 3:
      cout << a << " " << b - 1;
      break;
  }
}
