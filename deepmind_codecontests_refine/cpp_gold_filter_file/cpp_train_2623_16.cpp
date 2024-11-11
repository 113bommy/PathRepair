#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[100001];
int x[100001], y[100001];
int visited[100001];
int ne[100001];
long long sx[100001];
long long X, Y;
double res;
void dfs(int root) {
  visited[root] = true;
  double c = 0;
  for (int i = 0; i < a[root].size(); i++) {
    int j = a[root][i];
    if (not visited[j]) {
      dfs(j);
      sx[root] += sx[j];
      ne[root] += 1 + ne[j];
      c += (1 + ne[j]) * sx[j];
    }
  }
  sx[root] += x[root];
  c += (n - 1 - ne[root]) * (X - sx[root]);
  res += 1.0 * c / X * y[root];
}
int main() {
  scanf("%d", &n);
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", x + i, y + i);
    X += x[i];
    Y += y[i];
  }
  dfs(1);
  res /= Y;
  printf("%.12f\n", res);
  return 0;
}
