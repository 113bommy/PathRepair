#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> res, res2, res3;
int x[10005], y[10005], id[35], b[35], vis[10005], r[10005];
bitset<35> c[35], d[35], tmp;
int insert(int x, int y, bitset<35> now) {
  for (int i = 0; i <= 30; i++)
    if (x & (1 << i)) {
      if (!b[i]) {
        b[i] = x;
        id[i] = y;
        vis[y] = 1;
        d[i] = now;
        d[i][i] = 1;
        return i;
      }
      x ^= b[i];
      now ^= d[i];
    }
  return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &x[i]), r[i] = insert(x[i], i, bitset<35>());
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
  for (int i = 1; i <= n; i++) {
    int now = y[i];
    for (int j = 0; j <= 30; j++)
      if (now & (1 << j)) {
        now ^= b[j];
        if (~r[i]) c[r[i]] ^= d[j];
      }
    if (now) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      int now = y[i] ^ x[i];
      tmp.reset();
      for (int j = 0; j <= 30; j++)
        if (now & (1 << j)) now ^= b[j], tmp ^= d[j];
      for (int j = 0; j <= 30; j++)
        if (tmp[j]) res.push_back({i, id[j]});
    }
  for (int i = 0; i <= 30; i++) {
    if (!c[i][i])
      for (int j = 0; j <= 30; j++)
        if (c[j][i] && ((!c[j][j]) || j > i)) {
          res2.push_back({id[i], id[j]});
          res2.push_back({id[j], id[i]});
          res2.push_back({id[i], id[j]});
          swap(c[i], c[j]);
          break;
        }
    if (!c[i][i]) continue;
    for (int j = 0; j <= 30; j++)
      if (i != j && c[j][i]) {
        c[j] ^= c[i];
        res2.push_back({id[j], id[i]});
      }
  }
  for (int i = 1; i <= 30; i++)
    for (int j = 0; j < i; j++)
      if (c[j][i]) res3.push_back({id[j], id[i]});
  for (int i = 0; i <= 30; i++)
    if ((id[i]) && (!(c[i][i]))) res2.push_back({id[i], id[i]});
  printf("%d\n", (int)(res.size() + res2.size() + res3.size()));
  reverse(res2.begin(), res2.end());
  for (auto i : res) printf("%d %d\n", i.first, i.second);
  for (auto i : res3) printf("%d %d\n", i.first, i.second);
  for (auto i : res2) printf("%d %d\n", i.first, i.second);
  return 0;
}
