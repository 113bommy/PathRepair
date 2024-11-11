#include <bits/stdc++.h>
using namespace std;
struct point {
  int v, d, p, nul;
} a[4005];
bool vis[4005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v >> a[i].d >> a[i].p;
    a[i].nul = i;
  }
  queue<point> q;
  q.push(a[1]);
  memset(vis, 0, sizeof(vis));
  vis[1] = 1;
  while (true) {
    point pos = q.back();
    for (int i = pos.nul + 1; i <= n; i++) {
      if (pos.v <= 0) break;
      if (!vis[i]) {
        a[i].p -= pos.v;
        pos.v--;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[i].p < 0 && !vis[i]) {
        vis[i] = 1;
        for (int j = i + 1; j <= n; j++) {
          if (!vis[j]) a[j].p -= a[i].d;
        }
      }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        q.push(a[i]);
        vis[i] = 1;
        flag = true;
        break;
      }
    }
    if (!flag) break;
  }
  cout << q.size() << endl;
  cout << q.front().nul;
  q.pop();
  while (!q.empty()) {
    cout << ' ' << q.front().nul;
    q.pop();
  }
  cout << endl;
}
