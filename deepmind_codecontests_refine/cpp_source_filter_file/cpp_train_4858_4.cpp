#include <bits/stdc++.h>
using namespace std;
const int N = 15000 + 5;
int n;
int x1, __asd, x2, __bsd, cnt;
pair<int, int> a[N];
vector<int> add[N * 2], del[N * 2];
vector<pair<pair<int, int>, int> > v[N];
map<int, int> h;
void dfs(int x1, int __asd, int __bsd, int id) {
  h[id] = 1;
  for (auto tmp : v[x1 + 1]) {
    if (tmp.first.second < __asd or __bsd < tmp.first.first) continue;
    if (!h[tmp.second])
      dfs(x1 + 1, tmp.first.first, tmp.first.second, tmp.second);
  }
  if (x1 > 0)
    for (auto tmp : v[x1 - 1]) {
      if (tmp.first.second < __asd or __bsd < tmp.first.first) continue;
      if (!h[tmp.second])
        dfs(x1 - 1, tmp.first.first, tmp.first.second, tmp.second);
    }
}
int main() {
  scanf("%d %d %d %d", &x1, &__asd, &x2, &__bsd);
  swap(__asd, __bsd);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  a[n + 1] = a[1];
  for (int i = 1; i <= n; i++) {
    pair<int, int> x = a[i], y = a[i + 1];
    if (x.first == y.first) continue;
    if (x.first > y.first) swap(x, y);
    add[x.first].push_back(x.second);
    del[y.first].push_back(x.second);
  }
  map<int, int> M;
  for (int i = 0; i < x2; i++) {
    for (auto x : add[i]) {
      if (x > __asd) {
        M[x]++;
      }
    }
    for (auto x : del[i]) {
      if (x > __asd) {
        M.erase(x);
      }
    }
    if (M.empty() or i < x1) continue;
    int cur = M.size();
    int last = __asd;
    for (auto x : M) {
      if (cur % 2) {
        v[i].push_back({{last, min(__bsd - 1, x.first - 1)}, ++cnt});
      }
      if (x.first > __bsd) break;
      cur--;
      last = x.first;
    }
  }
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    for (auto &x : v[i]) {
      if (!h[x.second]) {
        ans++;
        dfs(i, x.first.first, x.first.second, x.second);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
