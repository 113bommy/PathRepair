#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, Log = 17, pot = (1 << Log);
long long a[maxn];
int n;
long long pref[maxn];
pair<long long, long long> p[maxn];
long long ccw(pair<long long, long long> a, pair<long long, long long> b,
              pair<long long, long long> c) {
  return a.first * (b.second - c.second) + b.first * (c.second - a.second) +
         c.first * (a.second - b.second);
}
vector<pair<long long, long long> > napravi(
    vector<pair<long long, long long> > &p) {
  vector<pair<long long, long long> > hull;
  for (int i = 0; i < p.size(); i++) {
    while (hull.size() > 1 &&
           ccw(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
      hull.pop_back();
    }
    hull.push_back(p[i]);
  }
  return hull;
}
long long mul(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.first + a.second * b.second;
}
long long binary(vector<pair<long long, long long> > &hull,
                 pair<long long, long long> val) {
  int lo = 0, hi = hull.size() - 1, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (mul(hull[mid], val) > mul(hull[mid + 1], val)) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return mul(hull[lo], val);
}
struct tournament {
  vector<pair<long long, long long> > t[pot * 2];
  void precompute() {
    for (int i = 0; i < n; i++) {
      t[i + pot].push_back(p[i]);
    }
    int p1, p2;
    for (int i = pot - 1; i > 0; i--) {
      p1 = 0;
      p2 = 0;
      while (p1 < t[i * 2].size() && p2 < t[i * 2 + 1].size()) {
        if (t[i * 2][p1] > t[i * 2 + 1][p2]) {
          t[i].push_back(t[i * 2 + 1][p2]);
          p2++;
        } else {
          t[i].push_back(t[i * 2][p1]);
          p1++;
        }
      }
      while (p1 < t[i * 2].size()) {
        t[i].push_back(t[i * 2][p1]);
        p1++;
      }
      while (p2 < t[i * 2 + 1].size()) {
        t[i].push_back(t[i * 2 + 1][p2]);
        p2++;
      }
    }
    for (int i = pot - 1; i > 0; i--) {
      t[i] = napravi(t[i]);
    }
  }
  long long query(int L, int D, int x, int l, int d,
                  pair<long long, long long> val) {
    if (L >= l && D <= d) {
      return binary(t[x], val);
    }
    long long lijeva = 1e18, desna = 1e18;
    if ((L + D) / 2 >= l) {
      lijeva = query(L, (L + D) / 2, x * 2, l, d, val);
    }
    if ((L + D) / 2 + 1 <= d) {
      desna = query((L + D) / 2 + 1, D, x * 2 + 1, l, d, val);
    }
    return min(lijeva, desna);
  }
};
tournament T;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long val = 0, x, y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    val += a[i];
    x = -val + (long long)a[i] * (i + 1);
    y = -a[i];
    p[i] = {x, y};
    pref[i + 1] = val;
  }
  T.precompute();
  int m;
  cin >> m;
  int b, c;
  for (int i = 0; i < m; i++) {
    cin >> b >> c;
    cout << T.query(0, pot - 1, 1, c - b, c - 1, {1, c - b}) + pref[c] << '\n';
  }
  return 0;
}
