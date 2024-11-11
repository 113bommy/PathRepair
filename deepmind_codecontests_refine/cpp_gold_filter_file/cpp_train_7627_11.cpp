#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> r;
bool f(int x) {
  vector<int> a(n, 0), b(n, 0);
  for (auto p : r) {
    if (p[2] > x) continue;
    a[p[0]]++, b[p[1]]++;
  }
  for (int x : a)
    if (!x) return 0;
  for (int x : b)
    if (!x) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    vector<int> in(3);
    for (int &x : in) cin >> x;
    in[0]--, in[1]--;
    r.push_back(in);
  }
  long long l = 0, r = 2e9;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (f(m))
      r = m;
    else
      l = m;
  }
  if (f(r))
    cout << r;
  else
    cout << -1;
  return 0;
}
