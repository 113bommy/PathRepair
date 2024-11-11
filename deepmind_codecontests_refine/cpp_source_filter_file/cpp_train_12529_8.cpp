#include <bits/stdc++.h>
using namespace std;
int n;
int x[100], y[100];
vector<int> a[100];
bool visited[100];
int comp;
void dfs(int node) {
  int i;
  visited[node] = true;
  for (i = 0; i < a[node].size(); i++)
    if (!visited[a[node][i]]) dfs(a[node][i]);
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    for (j = 0; j < i; j++)
      if (x[i] == x[j] || y[i] == y[j]) {
        a[i].push_back(j);
        a[j].push_back(i);
      }
  }
  for (i = 0; i < n; i++)
    if (!visited[i]) {
      comp++;
      dfs(i);
    }
  printf("%d\n", comp + 1);
  return 0;
}
