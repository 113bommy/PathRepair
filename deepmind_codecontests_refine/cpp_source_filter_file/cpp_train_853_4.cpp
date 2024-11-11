#include <bits/stdc++.h>
using namespace std;
int xs[500000];
int ys[500000];
int zs[500000];
struct wut {
  int i;
  wut(int _i) : i(_i) {}
  int x() const { return xs[i]; }
  int y() const { return ys[i]; }
  int z() const { return zs[i]; }
  void pnt() const { printf("%d - %d %d %d\n", i, x(), y(), z()); }
  bool operator<(const wut& rhs) const {
    if (zs[i] == zs[rhs.i]) {
      if (xs[i] == xs[rhs.i]) {
        return ys[i] < ys[rhs.i];
      }
      return xs[i] < xs[rhs.i];
    }
    return zs[i] < zs[rhs.i];
  }
};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &xs[i]);
  for (int i = 0; i < n; i++) scanf("%d", &ys[i]);
  for (int i = 0; i < n; i++) scanf("%d", &zs[i]);
  vector<wut> sz;
  for (int i = 0; i < n; i++) sz.push_back(i);
  sort(sz.begin(), sz.end());
  map<int, int> m;
  m[-1] = 1000000010;
  m[1000000010] = -1;
  int ig = 0;
  for (int i = n - 1; i >= 0; i--) {
    map<int, int>::iterator np = m.upper_bound(sz[i].x());
    if (np->second > sz[i].y()) {
      ig++;
      continue;
    }
    map<int, int>::iterator fp = m.find(sz[i].x());
    if (fp == m.end() || fp->second < sz[i].y()) {
      m[sz[i].x()] = sz[i].y();
      map<int, int>::iterator rme = m.lower_bound(sz[i].x());
      map<int, int>::iterator rms = rme;
      int rmc = 0;
      do {
        --rms;
        rmc++;
      } while (rms->second < sz[i].y());
      ++rms;
      m.erase(rms, rme);
    }
  }
  printf("%d\n", ig);
  return 0;
}
