#include <bits/stdc++.h>
using namespace std;
struct p {
  int parent, rank;
} subsets[100005];
struct st {
  int x, y, c;
} lovers[100005];
int color[100005];
int find(int x) {
  if (subsets[x].parent != x) subsets[x].parent = find(subsets[x].parent);
  return subsets[x].parent;
}
void Union(int x, int y) {
  int xset = find(x);
  int yset = find(y);
  if (xset != yset) {
    if (subsets[xset].rank > subsets[yset].rank)
      subsets[yset].parent = xset;
    else if (subsets[xset].rank < subsets[yset].rank)
      subsets[xset].parent = yset;
    else {
      subsets[yset].parent = xset;
      subsets[xset].rank++;
    }
  }
}
bool vis[100005];
vector<int> graph[100005];
bool dfs(int i, int colo) {
  if (!vis[i]) {
    vis[i] = true;
    color[i] = colo;
  } else {
    if (color[i] == 1 - colo) return false;
    return true;
  }
  for (typeof(graph[i].begin()) it = graph[i].begin(); it != graph[i].end();
       it++) {
    int v = *it;
    if (!dfs(v, 1 - colo)) return false;
  }
  return true;
}
int main() {
  int n, m, i, j, k;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 1; i < m + 1; i++) {
    int x, y, c;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &c);
    lovers[i].x = x;
    lovers[i].y = y;
    lovers[i].c = c;
  }
  for (i = 1; i < n + 1; i++) {
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }
  for (i = 1; i < m + 1; i++) {
    if (lovers[i].c) {
      Union(lovers[i].x, lovers[i].y);
    }
  }
  for (i = 1; i < m + 1; i++) {
    if (!lovers[i].c) {
      int xset = find(lovers[i].x);
      int yset = find(lovers[i].y);
      if (xset == yset) {
        printf("0\n");
        return 0;
      }
      graph[xset].push_back(yset);
      graph[yset].push_back(xset);
    }
  }
  int count = 0;
  for (i = 1; i < n + 1; i++) {
    if (find(i) == i && vis[i] == false) {
      if (!dfs(i, 0)) {
        printf("0\n");
        return 0;
      }
      count++;
    }
  }
  long long res = 1;
  for (i = 1; i < count; i++) {
    res *= 2LL;
    res %= 1000000007;
  }
  printf("%I64d\n", res);
}
