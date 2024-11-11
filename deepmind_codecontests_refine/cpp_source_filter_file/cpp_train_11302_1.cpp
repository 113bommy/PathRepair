#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
set<pair<long long, char> > q1, q2, q3, q4, xs, ys;
bool ans;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> x >> y;
  for (long long i = 0; i < n; ++i) {
    char c;
    long long x1, y1;
    cin >> c >> x1 >> y1;
    x1 -= x;
    y1 -= y;
    if (x1 == 0) {
      ys.insert({y1, c});
    }
    if (y1 == 0) {
      xs.insert({x1, c});
    }
    if (x1 + y1 == 0) {
      if (x1 < 0 and y1 > 0) {
        q1.insert({x1 * x1 + y1 * y1, c});
      }
      if (x1 > 0 and y1 < 0) {
        q3.insert({x1 * x1 + y1 * y1, c});
      }
    }
    if (x1 - y1 == 0) {
      if (x1 < 0 and y1 < 0) {
        q2.insert({x1 * x1 + y1 * y1, c});
      }
      if (x1 > 0 and y1 > 0) {
        q4.insert({x1 * x1 + y1 * y1, c});
      }
    }
  }
  ys.insert({1e18, 'B'});
  ys.insert({-1e18, 'B'});
  xs.insert({1e18, 'B'});
  xs.insert({-1e18, 'B'});
  q1.insert({4e18, 'R'});
  q1.insert({-4e18, 'R'});
  q2.insert({4e18, 'R'});
  q2.insert({-4e18, 'R'});
  q3.insert({4e18, 'R'});
  q3.insert({-4e18, 'R'});
  q4.insert({4e18, 'R'});
  q4.insert({-4e18, 'R'});
  if ((*ys.lower_bound({0, 0})).second != 'B' or
      (*--ys.lower_bound({0, 0})).second != 'B') {
    ans = 1;
  }
  if ((*xs.lower_bound({0, 0})).second != 'B' or
      (*--xs.lower_bound({0, 0})).second != 'B') {
    ans = 1;
  }
  if ((*q1.lower_bound({0, 0})).second != 'R' or
      (*--q1.lower_bound({0, 0})).second != 'R') {
    ans = 1;
  }
  if ((*q4.lower_bound({0, 0})).second != 'R' or
      (*--q4.lower_bound({0, 0})).second != 'R') {
    ans = 1;
  }
  if ((*q2.lower_bound({0, 0})).second != 'R' or
      (*--q2.lower_bound({0, 0})).second != 'R') {
    ans = 1;
  }
  if ((*q3.lower_bound({0, 0})).second != 'R' or
      (*--q3.lower_bound({0, 0})).second != 'R') {
    ans = 1;
  }
  if (ans == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
