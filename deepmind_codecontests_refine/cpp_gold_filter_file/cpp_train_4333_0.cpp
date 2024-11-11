#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 213;
const int MOD = (int)1e9 + 7;
const int inf = (int)5e8;
const long long infll = (long long)1e17;
int n, w, h;
int x[N];
int y[N];
struct Positions {
  int x;
  int y;
  Positions() = default;
  Positions(int x, int y) : x(x), y(y) {}
};
struct Dancer {
  int g;
  int p;
  int t;
  int id;
  Positions finish;
  int inter_func;
  Dancer() = default;
  Dancer(int g, int p, int t, int id) : g(g), p(p), t(t), id(id) {
    inter_func = t - p;
    if (g == 0) {
      finish = Positions(p, h);
    } else {
      finish = Positions(w, p);
    }
  }
};
map<int, Dancer> dancer;
map<int, int> rot[2];
map<int, vector<int>> dancers_by_func[2];
int add(int a, int b, int mod) { return ((a + b) % mod + mod) % mod; }
void solve() {
  scanf("%d %d %d", &n, &w, &h);
  vector<int> order;
  for (int i = 0; i < n; ++i) {
    int g, p, t;
    scanf("%d %d %d", &g, &p, &t);
    --g;
    dancer[i] = Dancer(g, p, t, i);
    dancers_by_func[g][dancer[i].inter_func].push_back(i);
    if (g == 0) {
      order.push_back(i);
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (auto& j : dancers_by_func[i]) {
      sort(j.second.begin(), j.second.end(), [](int a, int b) {
        if (dancer[a].p == dancer[b].p) return dancer[a].t < dancer[b].t;
        return dancer[a].p < dancer[b].p;
      });
    }
  }
  sort(order.begin(), order.end(), [](int a, int b) {
    if (dancer[a].p == dancer[b].p) return dancer[a].t < dancer[b].t;
    return dancer[a].p < dancer[b].p;
  });
  for (auto i : order) {
    auto& now = dancers_by_func[1][dancer[i].inter_func];
    int r = rot[1][dancer[i].inter_func];
    if (now.size() > 0) {
      int last_id = add(now.size() - 1, -r, now.size());
      swap(dancer[i].id, dancer[now[last_id]].id);
    }
    ++rot[1][dancer[i].inter_func];
  }
  for (auto i : dancers_by_func[1]) {
    auto& now = i.second;
    vector<int> new_ids(now.size());
    int r = rot[1][i.first];
    for (int i = 0; i < now.size(); ++i) {
      new_ids[add(i, +r, now.size())] = dancer[now[i]].id;
    }
    for (int i = 0; i < now.size(); ++i) {
      dancer[now[i]].id = new_ids[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    int id = dancer[i].id;
    x[id] = dancer[i].finish.x;
    y[id] = dancer[i].finish.y;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", x[i], y[i]);
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
