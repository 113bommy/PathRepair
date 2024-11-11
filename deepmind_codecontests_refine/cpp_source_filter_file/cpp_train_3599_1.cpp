#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
char s[1010][1010];
int fa[N], dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
           dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, n, m, q, S, T, k, bx[20],
           by[20], st[N], tp, id[1010][1010], tt;
set<pair<int, int> > all;
int getf(int x) { return x == fa[x] ? x : fa[x] = getf(fa[x]); }
int getf2(int x) { return x == fa[x] ? x : getf2(fa[x]); }
pair<int, int> mp2(int x, int y) { return make_pair(min(x, y), max(x, y)); }
int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; j++) id[i][j] = ++tt;
  }
  S = ++tt;
  T = ++tt;
  for (int i = 1; i <= tt; i++) fa[i] = i;
  for (int i = 1; i <= n; i++)
    id[i][0] = S, id[i][m + 1] = T, s[i][0] = s[i][m + 1] = '#';
  for (int i = 1; i <= m; i++)
    id[0][i] = T, id[n + 1][i] = S, s[0][i] = s[n + 1][i] = '#';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#')
        for (int d = 0; d < 8; d++) {
          int x = i + dx[d], y = j + dy[d];
          if (s[x][y] == '#') fa[getf(id[i][j])] = getf(id[x][y]);
        }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i + j == 2 || i + j == n + m) continue;
      for (int d1 = 0; d1 < 8; d1++)
        for (int d2 = d1 + 1; d2 < 8; d2++) {
          int x1 = i + dx[d1], y1 = j + dy[d1], x2 = i + dx[d2],
              y2 = j + dy[d2];
          all.insert(mp2(getf(id[x1][y1]), getf(id[x2][y2])));
        }
    }
  for (int i = 1; i <= tt; i++) getf(i);
  while (q--) {
    k = gi();
    tp = 0;
    for (int i = 1; i <= k; i++) {
      bx[i] = gi(), by[i] = gi();
      s[bx[i]][by[i]] = '#';
      st[++tp] = getf(id[bx[i]][by[i]]);
      for (int d = 0; d < 8; d++) {
        int x = bx[i] + dx[d], y = by[i] + dy[d];
        if (s[x][y] == '#') st[++tp] = getf(id[x][y]);
      }
    }
    st[++tp] = getf(S);
    st[++tp] = getf(T);
    sort(st + 1, st + tp + 1);
    tp = unique(st + 1, st + tp + 1) - st - 1;
    for (int i = 1; i <= k; i++)
      for (int d = 0; d < 8; d++) {
        int x = bx[i] + dx[d], y = by[i] + dy[d];
        if (s[x][y] == '#') {
          fa[getf2(id[bx[i]][by[i]])] = getf2(id[x][y]);
        }
      }
    bool ans = 1;
    if (getf2(S) == getf2(T)) ans = 0;
    for (int i = 1; i <= tp && ans; i++)
      if (getf2(st[i]) == getf(S))
        for (int j = 1; j <= tp && ans; j++)
          if (getf2(st[j]) == getf(T) &&
              all.find(mp2(st[i], st[j])) != all.end())
            ans = 0;
    cout << (ans ? "YES" : "NO") << endl;
    for (int i = 1; i <= k; i++) s[bx[i]][by[i]] = '.';
    for (int i = 1; i <= tp; i++) fa[st[i]] = st[i];
  }
  return 0;
}
