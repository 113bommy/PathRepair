#include <bits/stdc++.h>
using namespace std;
vector<int> s[1005], t[15];
unordered_map<int, vector<int>> mp;
unordered_map<int, int> f[1005];
int g[(1 << 12) + 5], h[(1 << 12) + 5];
int rasp = 0, m;
int nr(unsigned int num) { return 32 - __builtin_clz(num); }
int dfs(int nod, int ta) {
  vector<int> aux;
  for (auto it : t[nod])
    if (it != ta) aux.push_back(dfs(it, nod));
  sort(aux.begin(), aux.end());
  int cnt = 1;
  for (auto it : aux) cnt = (cnt << nr(it)) | it;
  cnt = cnt << 1;
  if (!mp.count(cnt)) mp[cnt] = aux;
  return cnt;
}
void dfs2(int nod, int ta) {
  for (auto it : s[nod])
    if (it != ta) dfs2(it, nod);
  int i, j, c;
  for (auto it : mp) {
    int x = it.first;
    vector<int>& y = it.second;
    int l = y.size();
    memset(g, 0, sizeof(int) * (1 << l));
    g[0] = 1;
    for (auto it2 : s[nod])
      if (it2 != ta) {
        memcpy(h, g, sizeof(int) * (1 << l));
        for (i = 0; i < l; i++)
          if (c = f[it2][y[i]])
            for (j = 0; j < (1 << l); j++)
              if (g[j] && !(j & (1 << i)) &&
                  !(i && y[i] == y[i - 1] && !(j & (1 << i - 1))))
                (h[j | (1 << i)] += 1LL * c * g[j] % 1000000007) %= 1000000007;
        memcpy(g, h, sizeof(int) * (1 << l));
      }
    f[nod][x] = g[(1 << l) - 1];
    if (nr(x) == 2 * m) (rasp += g[(1 << l) - 1]) %= 1000000007;
  }
}
int main() {
  int n, i, x, y;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    s[x].push_back(y);
    s[y].push_back(x);
  }
  scanf("%d", &m);
  for (i = 1; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    t[x].push_back(y);
    t[y].push_back(x);
  }
  for (i = 0; i < m; i++) dfs(i, -1);
  dfs2(0, -1);
  printf("%d\n", rasp);
  return 0;
}
