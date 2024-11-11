#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100010], tot = 1;
set<int> E[100010];
map<set<int>, vector<int> > M;
inline int read() {
  register int w = 0, X = 0;
  register char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    X = (X << 1) + (X << 3) + (ch ^ 48);
    ch = getchar();
  }
  return w ? -X : X;
}
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= m; i++) {
    register int x = read(), y = read();
    E[x].insert(y), E[y].insert(x);
  }
  for (register int i = 1; i <= n; i++) M[E[i]].push_back(i);
  if (M.size() != 3) {
    puts("-1");
    return 0;
  }
  for (auto it = M.begin(); it != M.end(); it++, tot++) {
    if ((it->first).size() == 0) {
      puts("-1");
      return 0;
    }
    for (auto x : it->second) ans[x] = tot;
  }
  for (register int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
