#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int ZERO = 2e5 + 5000;
int n, w, h;
struct node {
  int id, x, t;
  node() {}
  node(int _id, int _x, int _t) : id(_id), x(_x), t(_t) {}
  bool operator<(const node &a) const { return x < a.x; }
} X[MAXN];
vector<node> Y[MAXN * 4];
int cnt[MAXN * 4];
pair<int, int> ans[MAXN];
int main() {
  scanf("%d%d%d", &n, &w, &h);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    int g, p, t;
    scanf("%d%d%d", &g, &p, &t);
    if (g == 1) {
      X[++tot] = node(i, p, t);
    } else {
      Y[p - t + ZERO].push_back(node(i, p, t));
    }
  }
  sort(X + 1, X + 1 + tot);
  for (int i = 0; i < 4 * MAXN; i++) {
    sort(Y[i].begin(), Y[i].end());
  }
  for (int i = 1; i <= tot; i++) {
    int pos = X[i].x - X[i].t + ZERO;
    int sz = Y[pos].size();
    if (sz) {
      int en = ((sz - cnt[pos] - 1) % sz + sz) % sz;
      swap(Y[pos][en].id, X[i].id);
      cnt[pos]++;
    }
    ans[X[i].id] = make_pair(X[i].x, h);
  }
  for (int i = 0; i < 4 * MAXN; i++) {
    int sz = Y[i].size();
    for (int j = 0; j < sz; j++) {
      int pos = (((sz - cnt[i] - 1) % sz + sz) % sz + j + 1) % sz;
      ans[Y[i][pos].id] = make_pair(w, Y[i][j].x);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
