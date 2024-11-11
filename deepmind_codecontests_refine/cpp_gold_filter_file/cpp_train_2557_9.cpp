#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(1000005);
vector<int> a[MAXN];
bool visited[MAXN];
int dfs(int node) {
  visited[node] = 1;
  int ret = 1;
  for (int i = 0; i < a[node].size(); i++)
    if (!visited[a[node][i]]) ret += dfs(a[node][i]);
  return ret;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  vector<int> b;
  for (int i = 1; i <= n; i++)
    if (!visited[i]) b.push_back(min(k, dfs(i)));
  if (k == 1) {
    printf("%d", max(0, (int)b.size() - 2));
    return 0;
  }
  sort(b.begin(), b.end(), greater<int>());
  int now = b[0], l = 0, ans = 0;
  vector<int> slot;
  slot.push_back(max(0, k - b[0]));
  for (int i = 1; i <= (int)(b.size()) - 1; i++) {
    if (now + b[i] - 2 >= 0)
      now = now + b[i] - 2;
    else {
      ans++;
      while (l < slot.size() && slot[l] <= 0) l++;
      if (l < slot.size()) {
        now = 1;
        slot[l]--;
      } else
        now = 0;
    }
    slot.push_back(max(0, k - b[i]));
  }
  printf("%d", ans);
}
