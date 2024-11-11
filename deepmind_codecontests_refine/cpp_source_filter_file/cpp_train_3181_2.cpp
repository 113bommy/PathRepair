#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> tmin;
vector<int> tmax;
int nx;
int K;
void init(int n) {
  nx = n;
  tmin.resize(4 * n);
  tmax.resize(4 * n);
}
void build(vector<int>& a, int v = 1, int tl = 0, int tr = nx - 1) {
  if (tl == tr) {
    tmin[v] = tmax[v] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(a, 2 * v, tl, tm);
  build(a, 2 * v + 1, tm + 1, tr);
  tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
  tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
}
int getmin(int l, int r, int v = 1, int tl = 0, int tr = nx - 1) {
  if (l > r) return INF;
  if (l == tl && r == tr) return tmin[v];
  int tm = (tl + tr) / 2;
  int v1 = getmin(l, min(r, tm), 2 * v, tl, tm);
  int v2 = getmin(max(l, tm + 1), r, 2 * v + 1, tm + 1, tr);
  return min(v1, v2);
}
int getmax(int l, int r, int v = 1, int tl = 0, int tr = nx - 1) {
  if (l > r) return -1;
  if (l == tl && r == tr) return tmax[v];
  int tm = (tl + tr) / 2;
  int v1 = getmax(l, min(r, tm), 2 * v, tl, tm);
  int v2 = getmax(max(l, tm + 1), r, 2 * v + 1, tm + 1, tr);
  return max(v1, v2);
}
int find_delta(int a, int b) {
  int mn = getmin(a, b);
  int mx = getmax(a, b);
  return mx - mn;
}
bool ok(int delta) {
  for (int i = 0; i + delta - 1 < nx; ++i) {
    if (find_delta(i, i + delta - 1) <= K) return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  init(n);
  build(a);
  int lo = 1;
  int hi = n;
  if (ok(n)) {
    cout << n << " " << 1 << endl;
    cout << 1 << " " << n << endl;
    return 0;
  }
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  vector<pair<int, int> > res;
  for (int i = 0; i + lo - 1 < n; ++i) {
    if (find_delta(i, i + lo - 1) <= K) {
      res.push_back(make_pair(i, i + lo - 1));
    }
  }
  cout << lo << " " << ((int)res.size()) << endl;
  for (int i = 0; i < ((int)res.size()); ++i) {
    scanf("%d %d\n", res[i].first + 1, res[i].second + 1);
  }
  return 0;
}
