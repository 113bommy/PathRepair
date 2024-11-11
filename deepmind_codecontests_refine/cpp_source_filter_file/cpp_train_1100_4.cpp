#include <bits/stdc++.h>
using namespace std;
int cnt, n, root;
int head[200005], vet[200005 * 2], Next[200005 * 2], d[200005];
void add(int x, int y) {
  cnt++;
  Next[cnt] = head[x];
  head[x] = cnt;
  vet[cnt] = y;
}
int dfs(int x, int fa) {
  set<int> s;
  d[x] = d[fa] + 1;
  for (int i = head[x]; i; i = Next[i]) {
    int v = vet[i];
    if (v == fa) continue;
    int t = dfs(v, x);
    if (t == -1) {
      return -1;
    }
    s.insert(t + 1);
  }
  if (s.size() == 0) {
    return 0;
  } else if (s.size() == 1) {
    return *s.begin();
  } else if (s.size() == 2 && !fa) {
    return *s.begin() + *s.end();
  }
  root = x;
  return -1;
}
int main() {
  cin >> n;
  int x, y;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  int ans = dfs(1, 0);
  if (ans == -1 && root) {
    ans = dfs(root, 0);
  }
  while (!(ans & 1)) {
    ans >>= 1;
  }
  cout << ans << endl;
  return 0;
}
