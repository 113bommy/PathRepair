#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, p[maxn], old[maxn], rt, vis[maxn];
void gen_root() {
  for (int i = 0; i < n; i++) {
    if (p[i] == i) {
      rt = i;
      return;
    }
  }
  int cur = 0;
  while (!vis[cur]) {
    vis[cur] = true;
    cur = p[cur];
  }
  p[cur] = cur;
  rt = cur;
}
void connect() {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    if (p[i] == i) {
      p[i] = rt;
      vis[i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int cur = 0;
      while (vis[cur] == 0) {
        vis[cur] = 100 + i;
        cur = p[cur];
      }
      if (vis[cur] == 100 + i) {
        p[cur] = rt;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  memcpy(old, p, sizeof(old));
  gen_root();
  connect();
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != old[i]) {
      ++res;
    }
  }
  cout << res << '\n';
  for (int i = 0; i < n; i++) {
    cout << p[i] + 1;
    if (i + 1 < n) {
      cout << ' ';
    }
  }
  cout << '\n';
  return 0;
}
