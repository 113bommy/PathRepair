#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
struct Point {
  int x, y, axis;
};
int X[N], Y[N];
vector<Point> npx, npy;
bool cmp1(Point a, Point b) { return a.x < b.x; }
bool cmp2(Point a, Point b) { return a.y < b.y; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    npx.clear();
    npy.clear();
    for (int i = 1; i <= n; i++) {
      cin >> X[i];
    }
    for (int i = 1; i <= m; i++) {
      cin >> Y[i];
    }
    for (int i = 1; i <= k; i++) {
      int x, y;
      cin >> x >> y;
      auto it1 = lower_bound(X + 1, X + n + 1, x);
      auto it2 = lower_bound(Y + 1, Y + m + 1, y);
      if (*it1 == x && *it2 == y) {
        continue;
      }
      if (*it1 == x) {
        npx.push_back({x, y, *it1});
      } else {
        npy.push_back({x, y, *it2});
      }
    }
    sort(npx.begin(), npx.end(), cmp2);
    sort(npy.begin(), npy.end(), cmp1);
    int idx = 0;
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
      long long ct = 0;
      map<int, long long> mp;
      while (idx < npy.size() && X[i - 1] < npy[idx].x && npy[idx].x < X[i]) {
        mp[npy[idx].axis]++;
        idx++;
        ct++;
      }
      for (auto [it, v] : mp) {
        ans -= v * (v - 1) / 2;
      }
      ans += ct * (ct - 1) / 2;
    }
    idx = 0;
    for (int i = 2; i <= m; i++) {
      long long ct = 0;
      map<int, long long> mp;
      while (idx < npx.size() && Y[i - 1] < npx[idx].y && npx[idx].y < Y[i]) {
        mp[npx[idx].axis]++;
        idx++;
        ct++;
      }
      for (auto [it, v] : mp) {
        ans -= v * (v - 1) / 2;
      }
      ans += ct * (ct - 1) / 2;
    }
    cout << ans << endl;
  }
  return 0;
}
