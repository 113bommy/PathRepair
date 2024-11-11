#include <bits/stdc++.h>
using namespace std;
int n;
bool check(long long x, long long y, long long x1, long long y1, long long x2,
           long long y2) {
  long long L1 = (y - y1) * (x1 - x2), L2 = (y1 - y2) * (x - x1);
  if (L1 == L2)
    return 1;
  else
    return 0;
}
long long x[100100], y[100100];
bool yes, vis[100100];
int main() {
  long long x1, y1, x2, y2;
  cin >> n;
  if (n <= 3) {
    cout << "YES";
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  yes = 0;
  for (int k = 1; k <= 3; k++) {
    if (k == 1)
      x1 = x[1], x2 = x[2], y1 = y[1], y2 = y[2];
    else if (k == 2)
      x1 = x[1], x2 = x[3], y1 = y[1], y2 = y[3];
    else if (k == 3)
      x1 = x[2], x2 = x[3], y1 = y[2], y2 = y[3];
    memset(vis, 0, sizeof(vis));
    int cnt = n;
    for (int i = 1; i <= n; i++)
      if (check(x[i], y[i], x1, y1, x2, y2)) vis[i] = 1, cnt--;
    if (cnt <= 1) {
      yes = 0;
      break;
    } else {
      for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
          x1 = x[i], y1 = y[i];
          for (int j = i + 1; j <= n; j++)
            if (!vis[j]) x2 = x[j], y2 = y[j];
          break;
        }
      }
      for (int i = 1; i <= n; i++) {
        if (!vis[i] && check(x[i], y[i], x1, y1, x2, y2)) cnt--;
      }
      if (cnt == 0) {
        yes = 1;
        break;
      }
    }
  }
  if (yes)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
