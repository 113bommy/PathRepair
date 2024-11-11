#include <bits/stdc++.h>
using namespace std;
string x[1005], y[1005];
int ti[1005];
bool vis[1005];
struct TNode {
  string x, y;
} di[1020];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> ti[i];
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      for (int j = i - 1; j >= 0; j--) {
        if (ti[i] - ti[j] > 0 && ti[i] - ti[j] <= d) {
          if (x[j] == x[i] && y[i] == y[j]) {
            di[ans].x = min(x[i], y[i]);
            di[ans++].y = max(x[i], y[i]);
            for (int k = i + 1; k < n; k++)
              if ((x[k] == x[i] && y[k] == y[i]) ||
                  (x[k] == y[i] && y[k] == x[i]))
                vis[k] = 1;
            break;
          }
        }
      }
    }
  cout << ans << endl;
  for (int i = 0; i < ans; i++) cout << di[i].x << " " << di[i].y << endl;
  return 0;
}
