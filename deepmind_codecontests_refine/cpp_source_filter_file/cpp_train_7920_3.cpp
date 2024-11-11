#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<int> sg(n, +1);
  for (int i = 1, x; i <= n; ++i) {
    cout << i << "\n";
    fflush(stdout);
    cin >> x;
    if (x < 0) sg[i - 1] = -1;
    if (x == 0) return 0;
  }
  int l = n + 1, r = 1e9, pt = 0, x;
  while (l < r) {
    int md = (l + r) >> 1;
    cout << md << "\n";
    fflush(stdout);
    cin >> x;
    x *= sg[pt];
    pt = (pt + 1) % n;
    if (x == 0) return 0;
    if (x < 0)
      r = md;
    else
      l = md + 1;
  }
  cout << l << "\n";
  fflush(stdout);
  return 0;
}
