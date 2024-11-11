#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using VI = vector<int>;
template <typename T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <typename T, typename... X>
void R(T &head, X &...tail) {
  _R(head);
  R(tail...);
}
const int N = 200005;
vector<int> e[N], path;
int vis[N];
void dfs(int from, int now) {
  vis[now] = 1;
  path.push_back(now);
  for (auto next : e[now])
    if (!vis[next]) {
      dfs(now, next);
      path.push_back(now);
    }
}
int main() {
  int n, m, k;
  R(n, m, k);
  for (int i = 0; i < m; i++) {
    int x, y;
    R(x, y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(0, 1);
  int r = (2 * n + k - 1) / k, len = path.size();
  for (int i = 0, ptr = 0; i < k; i++, ptr += r) {
    if (ptr >= len) {
      puts("1 1");
      continue;
    }
    int x = min(r, len - ptr);
    printf("%d", x);
    for (int j = ptr; j < ptr + x; j++) printf(" %d", path[j]);
    puts("");
  }
  return 0;
}
