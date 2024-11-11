#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const int N = 2e5 + 100;
vector<int> g[N];
int us[N];
vector<pair<pair<int, int>, int> > resp;
int tempo = 1;
pair<int, int> dfs(int u, int last) {
  us[u] = tempo++;
  vector<int> tras;
  for (int v : g[u]) {
    if (!us[v]) {
      pair<int, int> aux = dfs(v, u);
      if (aux.first != -1) {
        resp.push_back(make_pair(make_pair(aux.second, aux.first), u));
      } else {
        tras.push_back(v);
      }
    } else if (v != last and us[v] < us[u]) {
      tras.push_back(v);
    }
  }
  if (tras.size() % 2 == 0) {
    for (int i = 0; i + 1 < tras.size(); i += 2) {
      int x = tras[i];
      int y = tras[i + 1];
      resp.push_back(make_pair(make_pair(x, u), y));
    }
    return make_pair(-1, -1);
  }
  for (int i = 0; i + 1 < (int)tras.size(); i += 2) {
    int x = tras[i];
    int y = tras[i + 1];
    resp.push_back(make_pair(make_pair(x, u), y));
  }
  return make_pair(tras.back(), u);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!us[i]) {
      dfs(i, i);
    }
  }
  printf("%d\n", (int)resp.size());
  for (auto x : resp) {
    printf("%d ", x.first.first);
    printf("%d ", x.first.second);
    printf("%d\n", x.second);
  }
  return 0;
}
