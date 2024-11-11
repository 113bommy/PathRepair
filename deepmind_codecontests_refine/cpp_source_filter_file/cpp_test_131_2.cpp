#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T>
void chmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void chmax(T &x, T y) {
  x = max(x, y);
}
int n;
int a[200010];
unordered_map<int, int> ID;
unordered_map<int, unordered_set<int> > G;
int one[30];
pair<int, pair<int, int> > ans = make_pair(-1, make_pair(0, 0));
int GetFa(int x) { return *lower_bound(one, one + 30, x) - x; }
pair<int, int> dfs(int x) {
  pair<int, int> tmp =
      ID.count(x) ? make_pair(0, ID[x]) : make_pair(-0x3f3f3f3f, -1);
  for (auto v : G[x]) {
    pair<int, int> qwq = dfs(v);
    qwq.first++;
    chmax(ans,
          make_pair(tmp.first + qwq.first, make_pair(tmp.second, qwq.second)));
    chmax(tmp, qwq);
  }
  return tmp;
}
int main() {
  for (int i = 0; i < 30; i++) {
    one[i] = 1 << i;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int x = a[i];
    ID[x] = i;
    while (x) {
      int fa = GetFa(x);
      G[fa].insert(x);
      x = fa;
    }
  }
  dfs(0);
  printf("%d %d %d\n", ans.second.first, ans.second.second, ans.first);
  return 0;
}
