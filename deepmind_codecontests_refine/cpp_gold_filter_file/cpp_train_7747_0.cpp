#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long n[3];
vector<int> g[3][100005];
long long val[3][100005], size[3][100005], cnt[3][100005];
long long bst[2][100005], cur;
long long res = 0;
int x, y;
void dfs1(int id, int v, int pr = -1) {
  size[id][v] = 1;
  for (int(i) = 0; (i) < (g[id][v].size()); ++(i)) {
    int to = g[id][v][i];
    if (to == pr) continue;
    dfs1(id, to, v);
    size[id][v] += size[id][to];
    val[id][v] += val[id][to] + size[id][to];
  }
}
void dfs2(int id, int v, int pr = -1) {
  cnt[id][v] = val[id][v];
  if (pr != -1) {
    cnt[id][v] +=
        cnt[id][pr] - (val[id][v] + size[id][v]) + (n[id] - size[id][v]);
  }
  for (int(i) = 0; (i) < (g[id][v].size()); ++(i)) {
    int to = g[id][v][i];
    if (to == pr) continue;
    dfs2(id, to, v);
  }
}
void dfs3(int id, int v, int pr = -1) {
  multiset<long long> now;
  for (int(i) = 0; (i) < (g[id][v].size()); ++(i)) {
    int to = g[id][v][i];
    if (to == pr) continue;
    dfs3(id, to, v);
    now.insert(bst[0][to]);
  }
  cur = max(cur, cnt[id][v] * (n[x] + n[y]));
  bst[0][v] = cnt[id][v] * n[x];
  bst[1][v] = cnt[id][v] * n[y];
  for (int(i) = 0; (i) < (g[id][v].size()); ++(i)) {
    int to = g[id][v][i];
    if (to == pr) continue;
    now.erase(now.find(bst[0][to]));
    if (!now.empty())
      cur = max(cur, *now.rbegin() + 2 * n[x] * n[y] + bst[1][to]);
    now.insert(bst[0][to]);
    cur = max(cur, cnt[id][v] * n[x] + n[x] * n[y] + bst[1][to]);
    cur = max(cur, cnt[id][v] * n[y] + n[x] * n[y] + bst[0][to]);
    bst[0][v] = max(bst[0][v], bst[0][to] + n[x] * n[y]);
    bst[1][v] = max(bst[1][v], bst[1][to] + n[x] * n[y]);
  }
}
int main(void) {
  cin >> n[0] >> n[1] >> n[2];
  long long mx[3] = {0, 0, 0};
  long long s = 0;
  for (int(i) = 0; (i) < (3); ++(i)) {
    for (int(j) = 0; (j) < (n[i] - 1); ++(j)) {
      int x, y;
      scanf("%d %d", &x, &y);
      --x;
      --y;
      g[i][x].push_back(y);
      g[i][y].push_back(x);
    }
    dfs1(i, 0);
    dfs2(i, 0);
    for (int(j) = 0; (j) < (n[i]); ++(j)) {
      s += cnt[i][j];
      mx[i] = max(mx[i], cnt[i][j]);
    }
  }
  s /= 2;
  for (int(i) = 0; (i) < (3); ++(i))
    for (int(j) = 0; (j) < (3); ++(j))
      if (i != j) {
        x = j;
        y = 3 - i - j;
        cur = 0;
        dfs3(i, 0);
        cur += s;
        cur += 2 * n[x] * n[y];
        cur += mx[x] * n[i] + n[x] * n[i];
        cur += mx[y] * n[i] + n[y] * n[i];
        cur += mx[x] * n[y] + mx[y] * n[x];
        res = max(res, cur);
      }
  cout << res << "\n";
  return 0;
}
