#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const long long int LINF = 1LL * INF * INF;
const int MAXN = (1 << 19);
const int MAXM = 5e3 + 10;
priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;
char S[MAXN];
char T[MAXN];
int n, d, sa[MAXN], pos[MAXN];
int lcp[MAXN];
int tmp[MAXN];
bool cmp(int i, int j) {
  if (pos[i] != pos[j]) return pos[i] < pos[j];
  i += d;
  j += d;
  return (i < n && j < n) ? (pos[i] < pos[j]) : (i > j);
}
void constructSA() {
  n = strlen(S);
  for (int i = 0; i < n; i++) {
    sa[i] = i;
    pos[i] = S[i];
  }
  for (d = 1;; d <<= 1) {
    sort(sa, sa + n, cmp);
    fill(tmp, tmp + n, 0);
    for (int i = 0; i < n - 1; i++) tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
    for (int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
    if (tmp[n - 1] == n - 1) break;
  }
  for (int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
}
void constructLCP() {
  for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
    if (pos[i] == n - 1) continue;
    for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; k++)
      ;
    lcp[pos[i]] = k;
  }
}
int par[MAXN];
int sz[MAXN];
pair<int, int> ed[MAXN];
int root(int x) {
  if (x == par[x]) return x;
  return par[x] = root(par[x]);
}
int mymerge(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return sz[x];
  par[y] = x;
  sz[x] += sz[y];
  return sz[x];
}
int main() {
  int m, k, a, b, x, y;
  int sum = 0;
  int cnt = 0;
  int mx = 0;
  int mn = INF;
  int cur = 0, idx = -1;
  cin >> n;
  cin >> S;
  cin >> T;
  reverse(S, S + n);
  reverse(T, T + n);
  constructSA();
  constructLCP();
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < n; i++) sz[i] = 1 - (T[sa[i]] - '0');
  long long int res = 0;
  for (int i = 0; i < n; i++)
    if (T[sa[i]] == '0') res = max(res, (long long int)n - sa[i]);
  for (int i = 0; i < n - 1; i++) ed[i] = pair<int, int>(lcp[i], i);
  sort(ed, ed + n - 1);
  for (int i = n - 2; i >= 0; i--) {
    x = ed[i].second;
    y = ed[i].second + 1;
    cur = mymerge(x, y);
    res = max(res, (long long int)ed[i].first * cur);
  }
  cout << res << "\n";
  return 0;
}
