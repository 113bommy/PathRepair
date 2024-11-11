#include <bits/stdc++.h>
using namespace std;
const int N = 100011;
const int M = 1005;
const int MOD = 1e9 + 7;
long long int powmod(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int x = powmod(a, b / 2);
  long long int y = (x * x) % MOD;
  if (b % 2) return (a * y) % MOD;
  return y % MOD;
}
int ans[N], a[M][M], cnt;
int n, m, q;
bool f1[N], f2[N];
vector<int> g[N];
pair<int, pair<int, int> > p[N];
void frw(int i) {
  int k, x, y;
  k = p[i].first;
  x = p[i].second.first;
  y = p[i].second.second;
  if (k == 1) {
    if (!a[x][y]) {
      f1[i] = true;
      a[x][y] = 1;
      cnt++;
    }
  } else if (k == 2) {
    if (a[x][y]) {
      f2[i] = true;
      a[x][y] = 0;
      cnt--;
    }
  } else if (k == 3) {
    for (int j = 1; j < m + 1; j++) {
      a[x][j] = 1 - a[x][j];
      if (a[x][j])
        cnt++;
      else
        cnt--;
    }
  }
  ans[i] = cnt;
}
void bck(int i) {
  int k, x, y;
  k = p[i].first;
  x = p[i].second.first;
  y = p[i].second.second;
  if (k == 1) {
    if (a[x][y] && f1[i]) {
      a[x][y] = 0;
      cnt--;
    }
  } else if (k == 2) {
    if (!a[x][y] && f2[i]) {
      a[x][y] = 1;
      cnt++;
    }
  } else if (k == 3) {
    for (int j = 1; j < m + 1; j++) {
      a[x][j] = 1 - a[x][j];
      if (a[x][j])
        cnt++;
      else
        cnt--;
    }
  }
}
void dfs(int i) {
  frw(i);
  for (int j = 0; j < (int)(g[i].size()); j++) dfs(g[i][j]);
  bck(i);
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &q);
  for (int i = 1; i < q + 1; i++) {
    int k, x, y;
    scanf("%d", &k);
    if (k <= 2) {
      scanf("%d", &x);
      scanf("%d", &y);
      p[i] = {k, {x, y}};
      g[i - 1].push_back(i);
    } else {
      scanf("%d", &x);
      p[i] = {k, {x, -1}};
      if (k == 3)
        g[i - 1].push_back(i);
      else
        g[x].push_back(i);
    }
  }
  dfs(0);
  for (int i = 1; i < q + 1; i++) printf("%d\n", ans[i]);
  return 0;
}
