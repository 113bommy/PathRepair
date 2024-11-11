#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
int N;
int a[500100], b[500100];
tuple<bool, int, int> solve(int d) {
  int xmn = -1e9, ymn = -1e9, dmn = -1e9;
  int xmx = 1e9, ymx = 1e9, dmx = 1e9;
  for (int i = 0; i < N; i++) {
    xmn = max(xmn, a[i] - d);
    ymn = max(ymn, b[i] - d);
    dmn = max(dmn, b[i] - a[i] - d);
    xmx = min(xmx, a[i] + d);
    ymx = min(ymx, b[i] + d);
    dmx = min(dmx, b[i] - a[i] + d);
  }
  if (xmn > xmx || ymn > ymx || dmn > dmx) return {0, 0, 0};
  if (dmn > ymx - xmn) return {0, 0, 0};
  if (dmx < ymn - xmx) return {0, 0, 0};
  int x = xmx, y = ymx;
  if (dmn > ymx - xmx)
    x = y - dmn;
  else if (dmx < dmx - xmx)
    y = x + dmx;
  if (x == 0 && y == 0) return {0, 0, 0};
  return {1, x, y};
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (char c : s) {
      if (c == 'B')
        a[i]++;
      else
        b[i]++;
    }
  }
  int l = 0, r = 1e6;
  int xx = 0, yy = 0;
  while (l < r) {
    int m = (l + r) / 2;
    auto [good, x, y] = solve(m);
    if (good) {
      xx = x, yy = y;
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << '\n';
  while (xx-- > 0) cout << 'B';
  while (yy-- > 0) cout << 'N';
  cout << '\n';
  return 0;
}
