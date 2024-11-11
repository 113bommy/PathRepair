#include <bits/stdc++.h>
using namespace std;
const int MAXN = 102400;
int n, m, a[MAXN], b[MAXN];
vector<pair<int, int> > occ;
vector<pair<int, int> > front;
vector<int> v;
void calcOcc() {
  v.clear();
  for (int i = 0; i < n; i++) {
    v.push_back(a[i]);
    if (a[i] != b[i]) {
      v.push_back(b[i]);
    }
  }
  sort(v.begin(), v.end());
  occ.clear();
  for (int i = 0; i < (int)v.size(); i++) {
    if (occ.empty() || occ.back().first != v[i]) {
      occ.push_back(make_pair(v[i], 1));
    } else {
      occ.back().second++;
    }
  }
}
void calcFront() {
  v.clear();
  for (int i = 0; i < n; i++) {
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  front.clear();
  for (int i = 0; i < (int)v.size(); i++) {
    if (front.empty() || front.back().first != v[i]) {
      front.push_back(make_pair(v[i], 1));
    } else {
      front.back().second++;
    }
  }
}
const int INF = 1012345678;
int calc() {
  int pnt = 0, res = INF;
  for (int i = 0; i < (int)occ.size(); i++) {
    if (occ[i].second < m) continue;
    for (; pnt < (int)front.size() && front[pnt].first < occ[i].first; pnt++)
      ;
    if (pnt < (int)front.size() && front[pnt].first == occ[i].first) {
      res = min(res, max(m - front[pnt].second, 0));
    } else {
      res = min(res, m);
    }
  }
  return res == INF ? -1 : res;
}
int main() {
  scanf("%d", &n);
  m = (n + 1) >> 1;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  calcOcc();
  calcFront();
  printf("%d\n", calc());
  return 0;
}
