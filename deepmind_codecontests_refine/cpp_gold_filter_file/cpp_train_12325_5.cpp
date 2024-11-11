#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int MAXN = int(1e6) + 5;
vector<pair<int, int> > bad[MAXN];
int n, k;
int a[5010];
int par[5010];
int sz[5010];
int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }
int union_set(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) return 0;
  if (sz[x] > sz[y]) swap(x, y);
  par[x] = y;
  return 1;
}
bool good(int m) {
  int cnt = 0;
  int J = m;
  for (int j = m; j < MAXN; j += m) {
    J = j;
    for (int i = 0; i < int(((int)(bad[j]).size())); i++)
      cnt += union_set(bad[j][i].first, bad[j][i].second);
    if (cnt > k) break;
  }
  for (int j = m; j <= J; j += m)
    for (int i = 0; i < int(((int)(bad[j]).size())); i++) {
      int x = bad[j][i].first;
      int y = bad[j][i].second;
      par[x] = x;
      par[y] = y;
      sz[x] = sz[y] = 1;
    }
  return cnt <= k;
}
int main() {
  scanf("%d %d", &n, &k);
  if (n - k <= 1) {
    puts("1");
    return 0;
  }
  int ma = -1;
  for (int i = 0; i < int(n); i++) {
    scanf("%d", &a[i]);
    ma = max(a[i], ma);
    for (int j = 0; j < int(i); j++) {
      int id = abs(a[i] - a[j]);
      if (bad[id].empty() || ((int)(bad[id]).size()) <= k)
        bad[abs(a[i] - a[j])].push_back(make_pair(i, j));
    }
  }
  for (int i = 0; i < int(n); i++) {
    par[i] = i;
    sz[i] = 1;
  }
  for (int i = 2; i < MAXN; i++)
    if (good(i)) {
      printf("%d\n", i);
      return 0;
    }
  printf("%d\n", ma + 1);
  return 0;
}
