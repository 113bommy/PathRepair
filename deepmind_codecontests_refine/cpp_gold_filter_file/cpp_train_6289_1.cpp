#include <bits/stdc++.h>
using namespace std;
int n, m, a;
int c[100000];
int b[100000];
int main() {
  cin >> n >> m >> a;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(c, c + n, greater<int>());
  sort(b, b + m);
  int ra = 0;
  int rc = 0;
  int temp, ta, tc;
  int low = 0;
  int high = min(m, n) + 1;
  while (high - low > 1) {
    bool passable = true;
    int i = (low + high) / 2;
    temp = a;
    ta = 0;
    tc = 0;
    for (int j = 0; j < i && passable; j++) {
      int cb = b[i - j - 1];
      if (c[j] + temp < cb) passable = false;
      ta++;
      tc += min(c[j], cb);
      if (c[j] < cb) temp -= cb - c[j];
    }
    if (temp > 0) tc -= min(tc, temp);
    if (passable && ta > ra) {
      ra = ta;
      rc = tc;
    }
    if (passable)
      low = i;
    else
      high = i;
  }
  cout << low << " " << rc << endl;
  return 0;
}
