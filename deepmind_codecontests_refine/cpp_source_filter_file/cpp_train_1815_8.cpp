#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dc[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
vector<vector<int>> Graph;
int tim = 0;
struct node {
  long long x, k, hk;
};
class segment_tree {
 public:
  vector<node> ST;
  vector<long long> height, s, f;
  long long v, x, k;
  segment_tree(int n, int root) {
    ST.resize(4 * n), height.resize(4 * n), s.resize(n), f.resize(n);
    DFS(root, 0);
  }
  void DFS(int node, int h) {
    s[node] = tim++;
    height[node] = h;
    for (long long i = 0; i < (long long)Graph[node].size(); ++i) {
      int child = Graph[node][i];
      DFS(child, h + 1);
    }
    f[node] = tim;
  }
  void update(int p, int start, int end) {
    if (s[v] >= end || f[v] <= start) return;
    if (s[v] <= start && f[v] >= end) {
      ST[p].k = (ST[p].k + 1LL * MOD - k) % MOD;
      ST[p].x = (ST[p].x + x) % MOD;
      ST[p].hk = (ST[p].hk * 1LL + k * height[v] * 1LL) % MOD;
      return;
    }
    int mid = (start + end) / 2;
    update(2 * p, start, mid);
    update(2 * p + 1, mid, end);
  }
  long long query(int p, int start, int end) {
    long long ans = 0LL;
    ans = (ans + ST[p].x) % MOD;
    ans = (ans + ST[p].hk) % MOD;
    ans = (ans + ST[p].k * height[v]) % MOD;
    if (end - start < 2) return ans;
    int mid = (start + end) / 2;
    if (s[v] < mid) return (ans + query(2 * p, start, mid)) % MOD;
    return (ans + query(2 * p + 1, mid, end)) % MOD;
  }
};
int main() {
  int n;
  scanf("%d", &n);
  Graph.resize(n);
  for (long long i = 0; i < n - 1; ++i) {
    int x;
    scanf("%d", &x);
    Graph[--x].push_back(i + 1);
  }
  segment_tree ST(n, 0);
  int q;
  scanf("%d", &q);
  for (long long i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &ST.v), scanf("%d", &ST.x), scanf("%d", &ST.k);
      ST.v--;
      ST.update(1, 0, tim);
    } else {
      scanf("%d", &ST.v);
      ST.v--;
      int ans = ST.query(1, 0, tim);
      printf("%d\n", ans);
    }
  }
}
