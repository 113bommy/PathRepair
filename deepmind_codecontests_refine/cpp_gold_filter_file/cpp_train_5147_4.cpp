#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(std::istream& in, vector<T>& a) {
  for (auto& it : a) in >> it;
  return in;
}
template <typename T1, typename T2>
istream& operator>>(std::istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
ostream& operator<<(std::ostream& out, vector<T>& a) {
  for (auto it : a) {
    out << " " << it;
  }
  out << endl;
  return out;
}
template <typename T1, typename T2>
ostream& operator<<(std::ostream& out, pair<T1, T2>& a) {
  out << a.first << ' ' << a.second;
  return out;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int> > x(n, vector<int>(n, 0));
  bool ok = 1;
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= k; j++) {
      if (x[i][(i + j) % n] || x[(i + j) % n][i]) ok = 0;
      x[i][(i + j) % n] = 1;
      x[(i + j) % n][i] = -1;
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (x[i][j] == 1) ans++;
  if (!ans || !ok) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (x[i][j] == 1) cout << i + 1 << ' ' << j + 1 << endl;
}
