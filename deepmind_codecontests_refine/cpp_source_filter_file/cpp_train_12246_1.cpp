#include <bits/stdc++.h>
using namespace std;
class sum {
  int n;
  vector<int> v;

 public:
  sum(int _n) : n(_n), v(vector<int>(2 * n, 0)) {}
  int get(int i) {
    int rval = 0;
    for (i += n; i > 0; i >>= 1) rval += v[i];
    return rval;
  }
  void add(int l, int r, int val) {
    r = min(n, r);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) v[l++] += val;
      if (r & 1) v[--r] += val;
    }
  }
};
void ending(bool good) {
  if (good)
    cout << "YES\n";
  else
    cout << "NO\n";
  exit(0);
}
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second == p2.second) return p1.second > p2.second;
  return p1.first < p2.first;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = n - i;
  }
  a.push_back({0, 0});
  n++;
  sort(a.begin(), a.end(), cmp);
  sum r1(n + 1);
  int left = 0, right = n, first = -1;
  for (int i = 0; i < n; i++) {
    if (i && !r1.get(a[i].second)) {
      if (first == -1) first = i;
      left = max(left, a[i].second - k);
      right = min(right, a[i].second - 1);
    }
    r1.add(a[i].second, a[i].second + k + 1, 1);
  }
  if (first == -1) ending(true);
  if (left > right) ending(false);
  for (int i = 0; i < first - 1; i++) {
    if (a[i].second <= left && left <= a[i].second + k + 1) ending(true);
  }
  ending(false);
  return 0;
}
