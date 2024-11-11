#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
inline bool commonSeg1D(const pair<int, int> &x, const pair<int, int> &y) {
  return y.first < x.second && x.first < y.second;
}
inline bool commonArea2D(const pair<pair<int, int>, pair<int, int> > &a,
                         const pair<pair<int, int>, pair<int, int> > &b) {
  return commonSeg1D(a.first, b.first) && commonSeg1D(a.second, b.second);
}
int main() {
  pair<int, int> ps[3];
  while (cin >> ps[0].first >> ps[0].second >> ps[1].first >> ps[1].second >>
         ps[2].first >> ps[2].second) {
    int area = 0;
    for (int(i) = 0; (i) < (int)(3); ++(i)) area += ps[i].first * ps[i].second;
    int N = (int)(sqrt(area * 1.) + .5);
    if (N * N != area) {
      puts("-1");
      continue;
    }
    vector<string> ans(N, string(N, '?'));
    for (int(rot) = 0; (rot) < (int)(1 << 3); ++(rot)) {
      for (int(i) = 0; (i) < (int)(3); ++(i))
        if (rot >> i & 1) swap(ps[i].first, ps[i].second);
      vector<int> ys, xs;
      for (int(i) = 0; (i) < (int)(1 << 3); ++(i)) {
        int y = 0, x = 0;
        for (int(j) = 0; (j) < (int)(3); ++(j))
          if (i >> j & 1) {
            y += ps[j].first;
            x += ps[j].first;
          }
        ys.push_back(y);
        xs.push_back(x);
      }
      sort(ys.begin(), ys.end());
      ys.erase(unique(ys.begin(), ys.end()), ys.end());
      sort(xs.begin(), xs.end());
      xs.erase(unique(xs.begin(), xs.end()), xs.end());
      vector<int> perm(3);
      for (int(i) = 0; (i) < (int)(3); ++(i)) perm[i] = i;
      for (int(ord) = 0; (ord) < (int)(3); ++(ord)) {
        for (int(y1i) = 0; (y1i) < (int)(ys.size()); ++(y1i))
          for (int(x1i) = 0; (x1i) < (int)(xs.size()); ++(x1i))
            for (int(y2i) = 0; (y2i) < (int)(ys.size()); ++(y2i))
              for (int(x2i) = 0; (x2i) < (int)(xs.size()); ++(x2i)) {
                int y1 = ys[y1i], x1 = xs[x1i];
                int y2 = ys[y2i], x2 = xs[x2i];
                pair<pair<int, int>, pair<int, int> > a[3];
                a[0] = pair<pair<int, int>, pair<int, int> >(
                    pair<int, int>(0, ps[perm[0]].first),
                    pair<int, int>(0, ps[perm[0]].second));
                a[1] = pair<pair<int, int>, pair<int, int> >(
                    pair<int, int>(y1, y1 + ps[perm[1]].first),
                    pair<int, int>(x1, x1 + ps[perm[1]].second));
                a[2] = pair<pair<int, int>, pair<int, int> >(
                    pair<int, int>(y2, y2 + ps[perm[2]].first),
                    pair<int, int>(x2, x2 + ps[perm[2]].second));
                bool ok = true;
                for (int(i) = 0; (i) < (int)(3); ++(i))
                  for (int(j) = 0; (j) < (int)(i); ++(j))
                    ok &= !commonArea2D(a[i], a[j]);
                for (int(i) = 0; (i) < (int)(3); ++(i)) {
                  ok &= a[i].first.second <= N;
                  ok &= a[i].second.second <= N;
                }
                if (ok) {
                  for (int(i) = 0; (i) < (int)(3); ++(i)) {
                    for (int(y) = (int)(a[i].first.first);
                         (y) < (int)(a[i].first.second); ++(y))
                      for (int(x) = (int)(a[i].second.first);
                           (x) < (int)(a[i].second.second); ++(x))
                        ans[y][x] = (char)('A' + perm[i]);
                  }
                  goto okok;
                }
              }
        rotate(perm.begin(), perm.begin() + 1, perm.end());
      }
      for (int(i) = 0; (i) < (int)(3); ++(i))
        if (rot >> i & 1) swap(ps[i].first, ps[i].second);
    }
    if (0) {
    okok:;
      printf("%d\n", N);
      for (int(i) = 0; (i) < (int)(N); ++(i)) puts(ans[i].c_str());
    } else {
      puts("-1");
    }
  }
  return 0;
}
