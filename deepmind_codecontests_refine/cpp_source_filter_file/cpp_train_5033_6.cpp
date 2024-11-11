#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  int id;
  double rad;
  point(int xx, int yy, int idd) {
    x = xx;
    y = yy;
    id = idd;
  }
  bool operator<(const point &o) const { return rad < o.rad; }
  void calRad(int xx, int yy) { rad = atan2(y - yy, x - xx); }
};
vector<int> e[2000];
vector<point> p;
int totalChild[3000];
int pass[3000];
int ans[3000];
int par[3000];
pair<int, int> findRef(vector<point> p) {
  int ymax = -1000000001;
  int xmax = -1000000001;
  for (int i = 0; i < p.size(); i++) {
    if (p[i].y > ymax) {
      ymax = p[i].x;
      xmax = p[i].x;
    } else if (p[i].y == ymax && p[i].x > xmax) {
      xmax = max(p[i].x, xmax);
    }
  }
  return make_pair(xmax, ymax);
}
int dfs(int now) {
  totalChild[now] = 0;
  pass[now] = 1;
  for (int i = 0; i < e[now].size(); i++) {
    if (pass[e[now][i]] == 0) {
      par[e[now][i]] = now;
      totalChild[now] += dfs(e[now][i]) + 1;
    }
  }
  return totalChild[now];
}
void doit(int now, vector<point> p) {
  pair<int, int> ref = findRef(p);
  for (int i = 0; i < p.size(); i++) {
    if (p[i].x == ref.first && p[i].y == ref.second) {
      p[i].rad = -10;
      continue;
    }
    p[i].calRad(ref.first, ref.second);
  }
  sort(p.begin(), p.end());
  ans[p[0].id] = now;
  int idx = 1;
  for (int i = 0; i < e[now].size(); i++) {
    if (e[now][i] == par[now]) continue;
    vector<point> pp;
    for (int j = idx; j < idx + totalChild[e[now][i]] + 1; j++)
      pp.push_back(p[j]);
    idx = idx + totalChild[e[now][i]] + 1;
    doit(e[now][i], pp);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  par[1] = -1;
  dfs(1);
  int ymax = -1000000001;
  int xmax = -1000000001;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back(point(a, b, i));
  }
  doit(1, p);
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}
