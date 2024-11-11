#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long int> h, p;
bool Ok(long long int t) {
  int pi = 0;
  for (int hi = 0; hi < h.size(); ++hi) {
    if (pi == p.size()) {
      return true;
    }
    if (h[hi] + t < p[pi]) {
      continue;
    }
    long long int reach = h[hi];
    if (h[hi] < p[pi]) {
      reach = h[hi] + t;
    } else if (h[hi] > p[pi] + t) {
      return false;
    } else {
      long long int lr = p[pi] + (t - h[hi] + p[pi]);
      long long int rl = h[hi] + (t - h[hi] + p[pi]) / 2;
      reach = max(lr, rl);
    }
    while (pi < p.size() && p[pi] <= reach) {
      ++pi;
    }
  }
  return pi == p.size();
}
int main() {
  cin >> n >> m;
  h.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  p.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }
  if (Ok(0)) {
    cout << 0 << endl;
    return 0;
  }
  long long int tmin = 0, tmax = 20000000000;
  while (tmin + 1 < tmax) {
    long long int tmid = (tmin + tmax) / 2;
    if (Ok(tmid)) {
      tmax = tmid;
    } else {
      tmin = tmid;
    }
  }
  cout << tmax << endl;
  return 0;
}
