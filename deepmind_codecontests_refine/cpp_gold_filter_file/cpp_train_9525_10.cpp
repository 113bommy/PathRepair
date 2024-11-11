#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > r;
int n, ec;
inline char nc() { return getchar(); }
inline int read() {
  char ch = nc();
  int sum = 0;
  while (!(ch >= '0' && ch <= '9')) ch = nc();
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = nc();
  return sum;
}
bitset<1010> g[1010], v[1010], vi;
void add(int a, int b) {
  if (a > b) swap(a, b);
  if (r.count(make_pair(a, b))) return;
  ec++;
  r.insert(make_pair(a, b));
}
int main() {
  cin >> n;
  if (n == 2) {
    puts("1 2");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    v[i][i] = 1;
    for (int j = 1; j <= c; j++) {
      int x = read();
      g[i][x] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      auto b = g[i] & g[j];
      if (b.count() == 2) {
        int x = 0, y = 0;
        for (int k = 1; k <= n; k++)
          if (b[k]) {
            if (!x)
              x = k;
            else
              y = k;
          }
        add(x, y);
        v[x][y] = v[y][x] = 1;
        vi[x] = vi[y] = 1;
      }
    }
  if (!ec) {
    for (int i = 2; i <= n; i++) printf("1 %d\n", i);
    return 0;
  }
  if (ec == 1) {
    int x = r.begin()->first, y = r.begin()->second;
    bitset<1010> a, b;
    int ok = 0;
    for (int i = 1; i <= n; i++)
      if (g[i].count() != n) a = g[i];
    cout << x << ' ' << y << '\n';
    for (int i = 1; i <= n; i++)
      if (i != x && i != y) {
        if (a[i])
          cout << x << ' ' << i << '\n';
        else
          cout << y << ' ' << i << '\n';
      }
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (!vi[i]) {
      int mn = 1e9, p = 0;
      for (int j = 1; j <= n; j++)
        if (g[j][i] && g[j].count() < mn) {
          mn = g[j].count();
          p = j;
        }
      bitset<1010> t = g[p] & vi;
      for (int j = 1; j <= n; j++)
        if (vi[j] && v[j] == t) {
          add(i, j);
          break;
        }
    }
  for (auto x : r) cout << x.first << ' ' << x.second << '\n';
}
