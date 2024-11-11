#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-6;
struct node {
  int val, step;
};
int vis[3000], ans;
queue<node> Q;
vector<int> v;
void BFS() {
  node cur, nt;
  while (!Q.empty()) {
    cur = Q.front();
    Q.pop();
    if (cur.val == 0) {
      ans = cur.step;
      return;
    }
    for (int i = 0; i < v.size(); i++) {
      int f = cur.val + v[i];
      if (vis[f + 1000] || f < -1000 || f > 1000) continue;
      vis[f + 1000] = 1;
      nt = {f, cur.step + 1};
      Q.push(nt);
    }
  }
}
int main() {
  int n, k, x, ans = -1;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    if (!vis[x - n + 1000]) {
      vis[x - n + 1000] = 1;
      v.push_back(x - n);
      node st = {x - n, 1};
      Q.push(st);
    }
  }
  BFS();
  printf("%d\n", ans);
  return 0;
}
