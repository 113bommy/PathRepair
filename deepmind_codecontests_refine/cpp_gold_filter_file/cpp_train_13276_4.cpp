#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N];
bool flag[N];
int find(int x) {
  int r = x;
  while (fa[r] != r) r = fa[r];
  int i = x, j;
  while (i != r) {
    j = fa[i];
    fa[i] = r;
    i = j;
  }
  return r;
}
int main() {
  int n, m, i, j;
  int x, y, fx, fy;
  int ans;
  ans = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) fa[i] = i;
  while (m--) {
    cin >> x >> y;
    fx = find(x);
    fy = find(y);
    if (fx != fy) {
      fa[fx] = fy;
      flag[fy] |= flag[fx];
    } else
      flag[fx] = flag[fy] = true;
  }
  for (i = 1; i <= n; i++) {
    int tem = find(i);
    if (tem == i && !flag[tem]) ans++;
  }
  cout << ans << endl;
  return 0;
}
