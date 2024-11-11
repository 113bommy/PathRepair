#include <bits/stdc++.h>
using namespace std;
struct poi {
  int x, y;
  poi(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
} all[6000];
int tmp[6000], ans[6000];
int res = 0;
int top = 0;
int dis(int x, int y) { return x * x + y * y; }
inline bool cmp(const poi& a, const poi& b) {
  return dis(a.x, a.y) > dis(b.x, b.y);
}
int n, r;
void dfs(int sum, int d, int p) {
  if (d == n + 1) {
    if (res < sum) {
      res = sum;
      for (int i = 1; i <= n; i++) ans[i] = tmp[i];
    }
    return;
  }
  for (int i = p; i <= top; i++) {
    int s = 0;
    for (int j = 1; j <= d - 1; j++)
      s += dis(all[i].x - all[tmp[j]].x, all[i].y - all[tmp[j]].y);
    tmp[d] = i;
    dfs(sum + s, d + 1, i);
  }
}
int main() {
  cin >> n >> r;
  for (int i = -r; i <= r; i++)
    for (int j = -r; j <= r; j++)
      if (dis(i, j) <= r * r) all[++top] = poi(i, j);
  sort(all + 1, all + 1 + top, cmp);
  top = min(top, 20);
  dfs(0, 1, 1);
  cout << res << endl;
  for (int i = 1; i <= n; i++) printf("%d %d\n", all[ans[i]].x, all[ans[i]].y);
}
