#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 2e5 + 10;
int T, n, a[maxn], ans[maxn];
vector<int> v1[maxn], v2[maxn];
queue<int> q;
inline void work() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0, len = v2[u].size(); i < len; ++i) {
      int v = v2[u][i];
      if (!ans[v] && !((a[v] ^ a[u]) % 2)) ans[v] = ans[u] + 1, q.push(v);
    }
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), ans[i] = 0;
  for (int i = 1; i <= n; ++i) {
    if (i + a[i] <= n) {
      v1[i].push_back(i + a[i]);
      v2[i + a[i]].push_back(i);
      if ((a[i + a[i]] ^ a[i]) & 1) ans[i] = 1, q.push(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i - a[i] >= 1) {
      v1[i].push_back(i - a[i]);
      v2[i - a[i]].push_back(i);
      if ((a[i - a[i]] ^ a[i]) & 1) ans[i] = 1, q.push(i);
    }
  }
  work();
  for (int i = 1; i <= n; i++) {
    if (!ans[i])
      printf("%d ", -1);
    else
      printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}
