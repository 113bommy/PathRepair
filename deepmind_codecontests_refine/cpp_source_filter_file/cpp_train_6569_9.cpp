#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h;
  cin >> n >> h;
  vector<pair<int, int>> zeros;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    zeros.push_back(make_pair(a, b));
  }
  int sol = 0;
  int pa, pb, ib, c1;
  pa = zeros[0].first;
  pb = zeros[0].second;
  ib = 0;
  c1 = 0;
  while (c1 < h) {
    int d = h - c1;
    if (ib + 1 >= n) {
      pb = pb + d;
      c1 = h;
      break;
    }
    if (d < zeros[ib + 1].first - pb) {
      pb = pb + d;
      c1 = h;
      break;
    }
    c1 += zeros[ib + 1].first - pb;
    pb = zeros[ib + 1].second;
    ib++;
  }
  sol = pb - pa;
  for (int i = 1; i < n; i++) {
    int ci1 = zeros[i].first - zeros[i - 1].second;
    pa = zeros[i].first;
    if (h < ci1) {
      pb = zeros[i].second;
      ib = i;
      c1 = 0;
      while (c1 < h) {
        int d = h - c1;
        if (ib + 1 >= n) {
          pb = pb + (h - c1);
          c1 = h;
          break;
        }
        if (d < zeros[ib + 1].first - pb) {
          pb = pb + (h - c1);
          c1 = h;
          break;
        }
        c1 += zeros[ib + 1].first - pb;
        pb = zeros[ib + 1].second;
        ib++;
      }
    } else {
      c1 = h - ci1;
      while (c1 < h) {
        int d = h - c1;
        if (ib + 1 >= n) {
          pb = pb + (h - c1);
          c1 = h;
          break;
        }
        if (d < zeros[ib + 1].first - pb) {
          pb = pb + (h - c1);
          c1 = h;
          break;
        }
        c1 += zeros[ib + 1].first - pb;
        pb = zeros[ib + 1].second;
        ib++;
      }
    }
    sol = max(sol, pb - pa);
  }
  cout << sol;
}
