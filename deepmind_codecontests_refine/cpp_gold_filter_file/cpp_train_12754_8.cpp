#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 1;
vector<int> p, cycle, q;
bool mark[MAX_N];
int pr[MAX_N];
int cmp = 0;
int cnt = 0;
void dfs(int node) {
  cnt++;
  mark[node] = true;
  if (!mark[q[node - 1]]) dfs(q[node - 1]);
}
void build(int node) {
  cycle.clear();
  for (int i = 0; i < cnt; i++) {
    cycle.push_back(node);
    node = q[node - 1];
  }
  int mid = (cnt + 1) >> 1;
  for (int i = 0; i < cnt; i++) {
    int mp = (i + mid) % cnt;
    p[cycle[i] - 1] = cycle[mp];
  }
}
void mergeEv(int f, int s) {
  while (p[f - 1] == p[s - 1] && !p[f - 1]) {
    p[f - 1] = s;
    p[s - 1] = q[f - 1];
    f = q[f - 1], s = q[s - 1];
  }
}
int main() {
  int n;
  scanf("%d", &n);
  q.resize(n);
  p.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &q[i]);
  for (int i = 0; i < n; i++) {
    if (!mark[i + 1]) {
      cmp++;
      cnt = 0;
      dfs(i + 1);
      if (cnt % 2) {
        build(i + 1);
      } else if (pr[cnt] != 0) {
        mergeEv(pr[cnt], i + 1);
        pr[cnt] = 0;
      }
      pr[cnt] = i + 1;
    }
  }
  for (int i = 0; i < n; i++)
    if (!p[i]) return printf("-1\n"), 0;
  for (int i = 0; i < n; i++) printf("%d ", p[i]);
  printf("\n");
}
