#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
struct UnionFind {
  int fa[55];
  void inline init() { memset(fa, -1, sizeof(fa)); }
  UnionFind() { init(); }
  int inline root(int x) { return fa[x] < 0 ? x : fa[x] = root(fa[x]); }
  bool inline conn(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return 0;
    if (fa[a] < fa[b]) swap(a, b);
    return fa[b] += fa[a], fa[a] = b, 1;
  }
} uf;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
char s[55][55];
vector<int> ls[55];
int rr[55];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (n); ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (n); ++j)
      if (s[i][j] == 'A') uf.conn(i, j);
  for (int i = 1; i <= (n); ++i)
    for (int j = 1; j <= (n); ++j)
      if (s[i][j] == 'X' && uf.root(i) == uf.root(j)) return puts("-1"), 0;
  int $b = 0;
  for (int i = 1; i <= (n); ++i)
    if (uf.root(i) == i) rr[i] = ++$b;
  for (int i = 1; i <= (n); ++i) ls[rr[uf.root(i)]].push_back(i);
  sort(ls + 1, ls + $b + 1, [&](const vector<int> &a, const vector<int> &b) {
    return ((int)(a).size()) > ((int)(b).size());
  });
  int res = 0;
  if (((int)(ls[$b]).size()) >= 2) res = 0;
  int ans = Inf;
  while (((int)(ls[$b]).size()) == 1) ++res, --$b;
  if (!$b) return printf("%d\n", res - 1), 0;
  for (int $ = 0; $ < (21); ++$) {
    shuffle(ls + 1, ls + $b + 1, rng);
    vector<vector<int> > grs;
    int egs = res;
    for (int i = 1; i <= ($b); ++i) {
      bool $$ = 0;
      for (int $i = 0; $i < (((int)(grs).size())); ++$i) {
        bool can = 1;
        for (int j = 0; j < (((int)(ls[i]).size())); ++j) {
          int ff = ls[i][j];
          for (int $j = 0; $j < (((int)(grs[$i]).size())); ++$j) {
            int nid = grs[$i][$j];
            if (s[ff][nid] == 'X') can = 0;
          }
        }
        if (can) {
          $$ = 1;
          for (int j = 0; j < (((int)(ls[i]).size())); ++j) {
            int ff = ls[i][j];
            grs[$i].push_back(ff);
          }
          break;
        }
      }
      if (!$$) grs.push_back(ls[i]);
    }
    egs += ((int)(grs).size()) - 1;
    for (int i = 0; i < (((int)(grs).size())); ++i)
      egs += ((int)(grs[i]).size());
    ans = min(ans, egs);
  }
  printf("%d\n", ans);
  return 0;
}
