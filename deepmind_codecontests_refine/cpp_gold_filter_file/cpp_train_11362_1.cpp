#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int neg = 1, num = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') neg = -1;
  for (; isdigit(c); c = getchar()) num = (num << 1) + (num << 3) + c - '0';
  return neg * num;
}
int n, T, cnt, d[2000010];
vector<int> g[2000010];
char s[2000010];
inline void Link(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
  d[u]++;
  d[v]++;
}
inline void Solve() {
  n = cnt = read();
  for (int i = 1; i <= 4 * n; i++) g[i].clear(), d[i] = 0;
  for (int i = 1, u, v; i <= n - 1; i++) u = read(), v = read(), Link(u, v);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] == 'W')
      Link(cnt + 1, i), Link(cnt + 1, cnt + 2), Link(cnt + 1, cnt + 3),
          cnt += 3;
  n = cnt;
  int tot = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] >= 4) {
      cout << "White\n";
      return;
    }
  for (int u = 1; u <= n; u++) {
    if (d[u] < 3) continue;
    int sum = 0;
    tot++;
    for (auto v : g[u]) sum += (d[v] == 1);
    if (sum <= 1) {
      cout << "White\n";
      return;
    }
  }
  if (tot < 2)
    cout << "Draw\n";
  else {
    if (n & 1)
      cout << "White\n";
    else
      cout << "Draw\n";
  }
}
signed main() {
  T = read();
  while (T--) Solve();
  return 0;
}
