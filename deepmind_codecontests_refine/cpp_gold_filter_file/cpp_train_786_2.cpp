#include <bits/stdc++.h>
using namespace std;
struct event {
  long long x, t;
};
struct point {
  long long f, g;
};
long long n, v;
event e[100001];
point fg[100001];
bool cmp(const event& a, const event& b) { return a.t < b.t; }
bool cmp2(const point& a, const point& b) {
  if (a.f == b.f)
    return a.g < b.g;
  else
    return a.f < b.f;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> e[i].x >> e[i].t;
  sort(e, e + n, cmp);
  cin >> v;
  for (long long i = 0; i < n; i++) {
    fg[i].f = -e[i].x + e[i].t * v;
    fg[i].g = e[i].x + e[i].t * v;
  }
  sort(fg, fg + n, cmp2);
  vector<long long> v1;
  for (long long i = 0; i < n; i++) {
    if (!v1.size() || fg[i].g >= v1[v1.size() - 1]) {
      v1.push_back(fg[i].g);
    } else {
      long long pos = upper_bound(v1.begin(), v1.end(), fg[i].g) - v1.begin();
      v1[pos] = fg[i].g;
    }
  }
  long long secondans = v1.size();
  v1.clear();
  for (long long i = 0; i < n; i++) {
    if (fg[i].f < 0 || fg[i].g < 0) continue;
    if (!v1.size() || fg[i].g >= v1[v1.size() - 1]) {
      v1.push_back(fg[i].g);
    } else {
      long long pos = upper_bound(v1.begin(), v1.end(), fg[i].g) - v1.begin();
      v1[pos] = fg[i].g;
    }
  }
  cout << v1.size() << " " << secondans;
}
