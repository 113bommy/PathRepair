#include <bits/stdc++.h>
using namespace std;
int qnts[21];
int pd[1 << 21];
int v[110000];
int n, m, d;
void up(int mask) {
  int& ret = pd[mask];
  if (ret) return;
  ret = 1;
  for (int i = 0; i < m; i++)
    if (!(1 & (mask >> i))) up(mask + (1 << i));
}
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x;
    while (x--) {
      cin >> y, y--;
      v[y] = i;
    }
  }
  memset(pd, 0, sizeof pd);
  int mask = 0;
  for (int i = 0; i < d; i++) {
    qnts[v[i]]++;
    if (qnts[v[i]] == 1) {
      mask |= (1 << v[i]);
    }
  }
  up(mask);
  for (int i = d; i < n; i++) {
    qnts[v[i - d]]--;
    if (qnts[v[i - d]] == 0) mask -= (1 << v[i - d]);
    qnts[v[i]]++;
    if (qnts[v[i]] == 1) mask |= (1 << v[i]);
    up(mask);
  }
  int ans = m;
  for (int i = 1; i < (1 << m); i++) {
    if (!pd[(1 << m) - i - 1]) ans = min(ans, __builtin_popcount(i));
  }
  cout << ans << endl;
  return 0;
}
