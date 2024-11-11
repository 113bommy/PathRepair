#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int x[N], y[N], c[N], n, m, d[N], good[N];
int fa[N];
vector<pair<int, int> > e[N];
bool cover[N];
int ans[N];
int main() {
  cin >> n >> m;
  memset(d, 0xff, sizeof(d));
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", x + i, y + i, c + i);
    x[i]--;
    y[i]--;
    e[x[i]].push_back(make_pair(y[i], i));
    e[y[i]].push_back(make_pair(x[i], i));
  }
  d[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto p : e[u]) {
      int v = p.first, ind = p.second;
      if (d[v] != -1) {
        if (d[v] == d[u] + 1 && good[v] < good[u]) {
          good[v] = good[u] + c[ind];
          fa[v] = ind;
        }
        continue;
      }
      fa[v] = ind;
      good[v] = good[u] + c[ind];
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
  int k = n - 1;
  while (k) {
    cover[fa[k]] = true;
    k = x[fa[k]] == k ? y[fa[k]] : x[fa[k]];
  }
  k = 0;
  for (int i = 0; i < m; i++) {
    if (cover[i] && !c[i]) {
      ans[k++] = i;
    } else if (!cover[i] && c[i]) {
      ans[k++] = i;
    }
  }
  printf("%d\n", k);
  for (int i = 0; i < k; i++) {
    printf("%d %d %d\n", x[ans[i]] + 1, y[ans[i]] + 1, 1 - c[ans[i]]);
  }
  return 0;
}
