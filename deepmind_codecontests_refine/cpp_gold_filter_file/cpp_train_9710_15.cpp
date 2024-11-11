#include <bits/stdc++.h>
using namespace std;
int a[2005] = {0}, b[2005] = {0};
struct node {
  int x, y;
  bool operator<(const node& t) const { return x < t.x; }
};
node c[2005];
int ans[2000005] = {0};
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i].x >> c[i].y;
  }
  sort(c, c + m);
  for (int i = 0; i < n; i++) {
    int maxy = 0;
    for (int j = m - 1; j >= 0 && c[j].x >= a[i]; j--) {
      maxy = max(maxy, c[j].y);
      if (maxy >= b[i]) {
        ans[c[j].x - a[i]] = max(ans[c[j].x - a[i]], maxy - b[i] + 1);
      }
    }
  }
  int res = 3e6;
  for (int i = 2000000; i >= 0; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
    res = min(res, i + ans[i]);
  }
  cout << res << endl;
  return 0;
}
