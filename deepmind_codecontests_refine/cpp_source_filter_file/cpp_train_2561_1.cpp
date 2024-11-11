#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
pair<int, int> e[N];
int E = 0, ee[N];
int d[N], mi[20], dz[N][20];
void init() {
  memset(d, -1, sizeof(d));
  memset(ee, -1, sizeof(ee));
  for (int i = 0; i < 20; i++) mi[i] = 1 << i;
}
void deep(int t) {
  for (int i = 1; mi[i] <= t; i++) dz[t][i] = dz[dz[t][i - 1]][i - 1];
  for (int i = ee[t]; i != -1; i = e[i].second)
    if (d[e[i].first] == -1) {
      d[e[i].first] = d[t] + 1;
      dz[e[i].first][0] = t;
      deep(e[i].first);
    }
}
int get(int t, int dp) {
  int i = d[t] - dp;
  for (int j = 0; i > 0; i >>= 1, j++)
    if (i & 1) t = dz[t][j];
  return t;
}
int len(int a, int b) {
  int l = 0, r = min(d[a], d[b]), p;
  while (l != r) {
    p = (l + r + 1) / 2;
    if (get(a, p) == get(b, p))
      l = p;
    else
      r = p - 1;
  }
  return (d[a] + d[b] - 2 * l);
}
void add(int x, int y) {
  e[E] = make_pair(y, ee[x]);
  ee[x] = E++;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(0);
  init();
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int j;
    cin >> j;
    add(i, j);
    add(j, i);
  }
  d[1] = 0;
  deep(1);
  for (int i = 1; i <= q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int x = len(a, b), y = len(a, c), z = len(b, c);
    cout << (x + y + z - 2 * min(x, min(y, z))) / 2 + 1 << endl;
  }
  return 0;
}
