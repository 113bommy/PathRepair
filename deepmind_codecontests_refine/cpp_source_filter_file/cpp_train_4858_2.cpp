#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
int go[N][4], nxt[N], xl, yl, xr, yr, n, tsz, esz = 1, my[N], csz, sec[N];
map<pair<int, int>, int> edx;
pair<int, int> pts[N];
bool was[N];
vector<int> ply[N];
double area[N];
long long cross(pair<int, int> a, pair<int, int> b) {
  return (long long)a.first * b.second - (long long)a.second * b.first;
}
double Area(vector<int> p) {
  double ans = 0;
  for (int i = 0, j = (int)p.size() - 1; i < p.size(); j = i, i++) {
    ans += cross(pts[p[i]], pts[p[j]]);
  }
  return abs(ans) / 2;
}
void Connect(int u, int v) {
  edx[{u, v}] = ++esz;
  sec[esz] = v;
  edx[{v, u}] = ++esz;
  sec[esz] = u;
  if (pts[u].first == pts[v].first) {
    if (pts[u].second > pts[v].second) swap(u, v);
    go[v][0] = u;
    go[u][2] = v;
  } else {
    if (pts[u].first > pts[v].first) swap(u, v);
    go[v][1] = u;
    go[u][3] = v;
  }
}
void Build(int u) {
  for (int i = 0; i < 4; i++)
    if (go[u][i]) {
      for (int j = 1; j <= 4; j++)
        if (go[u][(i + j) % 4]) {
          nxt[edx[{go[u][i], u}]] = edx[{u, go[u][(i + j) % 4]}];
          break;
        }
    }
}
vector<int> side[4], E[N];
void AddEdge(int u, int v) {
  E[u].push_back(v);
  E[v].push_back(u);
}
double sum[2];
bool vis[N];
int ty[N];
void DFS(int u, int t = 0) {
  vis[u] = 1;
  sum[t] += area[u];
  ty[u] = t;
  for (int v : E[u])
    if (!vis[v]) DFS(v, t ^ 1);
}
bool CuttingRayTest(double first, double second) {
  int cnt = 0;
  for (int i = 1, j = n; i <= n; j = i, i++) {
    if (pts[i].first == pts[j].first && pts[i].first > first) {
      int mx = max(pts[i].second, pts[j].second);
      int mn = min(pts[i].second, pts[j].second);
      if (mn < second && mx > second) cnt++;
    }
  }
  return cnt % 2;
}
int main() {
  scanf("%i %i %i %i", &xl, &yr, &xr, &yl);
  scanf("%i", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%i %i", &pts[i].first, &pts[i].second);
  }
  tsz = n;
  pts[++tsz] = {xl, yl};
  pts[++tsz] = {xr, yl};
  pts[++tsz] = {xr, yr};
  pts[++tsz] = {xl, yr};
  side[0] = {n + 1, n + 2};
  side[1] = {n + 2, n + 3};
  side[2] = {n + 3, n + 4};
  side[3] = {n + 4, n + 1};
  for (int i = 1, j = n; i <= n; j = i, i++) {
    if (pts[i].first == pts[j].first) {
      int mn = min(pts[i].second, pts[j].second);
      int mx = max(pts[i].second, pts[j].second);
      if (xl < pts[i].first && pts[i].first < xr && mx > yl && mn < yr) {
        if (mn <= yl && mx >= yr) {
          pts[++tsz] = {pts[i].first, yl};
          side[0].push_back(tsz);
          pts[++tsz] = {pts[i].first, yr};
          side[2].push_back(tsz);
          Connect(tsz - 1, tsz);
        } else if (mn <= yl) {
          pts[++tsz] = {pts[i].first, yl};
          side[0].push_back(tsz);
          Connect(tsz, pts[i].second == mx ? i : j);
        } else if (mx >= yr) {
          pts[++tsz] = {pts[i].first, yr};
          side[2].push_back(tsz);
          Connect(tsz, pts[i].second == mn ? i : j);
        } else
          Connect(i, j);
      }
    } else {
      int mn = min(pts[i].first, pts[j].first);
      int mx = max(pts[i].first, pts[j].first);
      if (yl < pts[i].second && pts[i].second < yr && mx > xl && mn < xr) {
        if (mn <= xl && mx >= xr) {
          pts[++tsz] = {xl, pts[i].second};
          side[3].push_back(tsz);
          pts[++tsz] = {xr, pts[i].second};
          side[1].push_back(tsz);
          Connect(tsz - 1, tsz);
        } else if (mn <= xl) {
          pts[++tsz] = {xl, pts[i].second};
          side[3].push_back(tsz);
          Connect(tsz, pts[i].first == mx ? i : j);
        } else if (mx >= xr) {
          pts[++tsz] = {xr, pts[i].second};
          side[1].push_back(tsz);
          Connect(tsz, pts[i].first == mn ? i : j);
        } else
          Connect(i, j);
      }
    }
  }
  for (int s = 0; s < 4; s++) {
    sort(side[s].begin(), side[s].end(),
         [&](int i, int j) { return pts[i] < pts[j]; });
    for (int i = 1; i < side[s].size(); i++)
      Connect(side[s][i - 1], side[s][i]);
  }
  for (int i = 1; i <= tsz; i++) Build(i);
  for (int i = 2; i <= esz; i++)
    if (!was[i]) {
      csz++;
      int j = i;
      while (!was[j]) {
        was[j] = 1;
        my[j] = csz;
        ply[csz].push_back(sec[j]);
        j = nxt[j];
      }
      area[csz] = 1;
    }
  int ban = my[edx[{side[0][1], side[0][0]}]];
  for (int i = 2; i <= esz; i += 2) {
    if (my[i] != ban && my[i + 1] != ban) {
      AddEdge(my[i], my[i + 1]);
    }
  }
  DFS(1 == ban ? 2 : 1);
  int xr = 1;
  if (CuttingRayTest(yl + 0.5, xl + 0.5)) xr = 0;
  double ans = sum[ty[my[edx[{side[0][0], side[0][1]}]]] ^ xr];
  printf("%.0f", ans);
  return 0;
}
