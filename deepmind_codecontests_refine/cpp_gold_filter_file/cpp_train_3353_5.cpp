#include <bits/stdc++.h>
const int maxn = 300;
using namespace std;
int rd() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
int n, in[maxn], out[maxn], to[maxn], cnt;
bool ct[maxn], ok[maxn];
vector<int> G[maxn];
queue<int> q;
int pcnt[8] = {0, 1, 1, 2, 1, 2, 2, 3};
int main() {
  n = rd();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 3; j++) in[i] |= rd() << (3 - j);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) out[i] |= rd() << (3 - j);
    out[i] &= in[i];
  }
  q.push(1);
  ok[1] = true;
  while (true) {
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      to[ct[u] ? out[u] : in[u]] = u;
      for (int i = 1; i <= n; i++) {
        if (!ok[i] && in[i] == (ct[u] ? out[u] : in[u])) {
          ok[i] = true;
          G[u].push_back(i);
          cnt++;
          q.push(i);
          ct[i] = true;
        }
      }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (!ok[i] && pcnt[in[i]] == 2) {
        int x = in[i] & (-in[i]), y = in[i] - x;
        if (to[x] && to[y]) {
          G[to[x]].push_back(i);
          G[to[y]].push_back(i);
          cnt += 2;
          ok[i] = true;
          q.push(i);
          flag = true;
          break;
        }
      }
    }
    if (!flag) break;
  }
  for (int i = 1; i <= n; i++)
    if (!ok[i]) {
      puts("Impossible");
      return 0;
    }
  puts("Possible");
  for (int i = 1; i <= n; i++) printf("%d ", ct[i]);
  puts("");
  printf("%d\n", cnt);
  for (int u = 1; u <= n; u++)
    for (int v : G[u]) printf("%d %d\n", u, v);
  return 0;
}
