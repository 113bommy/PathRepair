#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e3 + 10;
class UnionSet {
 public:
  int fa[N];
  void init() { memset((fa), (-1), sizeof(fa)); }
  int treesize(int x) { return -fa[Find(x)]; }
  int Find(int x) {
    int root = x;
    while (fa[root] >= 0) root = fa[root];
    while (x != root) {
      int tmp = fa[x];
      fa[x] = root;
      x = tmp;
    }
    return root;
  }
  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (fa[px] > fa[py]) swap(px, py);
    int sz = fa[px] + fa[py];
    fa[py] = px;
    fa[px] = sz;
  }
} uf;
int a[N];
map<int, int> ms[N];
int main() {
  int n;
  uf.init();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int d;
    cin >> d;
    if (i + d <= n && uf.Find(i) != uf.Find(i + d)) uf.Union(i + d, i);
    if (i - d >= 1 && uf.Find(i) != uf.Find(i - d)) uf.Union(i + d, i);
  }
  for (int i = 1; i <= n; i++) {
    ms[uf.Find(i)][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int p = uf.Find(i);
    if (!ms[p].count(a[i])) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
