#include <bits/stdc++.h>
using namespace std;
int n, x[200005], y[200005];
vector<int> bro[200004];
int color[200005];
void go(int u, int c) {
  if (color[u] != -1) return;
  color[u] = c;
  int v;
  for (int i = 0; i < bro[u].size(); i++) {
    v = bro[u][i];
    go(v, c ^ 1);
  }
}
int main() {
  memset(color, -1, sizeof(color));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    bro[x[i]].push_back(y[i]);
    bro[y[i]].push_back(x[i]);
  }
  for (int i = 1; i < n; i++) {
    bro[2 * i].push_back(2 * i + 1);
    bro[2 * i + 1].push_back(2 * i);
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (color[i] == -1) go(i, 1);
  }
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", 1 + color[x[i]], 1 + color[y[i]]);
  return 0;
}
