#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 17) + 1;
const int ALPH = ('z' - 'a' + 1);
int K;
vector<int> E[MAXN];
bool vis[MAXN];
int n;
int cnt[MAXN];
int sum[MAXN];
int s;
int dfs(int v) {
  if (vis[v]) return 0;
  vis[v] = true;
  if (0)
    cout << "v"
         << ":" << (v) << " " << endl;
  int res = 1;
  for (__typeof((E[v]).end()) e = (E[v]).begin(); e != (E[v]).end(); e++) {
    res += dfs(*e);
  }
  return res;
}
int countTrees() {
  long long res = 1;
  if (s == 1) return 1 % K;
  for (int i = 0; i < (s); ++i) {
    res = (res * cnt[i]) % K;
    if (i > 1) res = (res * n) % K;
  }
  return res;
}
int main() {
  int m;
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 0; i < (m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  for (int i = 0; i < (n); ++i) {
    if (vis[i]) continue;
    cnt[s++] = dfs(i);
    if (0)
      cout << "s"
           << ":" << (s) << " " << endl;
  }
  printf("%d\n", countTrees());
  return 0;
}
