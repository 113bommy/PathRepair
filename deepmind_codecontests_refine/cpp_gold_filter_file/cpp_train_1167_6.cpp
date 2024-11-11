#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int i, j, k;
  pair<int, int> p[n];
  int a, b;
  vector<char> v;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    p[i].first = a;
    p[i].second = b;
  }
  sort(p, p + n);
  int l_ind = 0;
  int u_ind = 0;
  for (i = 0; i < n; i++) {
    if (p[i].second < p[i - 1].second && i >= 1) {
      cout << "NO\n";
      return;
    } else {
      int x1 = p[i].first - l_ind;
      int y1 = p[i].second - u_ind;
      for (j = 0; j < x1; j++) v.push_back('R');
      for (j = 0; j < y1; j++) v.push_back('U');
      l_ind = p[i].first;
      u_ind = p[i].second;
    }
  }
  cout << "YES\n";
  for (i = 0; i < v.size(); i++) cout << v[i];
  cout << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
