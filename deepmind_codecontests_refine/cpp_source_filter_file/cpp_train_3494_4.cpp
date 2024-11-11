#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000 * 1000 * 1000;
int main() {
  int n;
  cin >> n;
  long long r1 = INT_MAX, r2 = 0;
  long long a, b, c;
  int ans1 = -1, ans2 = -1;
  map<pair<long long, long long>, pair<long long, int>> maxPos;
  cin >> a >> b >> c;
  maxPos[make_pair(max(a, b), min(a, b))] = make_pair(c, 0);
  maxPos[make_pair(max(a, c), min(a, c))] = make_pair(b, 0);
  maxPos[make_pair(max(c, b), min(c, b))] = make_pair(a, 0);
  r1 = min(a, b);
  r1 = min(r1, c);
  if (n == 1) {
    cout << "1\n1\n";
    return 0;
  }
  int ans0 = 0;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b >> c;
    long long r = INT_MAX;
    r = min(a, b);
    r = min(r, c);
    if (r1 < r) {
      r1 = r;
      ans0 = i;
    }
    r = INT_MAX;
    r = min(a, b);
    long long tc = c;
    if (maxPos.find(make_pair(max(a, b), min(a, b))) != maxPos.end()) {
      tc += maxPos[make_pair(max(a, b), min(a, b))].first;
      r = min(tc, r);
      if (r > r2) {
        r2 = r;
        ans1 = i;
        ans2 = maxPos[make_pair(max(a, b), min(a, b))].second;
      }
    }
    r = INT_MAX;
    r = min(b, c);
    long long ta = a;
    if (maxPos.find(make_pair(max(c, b), min(c, b))) != maxPos.end()) {
      ta += maxPos[make_pair(max(c, b), min(c, b))].first;
      r = min(r, ta);
      if (r > r2) {
        r2 = r;
        ans1 = i;
        ans2 = maxPos[make_pair(max(c, b), min(c, b))].second;
      }
    }
    r = INT_MAX;
    r = min(c, a);
    long long tb = b;
    if (maxPos.find(make_pair(max(a, c), min(a, c))) != maxPos.end()) {
      tb += maxPos[make_pair(max(a, c), min(a, c))].first;
      r = min(r, tb);
      if (r > r2) {
        r2 = r;
        ans1 = i;
        ans2 = maxPos[make_pair(max(a, c), min(a, c))].second;
      }
    }
    if (maxPos.find(make_pair(max(a, b), min(a, b))) == maxPos.end() ||
        maxPos[make_pair(max(a, b), min(a, b))].first < c)
      maxPos[make_pair(max(a, b), min(a, b))] = make_pair(c, i);
    if (maxPos.find(make_pair(max(a, c), min(a, c))) == maxPos.end() ||
        maxPos[make_pair(max(a, c), min(a, c))].first < b)
      maxPos[make_pair(max(a, c), min(a, c))] = make_pair(b, i);
    if (maxPos.find(make_pair(max(c, b), min(c, b))) != maxPos.end() ||
        maxPos[make_pair(max(c, b), min(c, b))].first < a)
      maxPos[make_pair(max(c, b), min(c, b))] = make_pair(a, i);
  }
  if (r1 > r2) {
    cout << "1\n" << ans0 + 1 << endl;
    return 0;
  }
  cout << "2\n";
  cout << ans1 + 1 << " " << ans2 + 1 << endl;
  return 0;
}
