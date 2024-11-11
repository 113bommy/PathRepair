#include <bits/stdc++.h>
using namespace std;
using big = long long;
const int N = 502000;
int n;
int a[N * 2];
int ans[N * 2];
bool used[N * 2];
int deg[1 << 20];
int head[1 << 20], nxt[N * 4], v[N * 4], w[N * 4];
int t = 1;
int path[N * 2];
int top = 0;
bool vis[1 << 20];
inline int id(int x, int y) { return x * 2 - 1 + y; }
void dfs(int x, int prev) {
  while (head[x]) {
    auto i = head[x];
    head[x] = nxt[i];
    if (!used[std::abs(w[i])]) {
      used[std::abs(w[i])] = true;
      dfs(v[i], w[i]);
    }
  }
  if (prev != -1) {
    path[++top] = prev;
  }
}
void ff(int x) {
  vis[x] = true;
  for (int i = head[x]; i; i = nxt[i]) {
    if (!vis[v[i]]) {
      ff(v[i]);
    }
  }
}
void add(int x, int y, int z) {
  nxt[++t] = head[x];
  v[t] = y;
  w[t] = z;
  head[x] = t;
  nxt[++t] = head[y];
  v[t] = x;
  w[t] = -z;
  head[y] = t;
}
bool ck(int x, bool output) {
  int mask = (1 << x) - 1;
  t = 1;
  for (int i = 0; i <= mask; ++i) {
    deg[i] = 0;
    head[i] = 0;
    vis[i] = false;
  }
  for (int i = 1; i <= n; ++i) {
    int from = a[id(i, 0)] & mask;
    int to = a[id(i, 1)] & mask;
    add(from, to, i);
    used[i] = false;
    ++deg[from];
    ++deg[to];
  }
  for (int i = 0; i <= mask; ++i) {
    if (deg[i] & 1) {
      return false;
    }
  }
  for (int i = 0; i <= mask; ++i) {
    if (head[i] && !vis[i]) {
      ff(i);
      break;
    }
  }
  for (int i = 0; i <= mask; ++i) {
    if (head[i] && !vis[i]) {
      return false;
    }
  }
  if (!output) {
    return true;
  }
  top = 0;
  for (int i = 0; i <= mask; ++i) {
    if (head[i]) {
      dfs(i, -1);
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      return false;
    }
  }
  int top2 = 0;
  for (int i = 1; i <= top; ++i) {
    int e = path[i];
    if (path[i] < 0) {
      ans[++top2] = id(-e, 0);
      ans[++top2] = id(-e, 1);
    } else {
      ans[++top2] = id(e, 1);
      ans[++top2] = id(e, 0);
    }
  }
  return true;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i * 2 - 1] >> a[i * 2];
  }
  int l = 0, r = 20;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ck(mid, false)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  ck(r, true);
  cout << r << "\n";
  for (int i = 1; i <= n * 2; ++i) {
    cout << ans[i] << " ";
  }
}
