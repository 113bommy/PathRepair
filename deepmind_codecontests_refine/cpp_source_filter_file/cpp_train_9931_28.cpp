#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T> v) {
  cerr << "[";
  if (v.size()) cerr << v[0];
  for (int i = (1); i < (v.size()); ++i) cerr << ", " << v[i];
  cerr << "]\n";
}
template <class T>
string i2s(T x) {
  ostringstream o;
  o << x;
  return o.str();
}
vector<string> splt(string s, char c = ' ') {
  vector<string> all;
  int p = 0, np;
  while (np = s.find(c, p), np >= 0) {
    if (np != p) all.push_back(s.substr(p, np - p));
    p = np + 1;
  }
  if (p < s.size()) all.push_back(s.substr(p));
  return all;
}
int h, w;
int data[1700][1700];
int edge[1700][1700];
int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
int main() {
  cin >> h >> w;
  for (int i = (0); i < (h); ++i)
    for (int j = (0); j < (w); ++j) scanf("%d", &data[i][j]);
  for (int r = (0); r < (h); ++r)
    for (int c = (0); c < (w); ++c)
      if (data[r][c]) {
        for (int d = (0); d < (4); ++d) {
          int nr = r + dr[d];
          int nc = c + dc[d];
          if (nr < 0 || nr >= h || nc < 0 || nc >= w || data[nr][nc] == 0)
            edge[r][c] = 1;
        }
      }
  vector<int> rays;
  for (int r = (0); r < (h); ++r)
    for (int c = (0); c < (w); ++c)
      if (edge[r][c]) {
        vector<pair<int, int> > v;
        int cr = r;
        int cc = c;
        while (edge[cr][cc]) {
          v.push_back(make_pair(cr, cc));
          edge[cr][cc] = 0;
          for (int d = (0); d < (8); ++d) {
            int nr = cr + dr[d];
            int nc = cc + dc[d];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && edge[nr][nc]) {
              cr = nr;
              cc = nc;
              break;
            }
          }
        }
        int bv = -1;
        int bp = -1;
        for (int i = (0); i < (v.size()); ++i)
          for (int j = (13); j < (130); ++j) {
            int sx = v[i].first;
            int sy = v[i].second;
            int ex = v[(i + j) % v.size()].first;
            int ey = v[(i + j) % v.size()].second;
            if (abs(sx - ex) > 36 || abs(sy - ey) > 36) break;
            if (abs(sx - ex) <= 4 && abs(sy - ey) <= 4) {
              if (j > bv) {
                bv = j;
                bp = i;
              }
            }
          }
        int count = 0;
        for (int i = (0); i < (v.size()); ++i)
          for (int j = (13); j < (130); ++j) {
            int sx = v[(i + bp) % v.size()].first;
            int sy = v[(i + bp) % v.size()].second;
            int ex = v[(i + j + bp) % v.size()].first;
            int ey = v[(i + j + bp) % v.size()].second;
            if (i + j > v.size()) break;
            if (abs(sx - ex) > 36 || abs(sy - ey) > 36) break;
            if (abs(sx - ex) <= 4 && abs(sy - ey) <= 4) {
              count++;
              i += j;
              break;
            }
          }
        if (count) rays.push_back(count);
      }
  sort(rays.begin(), rays.end());
  cout << rays.size() << endl;
  for (int i = (0); i < (rays.size()); ++i) cout << rays[i] << ' ';
  cout << endl;
  return 0;
}
