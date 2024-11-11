#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  return (a % b) == 0 ? b : GCD(b, a % b);
}
long long mod(long long x) { return ((x % 998244353 + 998244353) % 998244353); }
bool cmp(const pair<int, int> &left, const pair<int, int> &right) {
  return left.first > right.first ||
         (left.first == right.first && left.second < right.second);
}
int main() {
  int n, m, p1, p2, p3, t1, t2, i, j, k, mx = 0;
  vector<pair<int, int> > v;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  for (i = 0; i < n; i++) {
    cin >> j >> k;
    v.push_back(make_pair(j, k));
  }
  sort(v.begin(), v.end());
  for (i = 0; i < n - 1; i++) {
    mx += (v[i].second - v[i].first) * p1;
    if (v[i + 1].first > v[i].second + t1) {
      mx += t1 * p1;
      if (v[i + 1].first > v[i].second + t1 + t2) {
        mx += t2 * p2;
        mx += (v[i + 1].first - (v[i].second + t1 + t2)) * p3;
      } else
        mx += (v[i + 1].first - (v[i].second + t1)) * p2;
    } else
      mx += (v[i + 1].first - v[i].second) * p1;
  }
  mx += (v[n - 1].second - v[n - 1].first) * p1;
  cout << mx << endl;
  return 0;
}
