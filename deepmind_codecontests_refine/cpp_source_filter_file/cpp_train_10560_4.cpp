#include <bits/stdc++.h>
using namespace std;
const int knmax = 401337;
class edg {
 public:
  int x, y, color;
  edg(){};
  edg(int a1, int a2) {
    x = a1;
    y = a2;
    color = -1;
  }
  int nbr(int x1) {
    if (x == x1) return y;
    return x;
  }
};
vector<int> g[knmax];
vector<edg> t;
int evis[knmax * 5], nvis[knmax];
vector<int> ans;
void dfs(int x) {
  nvis[x] = 1;
  for (int i = 0; i < g[x].size(); ++i)
    if (!evis[g[x][i]]) {
      evis[g[x][i]] = 1;
      dfs(t[g[x][i]].nbr(x));
    }
  ans.push_back(x);
}
class seg {
 public:
  int x, y;
  seg(){};
  seg(int x1, int y1) {
    x = x1;
    y = y1;
  }
};
int nAt, nSg;
seg gv[knmax];
vector<int> atomz;
class hdata {
 public:
  int x, y, num;
  hdata(){};
  hdata(int x1, int y1, int n1) {
    x = x1;
    y = y1;
    num = n1;
  }
  bool operator==(hdata other) { return x == other.x && y == other.y; }
};
const int kmod = 666013, kp1 = 29, kp2 = 37;
vector<hdata> h[kmod];
int make_key(int x, int y) { return (x * kp1 + y * kp2) % kmod; }
void insert(hdata x) {
  int key = make_key(x.x, x.y);
  h[key].push_back(x);
}
void color(int x, int y, int col) {
  hdata now(x, y, 1337);
  int key = make_key(x, y);
  for (int i = 0; i < h[key].size(); ++i)
    if (h[key][i] == now) {
      t[h[key][i].num].color = col;
      swap(h[key].back(), h[key][i]);
      h[key].pop_back();
      return;
    }
}
int deg[knmax];
void new_edge(int x, int y) {
  t.push_back(edg(x, y));
  g[x].push_back(t.size() - 1);
  g[y].push_back(t.size() - 1);
  ++deg[y];
  ++deg[x];
  insert(hdata(x, y, (int)t.size() - 1));
}
void make_edges() {
  for (int i = 1; i <= nSg; ++i) {
    int a, b;
    int l = 0, r = nAt, mid, last;
    while (l <= r) {
      mid = (l + r) / 2;
      if (atomz[mid] > gv[i].x)
        r = mid - 1;
      else {
        l = mid + 1;
        last = mid;
      }
    }
    a = last;
    l = 0;
    r = nAt;
    while (l <= r) {
      mid = (l + r) / 2;
      if (atomz[mid] > gv[i].y)
        r = mid - 1;
      else {
        l = mid + 1;
        last = mid;
      }
    }
    b = last;
    new_edge(a, b + 1);
  }
}
void get_nodes() {
  scanf("%d", &nSg);
  set<int> ends;
  for (int i = 1; i <= nSg; ++i) {
    scanf("%d%d", &gv[i].x, &gv[i].y);
    ends.insert(gv[i].x);
    ends.insert(gv[i].y + 1);
  }
  atomz.push_back(-1e9);
  for (set<int>::iterator it = ends.begin(); it != ends.end(); ++it)
    atomz.push_back(*it);
  atomz.push_back(1e9);
  nAt = atomz.size() - 1;
  make_edges();
  vector<int> unp;
  for (int i = 1; i <= nAt; ++i)
    if (deg[i] & 1) unp.push_back(i);
  int u = 200042;
  for (int i = 0; i < unp.size(); i += 2) {
    new_edge(unp[i], u);
    new_edge(unp[i + 1], u);
  }
}
void color_edges() {
  for (int i = 1; i < ans.size(); ++i) {
    int x = ans[i - 1];
    int y = ans[i];
    if (x > y)
      color(y, x, 0);
    else
      color(x, y, 1);
  }
}
void output_colors() {
  for (int i = 0; i < nSg; ++i) printf("%d ", t[i].color);
}
int main() {
  get_nodes();
  for (int i = 1; i <= nAt; ++i)
    if (!nvis[i]) {
      ans.clear();
      dfs(i);
      color_edges();
    }
  output_colors();
  return 0;
}
