#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<pair<int, int>, pair<int, int>>> objs;
vector<int> xline;
int main() {
  int k;
  long long ans = 0;
  scanf("%d%d%d", &n, &m, &k);
  char a[n + 5][m + 5];
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        int ii = i, jj = j;
        while (a[ii][j] == '*') {
          ii++;
        }
        ii--;
        while (a[i][jj] == '*') {
          jj++;
        }
        jj--;
        objs.push_back(make_pair(make_pair(i, j), make_pair(ii, jj)));
        xline.push_back(i);
        xline.push_back(ii);
        for (int p = i; p <= ii; p++) {
          for (int q = j; q <= jj; q++) {
            a[p][q] = '.';
          }
        }
      }
    }
  }
  xline.push_back(0);
  sort(xline.begin(), xline.end());
  xline.erase(unique(xline.begin(), xline.end()), xline.end());
  for (int i = 0; i < xline.size(); i++) {
    for (int j = i; j < xline.size(); j++) {
      int left = xline[i], right = xline[j];
      vector<pair<int, int>> yline;
      for (int k = 0; k < objs.size(); k++) {
        if (objs[k].first.first > right || objs[k].second.first < left) {
          continue;
        }
        if (objs[k].first.first >= left && objs[k].second.first <= right) {
          yline.push_back(make_pair(objs[k].first.second, -1));
          yline.push_back(make_pair(objs[k].second.second, 1));
        } else {
          yline.push_back(make_pair(objs[k].first.second, -10));
          yline.push_back(make_pair(objs[k].second.second, 10));
        }
      }
      yline.push_back(make_pair(0, 0));
      sort(yline.begin(), yline.end());
      for (int C = 1; C <= 3; C++) {
        int bottom = 0, c = 0, sb = 0, su = 0;
        for (int u = 0; u < yline.size(); u++) {
          while (bottom < yline.size() && (sb != 0 || c < C)) {
            c += max(0, yline[bottom].second);
            sb += yline[bottom].second;
            bottom++;
          }
          if (c == C && sb == 0 && su == 0) {
            ans += (long long)(i == 0 ? 1 : left - xline[i - 1]) *
                   (j == xline.size() - 1 ? n - right : xline[j + 1] - right) *
                   (u == 0 ? 1 : yline[u].first - yline[u - 1].first) *
                   (bottom == yline.size()
                        ? m - yline[bottom - 1].first
                        : yline[bottom].first - yline[bottom - 1].first);
          }
          c -= max(0, yline[u].second);
          su += yline[u].second;
        }
      }
    }
  }
  printf("%lld", ans);
  return 0;
}
