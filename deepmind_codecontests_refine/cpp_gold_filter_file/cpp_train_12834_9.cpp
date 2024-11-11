#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 20;
unordered_set<int> V[MAXN];
set<pair<int, int> > st;
int n, m, k;
void solve() {
  pair<int, int> tmp;
  while (!st.empty()) {
    tmp = *st.begin();
    int u = tmp.second;
    int d = tmp.first;
    if (d >= k) {
      printf("%d %d\n", 1, st.size());
      for (auto x : st) printf("%d ", x.second);
      printf("\n");
      return;
    } else if (d == k - 1) {
      int ok = 1;
      for (auto x : V[u]) {
        for (auto y : V[u]) {
          if (y != x && !V[y].count(x)) {
            ok = 0;
            break;
          }
        }
        if (ok == 0) break;
      }
      if (ok) {
        printf("2\n");
        printf("%d ", u);
        for (auto x : V[u]) printf("%d ", x);
        printf("\n");
        return;
      }
    }
    st.erase(tmp);
    for (auto x : V[u]) {
      if (st.count(pair<int, int>(V[x].size(), x))) {
        st.erase(pair<int, int>(V[x].size(), x));
        V[x].erase(u);
        st.insert(pair<int, int>(V[x].size(), x));
      }
    }
  }
  printf("-1\n");
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d%d%d", &n, &m, &k);
    st.clear();
    for (int i = 1; i <= n; i++) V[i].clear();
    int u, v;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &u, &v);
      V[u].insert(v);
      V[v].insert(u);
    }
    for (int i = 1; i <= n; i++) st.insert(pair<int, int>(V[i].size(), i));
    solve();
  }
}
