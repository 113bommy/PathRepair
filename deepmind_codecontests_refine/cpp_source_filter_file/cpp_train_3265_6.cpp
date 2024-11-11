#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char a[1001][1001];
pair<int, int> whr[26];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int find_dir(pair<int, int> sr, pair<int, int> ds) {
  if (sr.first == ds.first) {
    if (sr.second < ds.second)
      return 3;
    else
      return 2;
  } else {
    if (sr.first < ds.first)
      return 0;
    else
      return 1;
  }
}
int main() {
  int t = 1;
  while (t--) {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> a[i][j];
        if (a[i][j] <= 'z' && a[i][j] >= 'a') {
          whr[a[i][j] - 'a'] = pair<int, int>(i, j);
          a[i][j] = '1';
        }
      }
    }
    pair<int, int> s, d;
    string rt;
    cin >> s.first >> s.second >> rt >> d.first >> d.second;
    int go = 0, i = 0;
    for (; i < rt.size(); ++i) {
      pair<int, int> des = whr[rt[i] - 'a'];
      int DDD = find_dir(s, des);
      while (s.first != des.first && s.second != des.second) {
        go += a[s.first][s.second] - '0';
        if (go > k) break;
        s.first += dir[DDD][0];
        s.second += dir[DDD][1];
      }
      if (go >= k) break;
    }
    if (go < k) {
      int DDD = find_dir(s, d);
      while (s.first != d.first && s.second != d.second) {
        go += a[s.first][s.second] - '0';
        if (go > k) break;
        s.first += dir[DDD][0];
        s.second += dir[DDD][1];
      }
      if (go >= k) break;
    }
    cout << s.first << " " << s.second << endl;
  }
  return 0;
}
