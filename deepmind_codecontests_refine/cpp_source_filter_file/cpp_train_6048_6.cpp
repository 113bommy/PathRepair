#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < v.size(); i++) os << v[i] << " ";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (typename set<T>::iterator it = v.begin(); it != v.end(); it++)
    os << *it << " ";
}
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
vector<pair<int, int> > g[N];
int sign[N];
long long dis[N];
int d[N];
int flag;
vector<int> b;
int siz[N];
void dfs(int u, int f) {
  siz[u] = 1;
  for (auto it : g[u]) {
    int v = it.first;
    int w = it.second;
    if (v == f) continue;
    dis[v] = dis[u] + w;
    dfs(v, u);
    siz[v] += siz[u];
    if (sign[v]) {
      sign[u] = 1;
    }
  }
  d[u] = 0;
  int tot = 0;
  for (auto it : g[u]) {
    int v = it.first;
    int w = it.second;
    if (v == f) continue;
    if (sign[v]) continue;
    if (siz[v] >= 2) flag = 1;
    tot++;
    d[u] = max(d[u], w);
  }
  if (tot >= 2) flag = 1;
  if (sign[u]) {
    b.push_back(u);
  }
}
long long suf[N], pre[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = (1); i <= (n - 1); i++) {
    int u, v, w;
    u = gi(), v = gi(), w = gi();
    g[u].push_back(pair<int, int>(v, w));
    g[v].push_back(pair<int, int>(u, w));
  }
  sign[n] = 1;
  dfs(1, 0);
  if (flag) {
    for (int i = (1); i <= (m); i++) {
      printf("%I64d\n", dis[n]);
    }
    return 0;
  }
  reverse(b.begin(), b.end());
  for (int i = (0); i <= ((int)b.size() - 1); i++) {
    pre[i + 1] = max(pre[i], dis[b[i]] + d[b[i]]);
  }
  for (int i = ((int)b.size() - 1); i >= (0); i--) {
    suf[i + 1] = max(suf[i + 2], dis[n] - dis[b[i]] + d[b[i]]);
  }
  long long ans = 0;
  for (int i = (1); i <= ((int)b.size() - 1); i++) {
    if (d[b[i - 1]] != 0 || d[b[i]] != 0) ans = max(ans, pre[i] + suf[i + 1]);
    if (i + 2 <= (int)b.size()) ans = max(ans, pre[i] + suf[i + 2]);
  }
  for (int i = (1); i <= (m); i++) {
    int q = gi();
    printf("%I64d\n", min(dis[n], q + ans));
  }
  return 0;
}
