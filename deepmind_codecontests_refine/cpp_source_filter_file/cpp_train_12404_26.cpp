#include <bits/stdc++.h>
const double E = 1e-8;
const double PI = acos(-1);
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> s(n), b(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  int maxe = *max_element(b.begin(), b.end());
  int mine = *min_element(s.begin(), s.end());
  if (mine >= maxe) {
    cout << r << '\n';
    return 0;
  }
  int total = 0;
  sort(s.begin(), s.end());
  for (int i = 0; i < n; ++i) {
    if (r >= s[i]) {
      total += r / s[i];
      r %= s[i];
    }
  }
  cout << total * maxe + r << '\n';
  return 0;
}
