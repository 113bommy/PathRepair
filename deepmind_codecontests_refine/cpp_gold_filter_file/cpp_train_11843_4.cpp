#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int nax = 1000 * 1007;
int n, m;
vector<int> graf[nax];
int wyn[nax];
int bylo[nax];
int licz;
int odj[nax];
int dfs(int v) {
  if (bylo[v]) {
    if (bylo[v] == 1) {
      licz++;
      odj[v]++;
      return 1;
    }
    return 0;
  }
  int ret = 0;
  bylo[v] = 1;
  for (int i : graf[v]) ret += dfs(i);
  bylo[v] = 2;
  wyn[v] += ret;
  return ret - odj[v];
}
int kol[nax];
void test() {
  scanf("%d%d", &n, &m);
  licz = 0;
  for (int i = 1; i <= n; i++) {
    graf[i].clear();
    bylo[i] = 0;
    wyn[i] = 0;
    odj[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    graf[a].push_back(b);
  }
  for (int h = 0; h < 15; h++) {
    for (int i = 1; i <= n; i++) {
      bylo[i] = 0;
      kol[i] = i;
      odj[i] = 0;
      random_shuffle(graf[i].begin(), graf[i].end());
    }
    random_shuffle(kol + 1, kol + 1 + n);
    for (int i = 1; i <= n; i++) dfs(kol[i]);
  }
  vector<int> wek;
  for (int i = 1; i <= n; i++)
    if (wyn[i] == licz) wek.push_back(i);
  wek.push_back(-1);
  for (int i : wek) {
    printf("%d", i);
    break;
  }
}
int main() {
  int t = 1;
  while (t--) test();
  return 0;
}
