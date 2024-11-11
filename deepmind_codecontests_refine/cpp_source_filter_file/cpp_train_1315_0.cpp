#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int src, dst;
  Edge(int src, int dst) : src(src), dst(dst) {}
};
void visit(const vector<vector<Edge> >& g, int v, int u, vector<Edge>& brdg,
           vector<vector<int> >& tecomp, stack<int>& roots, stack<int>& S,
           vector<bool>& inS, vector<int>& num, int& time) {
  num[v] = ++time;
  S.push(v);
  inS[v] = true;
  roots.push(v);
  for (__typeof((g[v]).begin()) e = (g[v]).begin(); e != (g[v]).end(); ++e) {
    int w = e->dst;
    if (num[w] == 0)
      visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
    else if (u != w && inS[w])
      while (num[roots.top()] > num[w]) roots.pop();
  }
  if (v == roots.top()) {
    brdg.push_back(Edge(u, v));
    tecomp.push_back(vector<int>());
    while (1) {
      int w = S.top();
      S.pop();
      inS[w] = false;
      tecomp.back().push_back(w);
      if (v == w) break;
    }
    roots.pop();
  }
}
void bridge(const vector<vector<Edge> >& g, vector<Edge>& brdg,
            vector<vector<int> >& tecomp) {
  const int n = g.size();
  vector<int> num(n);
  vector<bool> inS(n);
  stack<int> roots, S;
  int time = 0;
  for (int u = 0; u < (int)n; ++u)
    if (num[u] == 0) {
      visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
      brdg.pop_back();
    }
}
int belong[300010];
int cnt[300010];
int sz[300010];
int rightMost[300010];
int loopCnt = 0;
void add(int gId) {
  if (sz[gId] == 1) return;
  cnt[gId]++;
  if (cnt[gId] == sz[gId]) {
    loopCnt++;
  }
}
void dec(int gId) {
  if (sz[gId] == 1) return;
  if (cnt[gId] == sz[gId]) {
    loopCnt--;
  }
  cnt[gId]--;
}
long long cumsum[300010];
long long computeSum(int a, int b) {
  return cumsum[b] - (a ? cumsum[a - 1] : 0);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge> > g(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].push_back(Edge(a, b));
    g[b].push_back(Edge(b, a));
  }
  vector<Edge> brdg;
  vector<vector<int> > tecomp;
  bridge(g, brdg, tecomp);
  for (int i = 0; i < tecomp.size(); i++) {
    for (int j : tecomp[i]) {
      belong[j] = i;
    }
    sz[i] = tecomp[i].size();
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    while (r < n) {
      add(belong[r]);
      if (loopCnt > 0) {
        dec(belong[r]);
        break;
      }
      r++;
    }
    rightMost[i] = r;
    cumsum[i] = r - i;
    dec(belong[i]);
  }
  for (int i = 1; i < n; i++) {
    cumsum[i] = cumsum[i - 1] + cumsum[i];
  }
  auto f = [&](int L, int R) {
    int l = L, r = n;
    while (l != r) {
      int m = (l + r) / 2;
      if (m == n || rightMost[m] > R) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    assert(!(l == n) || rightMost[l - 1] == R);
    return l - 1;
  };
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    int rInclusive = f(a, b);
    long long sum = 0;
    if (rInclusive >= a) {
      sum += computeSum(a, rInclusive);
    }
    int overStartInclusive = rInclusive + 1;
    int overCount = b - overStartInclusive;
    sum += 1ll * (b - overStartInclusive) * overCount -
           1ll * (overCount * (overCount - 1) / 2);
    printf("%lld\n", sum);
  }
}
