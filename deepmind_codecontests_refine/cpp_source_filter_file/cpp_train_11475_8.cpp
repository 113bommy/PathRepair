#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int n, c[maxn], a[maxn], t[maxn], rt;
vector<int> es[maxn];
void upd(int x, int v) {
  while (x <= 2000) {
    t[x] += v;
    x += x & -x;
  }
}
int qr(int x) {
  int r = 0;
  while (x) {
    r += t[x];
    x -= x & -x;
  }
  return r;
}
void dfs(int u, int fa) {
  int l = 1, r = 2000, mid = l + r >> 1;
  while (r - l > 1) {
    if (qr(mid) >= c[u] + 1) {
      r = mid;
    } else
      l = mid;
    mid = l + r >> 1;
  }
  if (qr(l) >= c[u] + 1)
    a[u] = l, upd(l, -1);
  else if (qr(mid) >= c[u] + 1)
    a[u] = mid, upd(mid, -1);
  else
    a[u] = r, upd(r, -1);
  if (a[u] > n) {
    puts("NO");
    exit(0);
  }
  for (auto v : es[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
  if (qr(c[u] + 1)) {
    puts("NO");
    exit(0);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= 2000; i++) upd(i, 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x >> c[i];
    if (x)
      es[i].push_back(x), es[x].push_back(i);
    else
      rt = i;
  }
  dfs(rt, -1);
  puts("YES");
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
}
