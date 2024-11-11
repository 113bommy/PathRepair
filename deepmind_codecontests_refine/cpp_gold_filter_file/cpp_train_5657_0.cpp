#include <bits/stdc++.h>
using namespace std;
int signum(long long a) { return (a == 0 ? 0 : (a > 0 ? 1 : -1)); }
int dir(pair<long long, long long>& a, pair<long long, long long>& b,
        pair<long long, long long>& c) {
  return signum((b.first - a.first) * (c.second - a.second) -
                (b.second - a.second) * (c.first - a.first));
}
bool inside(vector<pair<long long, long long> >& hull,
            pair<long long, long long>& p) {
  if (dir(hull[0], hull[1], p) != 1) return false;
  if (dir(hull[0], hull[hull.size() - 1], p) != -1) return false;
  int l = 1, r = hull.size() - 2;
  while (l < r) {
    int m = (l + r) / 2 + 1;
    if (dir(hull[0], hull[m], p) == -1)
      r = m - 1;
    else
      l = m;
  }
  return dir(hull[l], hull[l + 1], p) == 1;
}
int main() {
  int n, m;
  cin >> n;
  vector<pair<long long, long long> > A(n);
  for (pair<long long, long long>& a : A) cin >> a.first >> a.second;
  reverse(A.begin(), A.end());
  cin >> m;
  vector<pair<long long, long long> > B(m);
  bool sol = true;
  for (pair<long long, long long>& a : B) {
    cin >> a.first >> a.second;
    sol &= inside(A, a);
  }
  cout << (sol ? "YES" : "NO") << endl;
}
