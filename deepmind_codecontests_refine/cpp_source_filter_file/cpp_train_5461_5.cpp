#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
int ch[N], best[N];
vector<pair<int, int> > v[N];
long long dfs(int p, int x) {
  ch[x] = 1;
  best[x] = x;
  long long res = 0;
  for (auto tmp : v[x]) {
    int u = tmp.first;
    int e = tmp.second;
    if (u != p) {
      res += dfs(x, u);
      res += (long long)e * ch[u];
      ch[x] += ch[u];
      if (ch[u] * 2 >= n) {
        best[x] = best[u];
      }
    }
  }
  return res;
}
int cnt;
int col[N], size[N];
set<pair<int, int> > all, sizes;
set<int> s[N];
void dfs2(int p, int x) {
  col[x] = cnt;
  s[cnt].insert(x);
  for (auto tmp : v[x]) {
    int u = tmp.first;
    if (u != p) dfs2(x, u);
  }
}
void del(int x) {
  int c = col[x];
  all.erase({*s[c].begin(), c});
  sizes.erase({size[c], c});
  s[c].erase(x);
  size[c]--;
  if (s[c].size()) {
    all.insert({*s[c].begin(), c});
    sizes.insert({size[c], c});
  }
}
void sub(int x) {
  int c = col[x];
  sizes.erase({size[c], c});
  size[c]--;
  sizes.insert({size[c], c});
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    v[x].push_back({y, z});
    v[y].push_back({x, z});
  }
  dfs(0, 1);
  int root = best[1];
  long long res = dfs(0, root);
  printf("%lld\n", res * 2);
  s[0].insert(root);
  all.insert({root, 0});
  sizes.insert({2, 0});
  for (auto tmp : v[root]) {
    int u = tmp.first;
    cnt++;
    dfs2(root, u);
    size[cnt] = ch[u] * 2;
    all.insert({*s[cnt].begin(), cnt});
    sizes.insert({size[cnt], cnt});
  }
  for (int i = 1; i <= n; i++) {
    auto tmp = *sizes.rbegin();
    if (tmp.second != col[i] and !tmp.second and tmp.first == n - i + 1) {
      int w = tmp.second;
      int x = *s[w].begin();
      printf("%d ", x);
      del(x);
    } else {
      auto tmp = all.begin();
      if (i != root and tmp->second == col[i]) tmp++;
      int x = tmp->first;
      printf("%d ", x);
      del(x);
    }
    sub(i);
  }
  puts("");
  return 0;
}
