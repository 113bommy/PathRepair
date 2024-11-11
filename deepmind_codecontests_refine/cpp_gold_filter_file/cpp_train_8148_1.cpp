#include <bits/stdc++.h>
using namespace std;
int n, child[35 * 200005][2], isEnd[35 * 200005], cnt = 0;
void add(int a) {
  int node = 0;
  for (int i = 30; i >= 0; i--) {
    int x = ((a >> i) & 1);
    if (!child[node][x]) child[node][x] = ++cnt;
    node = child[node][x];
  }
  isEnd[node] = 1;
}
int dfs(int u) {
  if (isEnd[u]) return 1;
  int a = 0, b = 0;
  if (child[u][0]) a = dfs(child[u][0]);
  if (child[u][1]) b = dfs(child[u][1]);
  return max(min(1, a) + b, a + min(1, b));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    add(a);
  }
  cout << n - dfs(0);
  return 0;
}
