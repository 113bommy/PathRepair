#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 1000;
vector<int> G[maxn], ans[maxn];
set<int> s;
set<int>::iterator ite;
int num[maxn], cnt, res;
void bfs(int x) {
  s.erase(x);
  queue<int> que;
  ans[res].push_back(x);
  que.push(x);
  cnt = 0;
  while (que.size()) {
    int cur = que.front();
    que.pop();
    cnt = 0;
    for (ite = s.begin(); ite != s.end(); ite++) {
      int next = *ite;
      if (!binary_search(G[cur].begin(), G[cur].end(), *ite)) {
        que.push(next);
        ans[res].push_back(next);
        num[cnt++] = next;
      }
    }
    for (int i = 0; i < cnt; i++) s.erase(num[i]);
  }
  res++;
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
      s.insert(i);
      sort(G[i].begin(), G[i].end());
    }
    res = 1;
    for (int i = 1; i <= n; i++) {
      if (s.count(i)) bfs(i);
    }
    printf("%d\n", res - 1);
    for (int i = 1; i <= res; i++) {
      if (ans[i].size()) {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++) {
          if (j == ans[i].size() - 1)
            printf("%d\n", ans[i][j]);
          else
            printf("%d ", ans[i][j]);
        }
      }
    }
  }
  return 0;
}
