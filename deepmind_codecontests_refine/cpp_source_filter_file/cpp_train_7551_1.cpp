#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 100000 + 10;
int n;
vector<int> G[N];
int son_size[N];
double ans[N];
void init() {
  for (int i = 1; i <= n; ++i) G[i].clear();
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    G[x].push_back(i);
  }
  memset(ans, 0, sizeof(ans));
}
void get_son(int u) {
  son_size[u] = 1;
  int siz = G[u].size();
  for (int i = 0; i < siz; ++i) {
    int v = G[u][i];
    get_son(v);
    son_size[u] += son_size[v];
  }
}
void get_ans(int u) {
  int siz = G[u].size();
  for (int i = 0; i < siz; ++i) {
    int v = G[u][i];
    double d = siz > 1 ? 1.0 * (son_size[u] - son_size[v] - 1) / (siz - 1) : 0;
    ans[v] = ans[u] + 1.0 / siz * (siz + siz * (siz - 1) / 2 * d);
    get_ans(v);
  }
}
void deal() {
  get_son(1);
  ans[1] = 1;
  get_ans(1);
}
int main() {
  scanf("%d", &n);
  init();
  deal();
  for (int i = 1; i <= n; ++i) {
    if (i != 1) printf(" ");
    printf("%.20f", ans[i]);
  }
  return 0;
}
