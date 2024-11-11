#include <bits/stdc++.h>
using namespace std;
int const N = 101010;
int const M = 1001000;
int parents[N];
int Find(int a) { return parents[a] < 0 ? a : parents[a] = Find(parents[a]); }
void Union(int a, int b) {
  if (parents[a] < parents[b])
    parents[a] += parents[b], parents[b] = a;
  else
    parents[b] += parents[a], parents[a] = b;
}
int n, m;
struct edges {
  int u, next;
} e[M];
int p[N], idx;
void addedge(int u, int v) { e[idx].u = v, e[idx].next = p[u], p[u] = idx++; }
void init() {
  idx = 0;
  memset(p, (0xff), sizeof p);
  memset(parents, (0xff), sizeof parents);
}
int v[N];
vector<int> ans;
void dfs(int u, int pre) {
  ans.push_back(u);
  v[u] ^= 1;
  for (int i = p[u]; ~i; i = e[i].next) {
    int t = e[i].u;
    if (t != pre) dfs(t, u);
  }
  if (v[u] == 1) {
    if (pre == -1) {
      for (int i = p[u]; ~i; i = e[i].next) {
        int t = e[i].u;
        ans.push_back(t);
        ans.push_back(u);
        ans.push_back(t);
        break;
      }
    } else {
      ans.push_back(pre);
      ans.push_back(u);
      ans.push_back(pre);
    }
  } else if (pre != -1) {
    ans.push_back(pre);
    v[pre] ^= 1;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  int a, b;
  for (int i = 0; i < (m); ++i) {
    scanf("%d%d", &a, &b);
    int ra = Find(a), rb = Find(b);
    if (ra != rb) {
      Union(ra, rb);
      addedge(a, b);
      addedge(b, a);
    }
  }
  for (int i = 1; i <= (n); ++i) scanf("%d", &v[i]);
  for (int i = 1; i <= (n); ++i) Find(i);
  int g = -1, root = -1;
  for (int i = 1; i <= (n); ++i) {
    int r = Find(i);
    if (v[i] == 1) {
      if (r == g) continue;
      if (g != -1) {
        puts("-1");
        return 0;
      }
      g = r;
      root = i;
    }
  }
  if (root == -1) {
    puts("0");
    return 0;
  }
  dfs(root, -1);
  printf("%d\n", ans.size());
  int sz = ans.size();
  for (int i = 0; i < (sz); ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
