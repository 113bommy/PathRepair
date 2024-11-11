#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double PI = acos(-1);
const double EPS = 1e-8;
int g[26][26];
pair<int, int> dis[26][26];
int main() {
  string s, t;
  cin >> s >> t;
  int n;
  cin >> n;
  for (int i = 0; i < (int)26; ++i)
    for (int j = 0; j < (int)26; ++j)
      if (i != j) g[i][j] = INF;
  for (int i = 0; i < (int)n; ++i) {
    char c1, c2;
    int w;
    cin >> c1 >> c2 >> w;
    c1 -= 'a';
    c2 -= 'a';
    g[c1][c2] = min(g[c1][c2], w);
  }
  if (s.size() != t.size()) {
    cout << -1 << endl;
    return 0;
  }
  for (int k = 0; k < (int)26; ++k)
    for (int i = 0; i < (int)26; ++i)
      for (int j = 0; j < (int)26; ++j)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = 0; i < (int)26; ++i) {
    for (int j = 0; j < (int)26; ++j) {
      int mi = INF;
      int id = -1;
      for (int k = 0; k < (int)26; ++k) {
        if (mi > g[i][k] + g[j][k]) {
          mi = g[i][k] + g[j][k];
          id = k;
        }
      }
      dis[i][j] = pair<int, int>(mi, id);
    }
  }
  long long ans = 0;
  string as;
  for (int i = 0; i < (int)s.size(); ++i) {
    int a = s[i] - 'a';
    int b = t[i] - 'a';
    if (dis[a][b].second < 0) {
      cout << -1 << endl;
      return 0;
    }
    ans += dis[a][b].first;
    as += 'a' + dis[a][b].second;
  }
  cout << ans << endl;
  cout << as << endl;
}
