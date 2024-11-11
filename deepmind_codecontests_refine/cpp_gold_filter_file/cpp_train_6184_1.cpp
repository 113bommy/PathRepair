#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
long long mod = 1000000007;
int L[100005], pre[2 * 100005], to[2 * 100005], ne;
inline void addEdge(int u, int v) {
  to[ne] = v, pre[ne] = L[u];
  L[u] = ne++;
}
char ans[100005];
int dfs(int u, int mu) {
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  for (int e = L[u]; e != -1; e = pre[e]) {
    int v = to[e];
    if (v != mu) {
      int bit = dfs(v, u);
      for (int i = 0; i < (26); i++)
        if (bit & (1 << i)) cnt[i]++;
    }
  }
  for (int i = 0; i < (26); i++) {
    if (cnt[i] > 1) break;
    if (cnt[i] == 0) ans[u] = i;
  }
  cnt[0 + ans[u]]++;
  int ret = 0;
  for (int i = 0; i < (ans[u] + 1); i++)
    if (cnt[i]) ret |= (1 << i);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(L, -1, sizeof(L));
  ne = 0;
  for (int i = 0; i < (n - 1); i++) {
    int a, b;
    cin >> a >> b;
    addEdge(a - 1, b - 1);
    addEdge(b - 1, a - 1);
  }
  dfs(0, 0);
  for (int i = 0; i < (n); i++) cout << (char)('A' + ans[i]) << " ";
  return 0;
}
