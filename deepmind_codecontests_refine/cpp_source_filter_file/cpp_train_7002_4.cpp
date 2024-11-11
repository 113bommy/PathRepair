#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int n;
long long m;
int h[N], e[M], w[M], cost[M], ne[M], idx;
void add(int a, int b, int c, int d) {
  e[idx] = b, w[idx] = c, cost[idx] = d, ne[idx] = h[a], h[a] = idx++;
}
int fa[N], son[N];
vector<int> leaf;
int dfs(int u, int pa) {
  son[u] = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (j != pa) {
      fa[j] = u;
      son[u] += dfs(j, u);
    }
  }
  if (son[u] == 0) {
    leaf.push_back(u);
    son[u] = 1;
  }
  return son[u];
}
struct cmp {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return (long long)(a.first - a.first / 2) * a.second <
           (long long)(b.first - b.first / 2) * b.second;
  }
};
void dfs2(int u, int fa,
          priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> &heap1,
          priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> &heap2,
          long long &sum1, long long &sum2) {
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (j != fa) {
      if (cost[i] == 1) {
        heap1.push({w[i], son[j]});
        sum1 += (long long)w[i] * son[j];
      } else {
        heap2.push({w[i], son[j]});
        sum2 += (long long)w[i] * son[j];
      }
      dfs2(j, u, heap1, heap2, sum1, sum2);
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(fa, 0, sizeof fa);
    memset(son, 0, sizeof son);
    idx = 0;
    leaf.clear();
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      add(a, b, c, d);
      add(b, a, c, d);
    }
    dfs(1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> heap1, heap2;
    long long sum1 = 0, sum2 = 0;
    dfs2(1, 0, heap1, heap2, sum1, sum2);
    vector<long long> v1, v2;
    v1.push_back(sum1);
    v2.push_back(sum2);
    while (sum1) {
      auto t = heap1.top();
      heap1.pop();
      sum1 -= (long long)(t.first - t.first / 2) * t.second;
      heap1.push({t.first / 2, t.second});
      v1.push_back(sum1);
    }
    while (sum2) {
      auto t = heap2.top();
      heap2.pop();
      sum2 -= (long long)(t.first - t.first / 2) * t.second;
      heap2.push({t.first / 2, t.second});
      v2.push_back(sum2);
    }
    int cnt = 0x3f3f3f3f;
    int a = v1.size(), b = v2.size();
    for (int i = 0; i < a; ++i) {
      int l = 0, r = b - 1;
      int k = m - v1[i];
      while (l < r) {
        int mid = l + r >> 1;
        if (v2[mid] <= k)
          r = mid;
        else
          l = mid + 1;
      }
      if (v1[i] + v2[r] <= m) cnt = min(cnt, i + r * 2);
    }
    cout << cnt << endl;
  }
  return 0;
}
