#include <bits/stdc++.h>
using namespace std;
const long long linf = 4000000000000000000LL;
const long long inf = 1000000007;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << endl;
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << endl;
}
void pv(vector<vector<int>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << endl;
    pv(a[i]);
    cout << endl;
  }
}
void pv(vector<vector<long long>> a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << endl;
    pv(a[i]);
  }
  cout << endl;
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << endl;
  cout << endl;
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int n, k;
vector<pair<long long, long long>> a;
void init() {
  vector<pair<long long, long long>> t;
  for (auto& x : a)
    if (x.first == 0 && x.second == 0)
      k--, n--;
    else
      t.push_back(x);
  a = t;
}
bool check(long double r) {
  long double pi = acos(-1);
  vector<pair<long double, int>> ranges;
  for (int i = (0); i < (n); ++i) {
    long double d = sqrt(a[i].first * a[i].first + a[i].second * a[i].second);
    if (d > 2 * r) continue;
    long double theta = acos(d / (2 * r));
    long double theta1 = atan((long double)a[i].second / a[i].first);
    if (theta1 < 0 || (theta1 == 0 && a[i].first < 0)) theta1 += pi;
    if (a[i].second < 0) theta1 += pi;
    long double x = theta1 - theta, y = theta1 + theta;
    if (x < 0 && y >= 0) {
      ranges.push_back({x + 2 * pi, 1});
      ranges.push_back({2 * pi, -1});
      ranges.push_back({0, 1});
      ranges.push_back({y, -1});
    } else if (x < 2 * pi && y >= 2 * pi) {
      ranges.push_back({x, 1});
      ranges.push_back({2 * pi, -1});
      ranges.push_back({0, 1});
      ranges.push_back({y - 2 * pi, -1});
    } else {
      ranges.push_back({x, 1});
      ranges.push_back({y, -1});
    }
  }
  sort(ranges.begin(), ranges.end(),
       [](pair<long double, int> x, pair<long double, int> y) {
         if (x.first == y.first) return x.second > y.second;
         return x.first < y.first;
       });
  int m = 0;
  int cur = 0;
  for (auto& x : ranges) {
    cur += x.second;
    m = max(m, cur);
  }
  return m >= k;
}
int main() {
  setIO("test1");
  cin >> n >> k;
  a.resize(n);
  for (auto& x : a) cin >> x.first >> x.second;
  init();
  long double l = 0, r = 222222;
  for (int i = (0); i < (30); ++i) {
    long double m = (l + r) / 2;
    if (check(m))
      r = m;
    else
      l = m;
  }
  cout << setprecision(20) << l << endl;
}
