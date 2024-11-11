#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
const int MAXN = 1e5 + 7;
vector<int> Gin[MAXN], Gout[MAXN];
int n, m, q, w[MAXN], cur;
long long int ret;
void change(int u) {
  ret -= Gin[u].size() * Gout[u].size();
  for (int v : Gin[u]) {
    ret -= Gin[v].size();
    Gout[v].erase(find(Gout[v].begin(), Gout[v].end(), u));
    ret += Gout[v].size();
    Gin[v].emplace_back(u);
    Gout[u].emplace_back(v);
  }
  w[u] = ++cur;
  Gin[u].clear();
}
int main() {
  scanf("%d %d", &n, &m);
  cur = n;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) swap(u, v);
    Gin[u].emplace_back(v);
    Gout[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++) {
    ret += Gin[i].size() * Gout[i].size();
    w[i] = i;
  }
  printf("%d\n", ret);
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    change(x);
    printf("%d\n", ret);
  }
  return 0;
}
