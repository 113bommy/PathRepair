#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int x, y, v;
} d[1200];
inline bool cmp(node a, node b) { return a.v < b.v; }
int fa[1200], sz[1200], sum[1200], SUM;
inline int getroot(int x) {
  if (fa[x] == x) return x;
  return fa[x] = getroot(fa[x]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> d[i].x >> d[i].y >> d[i].v;
  }
  for (int i = 1; i <= n; i++) cin >> sum[i], SUM += sum[i];
  sort(d + 1, d + n, cmp);
  for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
  int last = 0;
  for (int i = 1; i < n; i++) {
    last = d[i].v;
    if (SUM - (sum[getroot(d[i].x)] + sum[getroot(d[i].y)]) <
        sz[getroot(d[i].x)] + sz[getroot(d[i].y)]) {
      ;
      break;
    } else
      sum[getroot(d[i].x)] += sum[getroot(d[i].y)],
          sz[getroot(d[i].x)] += sz[getroot(d[i].y)],
          fa[getroot(d[i].y)] = fa[getroot(d[i].x)];
  }
  cout << last << endl;
}
