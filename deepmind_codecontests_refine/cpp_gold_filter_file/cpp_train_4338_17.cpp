#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
  cout << endl;
}
template <typename... Args>
void _db(Args... args) {}
ll dist_stairs(ll dx, ll dy) { return dx + dy; }
ll dist_eles(ll dx, ll dy, ll speed) {
  ll res = dx;
  res += dy / speed;
  if (dy % speed > 0) {
    ++res;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  ll ysize, xsize;
  int sta, ele;
  int maxspeed;
  cin >> ysize >> xsize >> sta >> ele >> maxspeed;
  vector<int> stairs(sta);
  for (int i = 0; i < sta; ++i) {
    cin >> stairs[i];
  }
  vector<int> elevs(ele);
  for (int i = 0; i < ele; ++i) {
    cin >> elevs[i];
  }
  int que;
  cin >> que;
  int sx, sy, dx, dy;
  for (int i = 0; i < que; ++i) {
    cin >> sy >> sx >> dy >> dx;
    ll ydif = abs(sy - dy);
    ll dist = 1000000000000000000ll;
    if (sy == dy) {
      cout << abs(sx - dx) << endl;
      continue;
    }
    if (sta > 0) {
      auto itstairsright = lower_bound(stairs.begin(), stairs.end(), sx);
      if (itstairsright != stairs.end()) {
        ll xdif = abs(*itstairsright - sx) + abs(*itstairsright - dx);
        dist = min(dist, dist_stairs(xdif, ydif));
        _db("after stairs right dist: ", dist);
      }
      if (itstairsright != stairs.begin()) {
        auto itstairsleft = itstairsright - 1;
        ll xdif = abs(*itstairsleft - sx) + abs(*itstairsleft - dx);
        _db("ydif", ydif);
        _db("xdif left", xdif);
        dist = min(dist, dist_stairs(xdif, ydif));
        _db("after stairs left dist: ", dist);
      }
    }
    if (ele > 0) {
      auto iteleright = lower_bound(elevs.begin(), elevs.end(), sx);
      if (iteleright != elevs.end()) {
        _db("found ele right: ", *iteleright);
        ll xdif = abs(*iteleright - sx) + abs(*iteleright - dx);
        _db("ele right x diff:", xdif);
        dist = min(dist, dist_eles(xdif, ydif, maxspeed));
      }
      if (iteleright != elevs.begin()) {
        auto iteleleft = iteleright - 1;
        _db("found ele left: ", *iteleleft);
        ll xdif = abs(*iteleleft - sx) + abs(*iteleleft - dx);
        _db("ele left x diff:", xdif);
        dist = min(dist, dist_eles(xdif, ydif, maxspeed));
      }
    }
    cout << dist << endl;
  }
  return 0;
}
