#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, val, rain[N], w[N], f[N][N];
struct umb {
  int c, id;
  umb(){};
  umb(int _c, int _id) {
    id = _id;
    c = _c;
  }
  bool operator<(const umb &t) const {
    return c < t.c || (c == t.c && id < t.id);
  }
} a[N];
void opf() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void inp() {
  cin >> val >> n >> m;
  for (int(x) = (int)(0); (x) <= (int)(val); ++(x)) a[x] = {1000000007, -1};
  int l, r;
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i)) {
    cin >> l >> r;
    for (int(j) = (int)(l); (j) <= (int)(r - 1); ++(j)) rain[j] = 1;
  }
  for (int(i) = (int)(0); (i) <= (int)(m - 1); ++(i)) {
    cin >> l >> r;
    a[l] = min(a[l], umb(r, i));
    w[i] = r;
  }
  for (int(i) = (int)(0); (i) <= (int)(val); ++(i))
    for (int(j) = (int)(0); (j) <= (int)(m); ++(j)) f[i][j] = 1000000007;
  f[0][0] = 0;
}
void solve() {
  for (int(x) = (int)(0); (x) <= (int)(val - 1); ++(x))
    for (int(i) = (int)(0); (i) <= (int)(m); ++(i))
      if (f[x][i] != 1000000007) {
        if (rain[x] == 0)
          if (f[x + 1][0] > f[x][i]) f[x + 1][0] = f[x][i];
        if (i > 0)
          if (f[x + 1][i] > f[x][i] + w[i]) f[x + 1][i] = f[x][i] + w[i];
        if (a[x].id != -1)
          if (f[x + 1][a[x].id] > f[x][i] + a[x].c)
            f[x + 1][a[x].id] = f[x][i] + a[x].c;
      }
  int res = 1000000007;
  for (int(i) = (int)(0); (i) <= (int)(m); ++(i))
    if (res > f[val][i]) res = f[val][i];
  cout << (res == 1000000007 ? -1 : res);
}
int main() {
  opf();
  inp();
  solve();
  return 0;
}
