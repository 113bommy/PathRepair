#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 1005;
char c[N];
int a[N], num[N], pw[N], used[N * 2], col[N * 2];
int ind[2];
int n, m, ans;
bool uz, ok;
set<int> rt;
vector<pair<int, int> > nei[N * 4];
inline int NUM(int x) {
  if (x > n + m) return num[x - n - m];
  return num[x];
}
void dfs(int x, int c) {
  if (NUM(x) != -1) uz = false;
  col[x] = c;
  if (ind[c] == -1 && NUM(x) != -1) ind[c] = NUM(x);
  if ((ind[c] != NUM(x) || ind[c ^ 1] == NUM(x)) && NUM(x) != -1) ok = false;
  used[x] = 1;
  for (int i = 0; i < nei[x].size(); i++) {
    int nx = nei[x][i].first;
    if (!used[nx])
      dfs(nx, (c + nei[x][i].second) % 2);
    else if (col[nx] != (c + nei[x][i].second) % 2)
      ok = false;
  }
}
int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * 2 % MOD;
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int i = 1; i <= n; i++) {
    if (c[i] == '0') a[i] = 0;
    if (c[i] == '1') a[i] = 1;
    if (c[i] == '?') a[i] = -1;
  }
  for (int i = n; i > 1; i--) {
    bool pal = true;
    m = n - i + 1;
    for (int j = 1; j <= (n + m); j++) {
      nei[j].clear();
      num[j] = -1;
    }
    for (int j = 1; j < i; j++) num[j] = a[j];
    num[n + 1] = 1;
    for (int j = 1; j <= n; j++)
      if (n + 1 - j != j) nei[j].push_back(make_pair(n + 1 - j, 0));
    for (int j = 1; j <= m; j++)
      if (m + 1 - j != j) nei[j + n].push_back(make_pair(m + 1 - j + n, 0));
    for (int j = 1; j <= m; j++) {
      if (a[j + n - m] != -1)
        nei[j + n].push_back(make_pair(j + n - m, a[j + n - m]));
      if (a[j + n - m] != -1)
        nei[j + n - m].push_back(make_pair(j + n, a[j + n - m]));
    }
    memset(col, -1, sizeof(col));
    memset(used, 0, sizeof(used));
    int add = 1;
    ok = true;
    for (int j = 1; j <= n + m; j++)
      if (!used[j]) {
        uz = true;
        ind[0] = ind[1] = -1;
        dfs(j, 0);
        if (uz) add = (add * 2) % MOD;
      }
    if (ok) ans = (ans + add) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
