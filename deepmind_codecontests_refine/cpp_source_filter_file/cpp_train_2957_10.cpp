#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, p[N];
set<int> s[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    s[u].insert(v);
    s[v].insert(u);
  }
  for (int op = 0; op < 300; op++) {
    for (int i = 1; i <= n; i++) p[i] = i;
    random_shuffle(p + 1, p + n + 1);
    bool ok = 1;
    for (int i = 1; ok && i <= m; i++)
      ok &= s[p[i]].find(p[i % n + 1]) == s[p[i]].end();
    if (!ok) continue;
    for (int i = 1; i <= m; i++) printf("%d %d\n", p[i], p[i % m + 1]);
    return 0;
  }
  puts("-1");
}
