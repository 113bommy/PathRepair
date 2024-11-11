#include <bits/stdc++.h>
using namespace std;
int n;
int deg[10000005];
int orx[10000005];
struct Ans {
  int u, v;
} ans[5000005];
queue<int> que;
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> deg[i] >> orx[i];
    }
    for (int i = 0; i < n; i++)
      if (deg[i] == 1) que.push(i);
    int x, y;
    int cnt = 0;
    while (!que.empty()) {
      x = que.front();
      que.pop();
      if (deg[x] != 1) continue;
      deg[x]--;
      y = orx[x];
      ans[cnt].u = x;
      ans[cnt++].v = y;
      deg[y]--;
      orx[y] ^= x;
      if (deg[y] == 1) que.push(y);
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << ans[i].u << ' ' << ans[i].v << endl;
  }
  return 0;
}
