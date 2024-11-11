#include <bits/stdc++.h>
using namespace std;
int n;
long long qry(int t, int i, int j, int k) {
  cout << t << " " << i << " " << j << " " << k << endl;
  long long ans;
  cin >> ans;
  return ans;
}
vector<int> solve(vector<int> pts) {
  if (pts.size() <= 1) return pts;
  map<int, long long> dists;
  long long y = 0, max_dist = 0;
  for (int x : pts) {
    dists[x] = qry(1, 1, 2, x);
    if (max_dist < dists[x]) {
      max_dist = dists[x];
      y = x;
    }
  }
  vector<int> l, r, ans;
  for (int p : pts) {
    if (p == y) continue;
    if (qry(2, y, 1, p) == -1)
      r.push_back(p);
    else
      l.push_back(p);
  }
  sort(l.begin(), l.end(),
       [&](int i, int j) -> bool { return dists[i] > dists[j]; });
  sort(r.begin(), r.end(),
       [&](int i, int j) -> bool { return dists[i] < dists[j]; });
  for (int p : r) ans.push_back(p);
  ans.push_back(y);
  for (int p : l) ans.push_back(p);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  vector<int> l, r;
  for (int p = 3; p <= n; p++) {
    if (qry(2, 1, 2, p) == -1)
      r.push_back(p);
    else
      l.push_back(p);
  }
  l = solve(l);
  r = solve(r);
  cout << "0 1 ";
  for (int p : r) cout << p << " ";
  cout << 2 << " ";
  for (int p : l) cout << p << " ";
  cout << endl;
}
