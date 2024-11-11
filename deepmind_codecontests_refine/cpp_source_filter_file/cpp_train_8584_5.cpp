#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const int INF = 1000000000;
int a[MAXN];
int T[50][4 * MAXN];
int n, q;
int ans;
int calc(int k, int x) {
  int ret = 1;
  while (k % x == 0) k++, ret++;
  return ret;
}
void init(int x, int i, int j) {
  if (i == j) {
    for (int k = 0; k < 30; k++) T[k][x] = calc(k, a[i]);
    return;
  }
  int mid = (i + j) / 2;
  init(x + x, i, mid);
  init(x + x + 1, mid + 1, j);
  for (int k = 0; k < 30; k++) {
    T[k][x] = T[k][x + x] + T[(k + T[k][x + x]) % 30][x + x + 1];
  }
}
void update(int x, int i, int j, int u, int v) {
  if ((j < u) || (i > u)) return;
  if (i == j) {
    a[u] = v;
    for (int k = 0; k < 30; k++) T[k][x] = calc(k, a[i]);
    return;
  }
  int mid = (i + j) / 2;
  update(x + x, i, mid, u, v);
  update(x + x + 1, mid + 1, j, u, v);
  for (int k = 0; k < 30; k++) {
    T[k][x] = T[k][x + x] + T[(k + T[k][x + x]) % 30][x + x + 1];
  }
}
void get(int x, int i, int j, int u, int v) {
  if ((j < u) || (i > v)) return;
  if ((i >= u) && (j <= v)) {
    ans += T[ans % 30][x];
    return;
  }
  int mid = (i + j) / 2;
  get(x + x, i, mid, u, v);
  get(x + x + 1, mid + 1, j, u, v);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  init(1, 1, n);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == 'C')
      update(1, 1, n, x, y);
    else {
      ans = 0;
      get(1, 1, n, x, y - 1);
      cout << ans << endl;
    }
  }
}
