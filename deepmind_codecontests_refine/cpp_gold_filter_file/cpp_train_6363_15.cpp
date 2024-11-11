#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& t) {
  return in >> t.first >> t.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& t) {
  return out << t.first << " " << t.second;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& t) {
  for (int i = 0; i < t.size(); i++) in >> t[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& t) {
  for (int i = 0; i < t.size(); i++) out << t[i] << " ";
  return out;
}
vector<pair<int, int> > ans;
vector<pair<int, int> > ve;
int is[1001][1001];
void draw(int i, int y1, int y2) {
  if (y1 > y2) swap(y1, y2);
  for (int j = y1; j <= y2; ++j) {
    if (is[i][j]) continue;
    ans.push_back({i, j});
    is[i][j] = 1;
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int rrrr = 1e5;
  pair<int, int> a, b, c;
  cin >> a >> b >> c;
  ve = {a, b, c};
  sort(ve.begin(), ve.end());
  int xl = ve[0].first;
  int xr = ve[2].first;
  vector<int> tve = {a.second, b.second, c.second};
  sort(tve.begin(), tve.end());
  int y = tve[1];
  for (int i = xl; i <= xr; ++i) {
    ans.push_back({i, y});
    is[i][y] = 1;
    for (int j = 0; j < 3; ++j) {
      if (ve[j].first == i) {
        draw(i, ve[j].second, y);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto& j : ans) {
    cout << j << endl;
  }
  return 0;
}
