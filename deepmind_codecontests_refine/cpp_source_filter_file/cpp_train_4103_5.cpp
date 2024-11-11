#include <bits/stdc++.h>
using namespace std;
int mn[1111];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    mn[i] = 1e9;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    mn[i] = min(mn[i], y);
  }
  int s = 0;
  for (int i = 0; i < m; i++) {
    s += mn[i];
  }
  cout << min(s, k);
  return 0;
}
