#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > e[305 * 305];
vector<pair<int, pair<int, int> > > h;
map<int, int> w;
queue<pair<int, int> > q;
int n, m, tot, num, z, px, py, X, Y, Old, New;
int a[305][305], g[305][305], cnt[305 * 305 * 2], f[305 * 305 * 2],
    r[305 * 2][305 * 2], c[305 * 305 * 2];
bool b[305 * 305 * 2];
long long ans;
int GetId(int z) { return w.count(z) ? w[z] : w[z] = ++tot; }
int get(int z) { return f[z] == z ? z : f[z] = get(f[z]); }
int main() {
  scanf("%d%d", &n, &m), w[0] = 0;
  r[X = 305][Y = 305] = ++num;
  for (int i = 2; i < 305 + 305 - 5; i += 2) {
    X--, Y--;
    for (int j = 0; j < i; j++) r[X][++Y] = ++num;
    for (int j = 0; j < i; j++) r[++X][Y] = ++num;
    for (int j = 0; j < i; j++) r[X][--Y] = ++num;
    for (int j = 0; j < i; j++) r[--X][Y] = ++num;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &z), z = GetId(z), a[i][j] = z, c[z]++;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &z);
      if (z < 0) {
        g[i][j] = -1;
        continue;
      }
      z = GetId(z), g[i][j] = z, e[a[i][j]].push_back(make_pair(i, j));
    }
  for (int i = 1; i <= tot; i++) f[i] = i, c[i] = i;
  scanf("%d%d", &px, &py);
  q.push(make_pair(px, py));
  while (!q.empty()) {
    pair<int, int> i = q.front();
    q.pop(), Old = get(a[i.first][i.second]), New = get(g[i.first][i.second]);
    if (c[Old] && c[Old] - g[i.first][i.second]) {
      if (!b[c[Old]]) {
        b[c[Old]] = 1;
        h.clear();
        for (pair<int, int> j : e[c[Old]])
          h.push_back(make_pair(
              r[305 + j.first - i.first][305 + j.second - i.second], j));
        sort(h.begin(), h.end());
        for (pair<int, pair<int, int> > j : h) q.push(j.second);
      }
      ans += cnt[Old];
      c[New] = g[i.first][i.second];
      if (Old - New) f[Old] = New, cnt[New] += cnt[Old];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
