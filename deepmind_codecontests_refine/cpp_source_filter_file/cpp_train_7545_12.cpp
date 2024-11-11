#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool visited[100005];
int cnt[100005];
vector<int> fortress;
vector<int> g[100005];
double mid;
bool once = false;
bool lvisited[100005];
void rec(int node) {
  visited[node] = true;
  for (auto nnode : g[node]) {
    if (visited[nnode]) continue;
    ++cnt[nnode];
    if (cnt[nnode] > g[nnode].size() * (1.0 - mid) + 1e-4) {
      rec(nnode);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int x;
    scanf("%d", &x);
    fortress.push_back(x - 1);
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  double low = 0.0;
  double high = 1.0;
  while (high - low > 1e-10) {
    mid = (low + high) / 2.0;
    memset(visited, 0, sizeof(visited));
    memset(cnt, 0, sizeof(cnt));
    for (auto node : fortress) {
      if (!visited[node]) {
        rec(node);
      }
    }
    bool found = false;
    for (int i = 0; i < n; ++i)
      if (!visited[i]) found = true;
    if (found) {
      low = mid;
      once = true;
      for (int i = 0; i < n; ++i) lvisited[i] = visited[i];
    } else
      high = mid;
  }
  if (!once) {
    if (n - fortress.size() > 0) {
      printf("1\n");
      sort(fortress.begin(), fortress.end());
      int x = 0;
      int i = 0;
      while (i < fortress.size()) {
        while (i < fortress.size() && fortress[i] < x) ++i;
        if (i == fortress.size() || fortress[i] != x) {
          break;
        }
        ++x;
      }
      printf("%d\n", x + 1);
    } else
      printf("0\n");
  } else {
    int resCnt = 0;
    for (int i = 0; i < n; ++i)
      if (!lvisited[i]) ++resCnt;
    printf("%d\n", resCnt);
    for (int i = 0; i < n; ++i)
      if (!lvisited[i]) printf("%d ", i + 1);
    printf("\n");
  }
  return 0;
}
