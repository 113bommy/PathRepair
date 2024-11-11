#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, h, w;
int u = 0, d = 0, l = 0, r = 0, hh = 0, ww = 0;
vector<int> vu, vd, vl, vr;
vector<pair<long long, int> > e;
char s[500005];
int main() {
  scanf("%d%d%d", &n, &h, &w);
  scanf("%s", s);
  int ans = (long long)h * w % MOD;
  for (int i = 0; i < (int)(n); ++i) {
    if (s[i] == 'U') {
      --hh;
      if (-hh > u) {
        u = -hh;
        vu.push_back(i);
      }
    } else if (s[i] == 'D') {
      ++hh;
      if (hh > d) {
        d = hh;
        vd.push_back(i);
      }
    } else if (s[i] == 'L') {
      --ww;
      if (-ww > l) {
        l = -ww;
        vl.push_back(i);
      }
    } else {
      ++ww;
      if (ww > r) {
        r = ww;
        vr.push_back(i);
      }
    }
    ans = (ans + (long long)max(0, h - u - d) * max(0, w - l - r)) % MOD;
  }
  h -= u + d;
  w -= l + r;
  if (h > 0 && w > 0) {
    if (hh == 0 && ww == 0) {
      printf("-1\n");
      return 0;
    }
    if (hh > 0) {
      for (int i = (int)vd.size() - hh; i < (int)vd.size(); ++i) {
        e.push_back(make_pair(vd[i], 0));
      }
    }
    if (hh < 0) {
      for (int i = (int)vu.size() + hh; i < (int)vu.size(); ++i) {
        e.push_back(make_pair(vu[i], 0));
      }
    }
    if (ww > 0) {
      for (int i = (int)vr.size() - ww; i < (int)vr.size(); ++i) {
        e.push_back(make_pair(vr[i], 1));
      }
    }
    if (ww < 0) {
      for (int i = (int)vl.size() + ww; i < (int)vl.size(); ++i) {
        e.push_back(make_pair(vl[i], 1));
      }
    }
    sort(e.begin(), e.end());
    int sz = (int)e.size();
    while ((int)e.size() < w + h + 3) {
      int ind = (int)e.size() - sz;
      e.push_back(make_pair(e[ind].first + n, e[ind].second));
    }
    int pre = 0;
    for (pair<int, int> x : e) {
      ans = (ans + (long long)w * h % MOD * (x.first - pre)) % MOD;
      if (x.second == 0)
        --h;
      else
        --w;
      if (h <= 0 || w <= 0) break;
      pre = x.first;
    }
  }
  printf("%d\n", ans);
  return 0;
}
