#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int h, w, k, e, temp, m[N][N];
string s;
vector<string> hor, ver;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> w >> k;
  for (int i = 0; i < 2 * h - 1; ++i) {
    cin >> s;
    if (i % 2)
      ver.push_back(s);
    else
      hor.push_back(s);
    for (int j = 0; j < s.size(); ++j)
      if (s[j] == 'E') ++e;
  }
  if (k >= 2) {
    if (w >= h)
      for (int i = 0; i < h; ++i) {
        m[i][0] = 1;
        for (int j = 1; j < w; ++j) {
          if (hor[i][j - 1] == 'E')
            m[i][j] = m[i][j - 1];
          else
            m[i][j] = 3 - m[i][j - 1];
        }
        if (!i) continue;
        temp = 0;
        for (int j = 0; j < w; ++j) {
          if (ver[i - 1][j] == 'E' && m[i][j] == m[i - 1][j]) ++temp;
          if (ver[i - 1][j] == 'N' && m[i][j] != m[i - 1][j]) ++temp;
        }
        if (2 * temp >= w) continue;
        for (int j = 0; j < w; ++j) m[i][j] = 3 - m[i][j];
      }
    else
      for (int i = 0; i < w; ++i) {
        m[0][i] = 1;
        for (int j = 1; j < h; ++j) {
          if (ver[j - 1][i] == 'E')
            m[j][i] = m[j - 1][i];
          else
            m[j][i] = 3 - m[j - 1][i];
        }
        if (!i) continue;
        temp = 0;
        for (int j = 0; j < h; ++j) {
          if (hor[j][i - 1] == 'E' && m[j][i] == m[j][i - 1]) ++temp;
          if (hor[j][i - 1] == 'N' && m[j][i] != m[j][i - 1]) ++temp;
        }
        if (2 * temp >= h) continue;
        for (int j = 0; j < h; ++j) m[j][i] = 3 - m[j][i];
      }
  }
  if (k == 1) {
    if (4 * e < (3 * (2 * w * h - w - h))) return cout << "NO\n", 0;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) m[i][j] = 1;
  }
  cout << "YES\n";
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) cout << m[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
