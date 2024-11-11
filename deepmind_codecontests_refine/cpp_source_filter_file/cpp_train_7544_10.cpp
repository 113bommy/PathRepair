#include <bits/stdc++.h>
using namespace std;
int n, m, w, h;
set<int> Set[2];
set<int>::iterator iter;
priority_queue<int> qu[2];
int vis[2][200010], point[2][200010];
char s[10];
int main() {
  int i, j, k, l, r, p, a, b;
  long long ans;
  scanf("%d%d%d", &w, &h, &k);
  Set[0].insert(0);
  Set[0].insert(h);
  Set[1].insert(0);
  Set[1].insert(w);
  point[0][h] = 0;
  point[1][w] = 0;
  qu[0].push(h);
  qu[1].push(w);
  for (i = 1; i <= k; i++) {
    scanf("%s%d", s, &p);
    if (s[0] == 'H') {
      iter = Set[0].lower_bound(p);
      r = *iter;
      l = point[0][r];
      vis[0][r - l] = 1;
      qu[0].push(r - p);
      qu[0].push(p - l);
      point[0][r] = p;
      point[0][p] = l;
      Set[0].insert(p);
    } else {
      iter = Set[1].lower_bound(p);
      r = *iter;
      l = point[1][r];
      vis[1][r - l] = 1;
      qu[1].push(r - p);
      qu[1].push(p - l);
      point[1][r] = p;
      point[1][p] = l;
      Set[1].insert(p);
    }
    while (true) {
      a = qu[0].top();
      if (vis[0][a] == 0) break;
      vis[0][a]--;
      qu[0].pop();
    }
    while (true) {
      b = qu[1].top();
      if (vis[1][b] == 0) break;
      vis[1][b]--;
      qu[1].pop();
    }
    ans = (long long)a * (long long)b;
    printf("%I64d\n", ans);
  }
}
