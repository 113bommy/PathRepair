#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long int maxN = 3e5;
struct segmentTree {
  vector<long long int> t;
  segmentTree() { t.resize(4 * maxN); }
  void add(long long int ind, long long int v = 0, long long int tl = 0,
           long long int tr = maxN) {
    if (tr - tl == 1)
      t.at(v)++;
    else {
      long long int mid = (tl + tr) / 2;
      if (ind >= mid)
        add(ind, 2 * v + 2, mid, tr);
      else
        add(ind, 2 * v + 1, tl, mid);
      t.at(v) = t.at(2 * v + 1) + t.at(2 * v + 2);
    }
  }
  long long int getS(long long int a, long long int R, long long int v = 0,
                     long long int tl = 0, long long int tr = maxN) {
    if (R <= tl || a >= tr || tr - tl < 1)
      return 0;
    else if (a <= tl && tr <= R)
      return t.at(v);
    else {
      long long int mid = (tl + tr) / 2;
      long long int left = getS(a, R, 2 * v + 1, tl, mid);
      long long int right = getS(a, R, 2 * v + 2, mid, tr);
      return left + right;
    }
  }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  vector<long long int> a(n), coords;
  vector<pair<long long int, long long int>> ev(n);
  for (long long int i = 0; i < n; i++) {
    long long int l, r;
    cin >> l >> r;
    coords.push_back(l);
    coords.push_back(r);
    a.at(i) = l;
    ev.at(i) = {r, i};
  }
  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());
  for (long long int i = 0; i < n; i++) {
    a.at(i) =
        (lower_bound(coords.begin(), coords.end(), a.at(i)) - coords.begin());
    ev.at(i).first =
        (lower_bound(coords.begin(), coords.end(), ev.at(i).first) -
         coords.begin());
  }
  sort(ev.begin(), ev.end());
  vector<long long int> ans(n);
  segmentTree t;
  for (auto e : ev) {
    ans.at(e.second) = t.getS(a.at(e.second), maxN);
    t.add(a.at(e.second));
  }
  for (auto i : ans) cout << i << "\n";
  return 0;
}
