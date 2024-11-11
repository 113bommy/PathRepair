#include <bits/stdc++.h>
using namespace std;
const int MAXN = 18;
const int MAXQ = 100010;
const double EPS = 1e-10;
const double DINF = 1e30;
const int IINF = ~0U >> 3;
const long long LINF = 1LL << 61;
void debug() { cout << "error_here" << endl; }
int n, m, tem[MAXN][MAXN], d[MAXN], p[MAXN];
int dp[1 << MAXN], ans;
int find_set(int x) {
  if (p[x] != x) p[x] = find_set(p[x]);
  return p[x];
}
void union_set(int x, int y) {
  x = find_set(x), y = find_set(y);
  if (x != y) p[x] = y;
}
void init() {
  scanf("%d%d", &n, &m);
  memset(d, 0, sizeof(d));
  ans = 0;
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) tem[i][j] = (i == j ? 0 : IINF);
  for (int i = 0, a, b, c; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    d[--a]++, d[--b]++;
    union_set(a, b);
    tem[b][a] = tem[a][b] = min(tem[a][b], c);
    ans += c;
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        tem[i][j] = min(tem[i][j], tem[i][k] + tem[k][j]);
  if (p[0] == 0 && d[0] == 0) {
    puts("-1");
    exit(0);
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (d[i] && p[i] == i) cnt++;
  if (cnt > 1) {
    puts("-1");
    exit(0);
  }
}
void solve() {
  vector<int> odd;
  for (int i = 0; i < n; ++i)
    if (d[i] & 1) odd.push_back(i);
  int s = 1 << odd.size();
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int u = 0; u < s; ++u)
    if (~dp[u])
      for (int i = 0; i < (int)odd.size(); ++i)
        if (!(u & (1 << i)))
          for (int j = i + 1; j < (int)odd.size(); ++j)
            if (!(u & (1 << j)) && i != j)
              if (dp[u + (1 << i) + (1 << j)] == -1 ||
                  dp[u + (1 << i) + (1 << j)] > dp[u] + tem[odd[i]][odd[j]])
                dp[u + (1 << i) + (1 << j)] = dp[u] + tem[odd[i]][odd[j]];
  printf("%d\n", dp[s - 1] + ans);
}
int main() {
  init();
  solve();
  return 0;
}
