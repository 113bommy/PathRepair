#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> v[N];
int n, cnt[N], mx = 0;
bool vis[N];
void dfs(int x, int c) {
  vis[x] = true;
  for (auto el : v[x]) {
    cnt[c]++;
    mx = max(mx, c);
    if (!vis[el]) dfs(el, c + 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    v[a].push_back(i);
  }
  memset(cnt, 0, sizeof(cnt));
  memset(vis, 0, sizeof(vis));
  dfs(1, 1);
  int ans = 1;
  for (int i = 1; i <= mx; ++i) {
    ans += (cnt[i] % 2);
  }
  printf("%d\n", ans);
}
