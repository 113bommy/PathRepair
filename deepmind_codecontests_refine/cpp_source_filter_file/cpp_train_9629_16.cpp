#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7, mod = 1e9 + 7, inf = 1e5 + 7;
const long long linf = (long long)1e18 + 7;
const long double eps = 1e-15, pi = 3.141592;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
inline int get_int() {
  char x = getchar();
  while (!('0' <= x && x <= '9')) x = getchar();
  int res = 0;
  while ('0' <= x && x <= '9') res = res * 10 + x - '0', x = getchar();
  return res;
}
int n, q, timer;
int in[N], out[N], second[N], h[N];
vector<int> g[N];
vector<pair<int, int> > first[N];
inline void dfs(int v = 1, int lvl = 1) {
  in[v] = ++timer, h[v] = lvl;
  first[lvl].push_back({timer, first[lvl].back().second ^ (1 << second[v])});
  for (auto i : g[v]) dfs(i, lvl + 1);
  out[v] = timer;
}
int main() {
  n = get_int(), q = get_int();
  for (int i = 2; i <= n; ++i) {
    int to;
    to = get_int();
    g[to].push_back(i);
  }
  putchar('\n');
  for (int i = 1; i <= n; ++i) {
    char x;
    x = getchar();
    second[i] = x - 'a';
    first[i].resize(1);
  }
  dfs();
  for (int i = 1; i <= q; ++i) {
    int x, y, cnt = 0, sol = 0, on = 0;
    x = get_int(), y = get_int();
    if (h[x] > y) {
      printf("Yes\n");
      continue;
    }
    int l = 0, r = (int)first[y].size() - 1, ans = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (first[y][mid].first <= out[x])
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    on = first[y][ans].second;
    l = 0, r = (int)first[y].size() - 1, ans = -1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (first[y][mid].first < in[x])
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (ans != -1) sol = first[y][ans].first;
    cnt = __builtin_popcountll(sol ^ on);
    if (cnt > 1)
      printf("No\n");
    else
      printf("Yes\n");
  }
  exit(0);
}
