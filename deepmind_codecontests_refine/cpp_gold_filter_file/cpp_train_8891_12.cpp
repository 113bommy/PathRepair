#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:267386880")
using namespace std;
const int N = 200005;
struct tree {
  void inc(int from, int to, int delta) {
    add(from, delta);
    add(to + 1, -delta);
  }
  int getValue(int pos) { return get(pos); }

 private:
  int data[N];
  void add(int pos, int delta) {
    for (; pos < N; pos |= pos + 1) data[pos] += delta;
  }
  int get(int pos) {
    int res(0);
    for (; pos >= 0; pos = ((pos & (pos + 1)) - 1)) res += data[pos];
    return res;
  }
};
tree t[2];
vector<int> order[2];
vector<pair<int, int> > q[2];
vector<int> data;
vector<int> whr;
vector<vector<int> > g;
void dfs(int v, bool cur) {
  whr[v] = cur;
  int curStart(((int)order[cur].size())), curFinish(((int)order[cur].size())),
      aStart(((int)order[cur ^ 1].size())),
      aFinish(((int)order[cur ^ 1].size()) - 1);
  order[cur].push_back(data[v]);
  for (int i(0); i <= ((long long)(((int)g[v].size())) - 1); ++i) {
    int to(g[v][i]);
    dfs(to, cur ^ 1);
    curFinish = max(curFinish, q[cur][to].second);
    aFinish = max(aFinish, q[cur ^ 1][to].second);
  }
  q[cur][v] = make_pair(curStart, curFinish);
  q[cur ^ 1][v] = make_pair(aStart, aFinish);
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  q[0].resize(n);
  q[1].resize(n);
  data.resize(n);
  whr.resize(n);
  for (int i(0); i <= ((long long)(n)-1); ++i) scanf("%d", &data[i]);
  for (int i(0); i <= ((long long)(n - 1) - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].push_back(b);
  }
  dfs(0, 0);
  for (int q(0); q <= ((long long)(2) - 1); ++q)
    for (int i(0); i <= ((long long)(((int)order[q].size())) - 1); ++i) {
      t[q].inc(i, i, order[q][i]);
    }
  for (int i(0); i <= ((long long)(m)-1); ++i) {
    int c, v;
    scanf("%d%d", &c, &v);
    --v;
    if (c == 1) {
      int delta;
      scanf("%d", &delta);
      for (int w(0); w <= ((long long)(2) - 1); ++w)
        t[w].inc(q[w][v].first, q[w][v].second, (w == whr[v] ? delta : -delta));
    } else {
      int ans(t[whr[v]].getValue(q[whr[v]][v].first));
      printf("%d\n", ans);
    }
  }
}
void bruteforce() {}
int main() {
  solve();
  bruteforce();
  return 0;
}
