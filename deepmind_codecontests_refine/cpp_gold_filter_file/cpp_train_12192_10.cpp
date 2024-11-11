#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
struct BipartiteGraph {
  int nl, nr;
  vector<vector<int>> ladj;
  void init(int _nl, int _nr) {
    nl = _nl, nr = _nr;
    ladj = vector<vector<int>>(nl);
  }
};
struct MaximumBipartiteMatching {
  bool solved;
  BipartiteGraph *g;
  vector<bool> been;
  vector<int> dist;
  vector<int> lmatch, rmatch;
  void init(BipartiteGraph *_g) {
    g = _g;
    solved = false;
  }
  bool augment(int at) {
    if (been[at])
      return false;
    else
      been[at] = true;
    for (int i = (0); i < (((int)(g->ladj[at]).size())); ++i) {
      int oth = g->ladj[at][i], to = rmatch[oth];
      if (to == -1 || dist[to] == dist[at] + 1 && augment(to)) {
        lmatch[at] = oth;
        rmatch[oth] = at;
        return true;
      }
    }
    return false;
  }
  int solve() {
    solved = true;
    lmatch = vector<int>(g->nl, -1);
    rmatch = vector<int>(g->nr, -1);
    dist = vector<int>(g->nl, INT_MAX);
    been = vector<bool>(g->nl, false);
    int ret = 0;
    while (true) {
      queue<int> q;
      int unmatcheddist = INT_MAX;
      for (int i = (0); i < (g->nl); ++i)
        if (lmatch[i] != -1)
          dist[i] = INT_MAX;
        else
          dist[i] = 0, q.push(i);
      while (!q.empty()) {
        int at = q.front();
        q.pop();
        if (dist[at] > unmatcheddist) continue;
        for (int i = (0); i < (((int)(g->ladj[at]).size())); ++i) {
          int to = rmatch[g->ladj[at][i]];
          if (to == -1)
            unmatcheddist = dist[at];
          else if (dist[to] == INT_MAX)
            dist[to] = dist[at] + 1, q.push(to);
        }
      }
      if (unmatcheddist == INT_MAX) break;
      for (int i = (0); i < (g->nl); ++i) been[i] = false;
      for (int i = (0); i < (g->nl); ++i)
        if (lmatch[i] == -1 && augment(i)) ++ret;
    }
    return ret;
  }
  vector<pair<int, int>> getMatching() {
    if (!solved) solve();
    vector<pair<int, int>> ret;
    for (int i = (0); i < (g->nl); ++i)
      if (lmatch[i] != -1) ret.push_back(make_pair(i, lmatch[i]));
    return ret;
  }
  pair<vector<int>, vector<int>> getMinVertexCover() {
    if (!solved) solve();
    vector<int> lcover;
    for (int i = (0); i < (g->nl); ++i)
      if (dist[i] == INT_MAX) lcover.push_back(i);
    vector<int> rcover;
    for (int i = (0); i < (g->nr); ++i)
      if (rmatch[i] != -1 && dist[rmatch[i]] != INT_MAX) rcover.push_back(i);
    return make_pair(lcover, rcover);
  }
  pair<vector<int>, vector<int>> getMaxIndependentSet() {
    if (!solved) solve();
    vector<int> lset;
    for (int i = (0); i < (g->nl); ++i)
      if (dist[i] != INT_MAX) lset.push_back(i);
    vector<int> rset;
    for (int i = (0); i < (g->nr); ++i)
      if (rmatch[i] == -1 || dist[rmatch[i]] == INT_MAX) rset.push_back(i);
    return make_pair(lset, rset);
  }
};
struct P {
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
};
struct XSeg {
  int x, ly, hy;
  XSeg() {}
  XSeg(int x, int ly, int hy) : x(x), ly(ly), hy(hy) {}
};
struct YSeg {
  int y, lx, hx;
  YSeg() {}
  YSeg(int y, int lx, int hx) : y(y), lx(lx), hx(hx) {}
};
bool intersect(const XSeg &a, const YSeg &b) {
  return a.ly < b.y && b.y < a.hy && b.lx < a.x && a.x < b.hx;
}
struct Points2SegsConvertor {
  vector<int> fst, snd;
  vector<int> prv, nxt;
  vector<pair<int, pair<int, int>>> solve(
      vector<pair<pair<int, int>, int>> &lst) {
    prv = nxt = vector<int>(((int)(lst).size()), -1);
    fst.clear();
    snd.clear();
    vector<pair<int, pair<int, int>>> ret;
    sort(lst.begin(), lst.end());
    for (int i = (0); i < (((int)(lst).size())); ++i)
      if (i + 1 < ((int)(lst).size()) &&
          lst[i].first.first == lst[i + 1].first.first) {
        nxt[lst[i].second] = prv[lst[i + 1].second] = ((int)(ret).size());
        fst.push_back(lst[i].second);
        snd.push_back(lst[i + 1].second);
        ret.push_back(
            make_pair(lst[i].first.first,
                      make_pair(lst[i].first.second, lst[i + 1].first.second)));
      }
    return ret;
  }
  vector<XSeg> makeXSegs(vector<P> p) {
    vector<pair<pair<int, int>, int>> byx;
    for (int i = (0); i < (((int)(p).size())); ++i)
      byx.push_back(make_pair(make_pair(p[i].x, p[i].y), i));
    auto res = solve(byx);
    vector<XSeg> ret;
    for (int i = (0); i < (((int)(res).size())); ++i)
      ret.push_back(
          XSeg(res[i].first, res[i].second.first, res[i].second.second));
    return ret;
  }
  vector<YSeg> makeYSegs(vector<P> p) {
    vector<pair<pair<int, int>, int>> byy;
    for (int i = (0); i < (((int)(p).size())); ++i)
      byy.push_back(make_pair(make_pair(p[i].y, p[i].x), i));
    auto res = solve(byy);
    vector<YSeg> ret;
    for (int i = (0); i < (((int)(res).size())); ++i)
      ret.push_back(
          YSeg(res[i].first, res[i].second.first, res[i].second.second));
    return ret;
  }
};
const int MAXN = 1000;
int n;
vector<P> p;
Points2SegsConvertor xconv, yconv;
vector<XSeg> xseg;
vector<YSeg> yseg;
BipartiteGraph bg;
MaximumBipartiteMatching solver;
vector<bool> xused;
vector<bool> yused;
vector<XSeg> xans;
vector<YSeg> yans;
void solve() {
  xseg = xconv.makeXSegs(p);
  yseg = yconv.makeYSegs(p);
  bg.init(((int)(xseg).size()), ((int)(yseg).size()));
  for (int i = (0); i < (((int)(xseg).size())); ++i)
    for (int j = (0); j < (((int)(yseg).size())); ++j)
      if (intersect(xseg[i], yseg[j])) bg.ladj[i].push_back(j);
  solver.init(&bg);
  pair<vector<int>, vector<int>> res = solver.getMaxIndependentSet();
  xused = vector<bool>(((int)(xseg).size()), false);
  for (int i = (0); i < (((int)(res.first).size())); ++i)
    xused[res.first[i]] = true;
  yused = vector<bool>(((int)(yseg).size()), false);
  for (int i = (0); i < (((int)(res.second).size())); ++i)
    yused[res.second[i]] = true;
  xans.clear();
  for (int i = (0); i < (n); ++i)
    if (xconv.prv[i] == -1 || !xused[xconv.prv[i]]) {
      int j = i;
      while (xconv.nxt[j] != -1 && xused[xconv.nxt[j]])
        j = xconv.snd[xconv.nxt[j]];
      xans.push_back(XSeg(p[i].x, p[i].y, p[j].y));
    }
  yans.clear();
  for (int i = (0); i < (n); ++i)
    if (yconv.prv[i] == -1 || !yused[yconv.prv[i]]) {
      int j = i;
      while (yconv.nxt[j] != -1 && yused[yconv.nxt[j]])
        j = yconv.snd[yconv.nxt[j]];
      yans.push_back(YSeg(p[i].y, p[i].x, p[j].x));
    }
}
void run() {
  scanf("%d", &n);
  p.clear();
  for (int i = (0); i < (n); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    p.push_back(P(x, y));
  }
  solve();
  printf("%d\n", ((int)(yans).size()));
  for (int i = (0); i < (((int)(yans).size())); ++i)
    printf("%d %d %d %d\n", yans[i].lx, yans[i].y, yans[i].hx, yans[i].y);
  printf("%d\n", ((int)(xans).size()));
  for (int i = (0); i < (((int)(xans).size())); ++i)
    printf("%d %d %d %d\n", xans[i].x, xans[i].ly, xans[i].x, xans[i].hy);
}
int main() {
  run();
  return 0;
}
