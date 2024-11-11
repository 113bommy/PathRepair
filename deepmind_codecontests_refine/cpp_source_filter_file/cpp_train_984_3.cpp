#include <bits/stdc++.h>
using namespace std;
int id[101][101];
int sz[101][101];
int root(int i, int c) {
  while (id[c][i] != i) {
    id[c][i] = id[c][id[c][i]];
    i = id[c][i];
  }
  return i;
}
bool connected(int p, int q, int c) { return root(p, c) == root(q, c); }
void qunion(int p, int q, int c) {
  int rp = root(p, c);
  int rq = root(q, c);
  if (rp == rq) return;
  if (sz[c][rp] < sz[c][rq]) {
    id[c][rp] = rq;
    sz[c][rq] += sz[c][rp];
  } else {
    id[c][rq] = rp;
    sz[c][rp] += sz[c][rq];
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int j = 1; j <= 100; j++) {
    for (int i = 1; i <= 100; i++) {
      id[j][i] = i;
      sz[j][i] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    qunion(x, y, c);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    int y;
    cin >> x >> y;
    int ans = 0;
    for (int j = 1; j <= 1; j++) {
      if (connected(x, y, j)) ans++;
    }
    cout << ans << "\n";
  }
}
