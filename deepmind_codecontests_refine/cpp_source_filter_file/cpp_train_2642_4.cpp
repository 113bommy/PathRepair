#include <bits/stdc++.h>
using namespace std;
int n, m;
bool use[300100];
int color[300100];
vector<int> a[300100];
inline void push(int v) {
  int kol = 0;
  int to = 0;
  for (int i = 0; i < int(a[v].size()); i++) {
    if (color[a[v][i]] == color[v])
      kol++;
    else
      to = a[v][i];
  }
  if (kol >= 2) {
    color[v] = 1 - color[v];
    if (color[to] >= 0) push(to);
  }
}
void dfs(int v, int col) {
  use[v] = true;
  color[v] = col;
  for (int i = 0; i < int(a[v].size()); i++) {
    int to = a[v][i];
    if (use[to]) {
      push(to);
      continue;
    }
    dfs(to, 1 - col);
  }
}
int main() {
  memset(color, -1, sizeof(color));
  cin >> n >> m;
  for (int i = 0; i < int(m); i++) {
    int t1, t2;
    scanf("%d %d", &t1, &t2);
    t1--;
    t2--;
    a[t1].push_back(t2);
    a[t2].push_back(t1);
  }
  for (int i = 0; i < int(n); i++)
    if (!use[i]) dfs(i, 0);
  for (int i = 0; i < int(n); i++) cout << color[i] << endl;
  return 0;
}
