#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
multiset<int> to[MAXN];
map<int, int> m;
map<int, int> p;
int n, cnt, k;
int x[MAXN], y[MAXN], road[MAXN];
int deg[MAXN];
void dfs(int x) {
  for (multiset<int>::iterator it = to[x].begin(); it != to[x].end();
       it = to[x].begin()) {
    int u = *it;
    to[x].erase(it);
    to[u].erase(to[u].find(x));
    dfs(u);
  }
  road[k++] = x;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) scanf("%d", x + i);
  for (int i = 1; i <= n - 1; ++i) scanf("%d", y + i);
  for (int i = 1; i <= n - 1; ++i) {
    if (m.count(x[i]) == 0) {
      m[x[i]] = cnt;
      p[cnt] = x[i];
      ++cnt;
    }
    if (m.count(y[i]) == 0) {
      m[y[i]] = cnt;
      p[cnt] = y[i];
      ++cnt;
    }
    int a = m[x[i]], b = m[y[i]];
    if (x[i] > y[i]) {
      puts("-1");
      return 0;
    } else {
      to[a].insert(b);
      to[b].insert(a);
      ++deg[a], ++deg[b];
    }
  }
  int countd = 0;
  int s = -1, e = -1;
  for (int i = 0; i <= cnt - 1; ++i) {
    if (deg[i] & 1) {
      ++countd;
      if (s == -1)
        s = i;
      else {
        if (e == -1)
          e = i;
        else {
          puts("-1");
          return 0;
        }
      }
    }
  }
  if (countd == 1) {
    puts("-1");
    return 0;
  }
  if (s == -1) s = 0;
  dfs(s);
  if (k == n)
    for (int i = k - 1; i >= 0; --i) {
      printf("%d ", p[road[i]]);
    }
  else
    puts("-1");
  return 0;
}
