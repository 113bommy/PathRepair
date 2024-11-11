#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000006;
int n, m;
struct pnt {
  int val, x, y;
  bool operator<(pnt b) const { return val < b.val; }
  int co() { return (x - 1) * m + y; }
};
vector<pnt> a;
map<pair<int, int>, int> b;
int mx[mxn];
int my[mxn];
map<pair<int, int>, int> ans;
class DSU {
  int p[mxn + 1];

 public:
  void clear(int n) { iota(p, p + n + 1, 0); }
  int root(int x) { return p[x] == x ? p[x] : p[x] = root(p[x]); }
  bool merge(int a, int b) {
    if ((a = root(a)) != (b = root(b))) p[a] = b;
    return a != b;
  }
} Q;
int tid[mxn];
void EXEC() {
  cin >> n >> m;
  a.reserve(n * m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int t;
      scanf("%d", &t);
      a.push_back({t, i, j});
      b[{i, j}] = t;
    }
  Q.clear(n * m);
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i)
    if (!i || a[i].val != a[i - 1].val) {
      int r = i;
      for (int j = i; j < a.size() && a[j].val == a[i].val; ++j) r = j;
      sort(a.begin() + i, a.begin() + r + 1,
           [](pnt a, pnt b) { return a.x < b.x; });
      for (int j = i; j < r; ++j)
        if (a[j].x == a[j + 1].x) Q.merge(a[j].co(), a[j + 1].co());
      sort(a.begin() + i, a.begin() + r + 1,
           [](pnt a, pnt b) { return a.y < b.y; });
      for (int j = i; j < r; ++j)
        if (a[j].y == a[j + 1].y) Q.merge(a[j].co(), a[j + 1].co());
      for (int j = i; j <= r; ++j) {
        tid[Q.root(a[j].co())] =
            max(tid[Q.root(a[j].co())], max(mx[a[j].x], my[a[j].y]) + 1);
      }
      for (int j = i; j <= r; ++j) {
        mx[a[j].x] = tid[Q.root(a[j].co())];
        my[a[j].y] = tid[Q.root(a[j].co())];
      }
      for (int j = i; j <= r; ++j) {
        ans[{a[j].x, a[j].y}] = tid[Q.root(a[j].co())];
      }
      sort(a.begin() + i, a.begin() + r + 1);
    }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%d ", ans[{i, j}]);
    printf("\n");
  }
}
int main() {
  EXEC();
  return 0;
}
