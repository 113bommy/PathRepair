#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
unsigned long long int POW(unsigned long long int p, int b) {
  unsigned long long int ans = 1LL;
  while (b > 0) {
    if (b & 1) {
      ans = ans * 1LL * p;
    }
    b /= 2;
    p = p * 1LL * p;
  }
  return ans;
}
long long int power(long long int a, long long int b, long long int mod) {
  long long int x = 1;
  long long int y = a;
  while (b > 0) {
    if (b & 1) {
      x = x * y;
      x %= mod;
    }
    y = y * y;
    y %= mod;
    b /= 2;
  }
  return x;
}
long long int add(long long int a, long long int b, long long int m = MOD) {
  long long int x = a + b;
  while (x >= m) x -= m;
  while (x < 0) x += m;
  return x;
}
long long int sub(long long int a, long long int b, long long int m = MOD) {
  long long int x = a - b;
  while (x < 0) x += m;
  while (x >= m) x -= m;
  return x;
}
long long int mul(long long int a, long long int b, long long int m = MOD) {
  long long int x = a * 1ll * b;
  x %= m;
  if (x < 0) x += m;
  return x;
}
const int N = 4e5 + 2;
vector<pair<int, int> > g[N];
bool used[N];
int n, m;
int maxi = 0;
int start = 0;
int intime[N], lowtime[N];
bool bridge[N];
int timer = 0;
int len = 0;
void dfs(int u, int p = 0) {
  if (used[u]) return;
  used[u] = true;
  intime[u] = lowtime[u] = timer++;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].first;
    if (v == p) continue;
    if (used[v]) {
      lowtime[u] = min(lowtime[u], intime[v]);
    } else {
      dfs(v, u);
      lowtime[u] = min(lowtime[u], lowtime[v]);
      if (lowtime[v] > lowtime[u]) {
        bridge[g[u][i].second] = true;
      }
    }
  }
}
void dfs2(int u) {
  if (used[u]) return;
  len++;
  used[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].first;
    int ege = g[u][i].second;
    if (bridge[ege]) continue;
    dfs2(v);
  }
}
bool done[N];
pair<int, int> ans[N];
void finaldfs(int u) {
  if (used[u]) return;
  used[u] = true;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].first;
    int ege = g[u][i].second;
    if (done[ege]) continue;
    if (bridge[ege]) {
      ans[ege] = make_pair(v, u);
      done[ege] = true;
      finaldfs(v);
    } else {
      ans[ege] = make_pair(u, v);
      done[ege] = true;
      finaldfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(make_pair(y, i));
    g[y].push_back(make_pair(x, i));
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs(i);
  memset(used, false, sizeof used);
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs2(i);
      if (len > maxi) {
        maxi = len;
        start = i;
      }
      len = 0;
    }
  }
  memset(used, false, sizeof used);
  finaldfs(start);
  cout << maxi << endl;
  for (int i = 1; i <= m; i++)
    cout << ans[i].first << " " << ans[i].second << endl;
}
