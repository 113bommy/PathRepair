#include <bits/stdc++.h>
using namespace std;
namespace flyinthesky {
const int MAXN = 1000000 + 5, len = 20;
int sz, ans, n, S[MAXN], a[MAXN], vis[MAXN];
vector<int> vec;
void add(int t, int op) {
  int oo = t;
  for (int i = len; i >= 0; --i) {
    if (!(t >> i & 1)) continue;
    if (a[i])
      t ^= a[i];
    else {
      for (int j = 0; j < i; ++j)
        if (t >> i & 1) t ^= a[j];
      for (int j = i + 1; j <= len; ++j)
        if (a[j] >> i & 1) a[j] ^= t;
      a[i] = t, ++sz;
      if (op) vec.push_back(oo);
      break;
    }
  }
}
void dfs(int x, int num) {
  printf("%d ", x);
  if (num == (1 << ans) - 1) return;
  for (int i = 0; i < (int)vec.size(); ++i) {
    int val = vec[i];
    if (!vis[x ^ val]) {
      vis[x ^ val] = 1;
      dfs(x ^ val, num + 1);
    }
  }
}
void clean() {}
int solve() {
  clean();
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", &S[i]);
  sort(S + 1, S + 1 + n);
  int p = 1;
  for (int i = 1; i <= len; ++i) {
    while (p <= n && S[p] <= (1 << i)) add(S[p], 0), ++p;
    if (sz == i) ans = i;
  }
  printf("%d\n", ans);
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n && S[i] < (1 << ans); ++i) add(S[i], 1);
  vis[0] = 1, dfs(0, 0);
  return 0;
}
}  // namespace flyinthesky
int main() {
  flyinthesky::solve();
  return 0;
}
