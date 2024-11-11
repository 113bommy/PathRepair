#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> v[maxn];
int book[maxn];
vector<int> v1, v2;
int flag = 1;
void dfs(int x, int fa) {
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    if (y == fa) continue;
    if (book[x] == 1) {
      if (book[y] == 1) {
        flag = 0;
        return;
      }
      if (book[y] == 0) {
        book[y] = 2;
        dfs(y, x);
      }
    }
    if (book[x] == 2) {
      if (book[y] == 2) {
        flag = 0;
        return;
      }
      if (book[y] == 0) {
        book[y] = 1;
        dfs(y, x);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (book[i] == 0 && v[i].size()) {
      book[i] = 1;
      dfs(1, 0);
    }
  }
  if (flag) {
    for (int i = 1; i <= n; i++) {
      if (book[i] == 1) v1.push_back(i);
      if (book[i] == 2) v2.push_back(i);
    }
    printf("%d\n", v1.size());
    for (auto i : v1) printf("%d ", i);
    printf("\n");
    printf("%d\n", v2.size());
    for (auto i : v2) printf("%d ", i);
  } else
    printf("-1");
}
