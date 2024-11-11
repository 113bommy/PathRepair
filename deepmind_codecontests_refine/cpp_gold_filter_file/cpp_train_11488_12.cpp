#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
int main() {
  int n, m, k;
  string str;
  cin >> n >> m >> k;
  vector<vector<int> > a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    b[i].resize(m);
    c[i].resize(m);
  }
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      cin >> a[i][j] >> b[i][j] >> c[i][j];
    }
  }
  int prib[m][n][n];
  for (int i = 0; i < m; i++) {
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = 0; i2 < n; i2++) {
        prib[i][i1][i2] = b[i2][i] - a[i1][i];
      }
    }
  }
  vector<pair<int, int> > buf;
  int maxprib = 0, ans = 0;
  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = 0; i2 < n; i2++) {
      buf.clear();
      for (int i = 0; i < m; i++) {
        buf.push_back(make_pair(prib[i][i1][i2], c[i1][i]));
      }
      sort(buf.begin(), buf.end(), greater<pair<int, int> >());
      if (buf[0].first <= 0)
        continue;
      else {
        int kk = k;
        maxprib = 0;
        for (int j = 0; j < buf.size(); j++)
          if (buf[j].first > 0) {
            if (buf[j].second >= kk) {
              maxprib += buf[j].first * kk;
              break;
            }
            kk -= buf[j].second;
            maxprib += buf[j].second * buf[j].first;
          }
        if (maxprib > ans) ans = maxprib;
      }
    }
  }
  cout << ans;
  return 0;
}
