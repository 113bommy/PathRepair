#include <bits/stdc++.h>
using namespace std;
bool w[40];
inline bool F(int x) {
  cout << x << endl;
  fflush(stdout);
  return cin >> x, x;
}
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int t = F(1);
    if (!t) return 0;
    if (t == -1) w[i] = 1;
  }
  int t = 0, l = 1, r = m;
  while (l <= r) {
    t = t % n + 1;
    int mid = (l + r) >> 1, x = F(mid);
    if (!x) return 0;
    if (w[t]) x = -x;
    if (x == -1)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}
