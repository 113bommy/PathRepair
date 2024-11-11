#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string str[2001];
    long long n, m, i, j, k;
    cin >> n >> m;
    vector<pair<long long, long long> > v[30];
    for (i = 0; i < n; i++) cin >> str[i];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (str[i][j] != '.') v[str[i][j] - 'a'].push_back({i, j});
      }
    }
    long long cnt = 0;
    vector<pair<pair<long long, long long>, pair<long long, long long> > > ans;
    pair<long long, long long> last;
    long long flag = 0;
    for (k = 25; k >= 0; k--) {
      if ((!v[k].size()) && (!flag)) continue;
      if (!flag) last = v[k][0];
      flag = 1;
      if (!v[k].size()) {
        cnt++;
        ans.push_back({last, last});
        continue;
      }
      if (v[k].size() == 1) {
        cnt++;
        ans.push_back(
            {{v[k][0].first, v[k][0].second}, {v[k][0].first, v[k][0].second}});
        str[v[k][0].first][v[k][0].second] = '?';
        continue;
      }
      cnt++;
      if (v[k][0].first == v[k][1].first) {
        for (i = 1; i < v[k].size(); i++) {
          if (v[k][i].first != v[k][i - 1].first) break;
        }
        if (i < v[k].size()) break;
        i = v[k][0].first;
        j = v[k][0].second;
        for (j; j <= v[k][v[k].size() - 1].second; j++) {
          if ((str[i][j] != 'a' + k) && (str[i][j] != '?')) break;
        }
        if (j <= v[k][v[k].size() - 1].second) break;
        j = v[k][0].second;
        for (j; j <= v[k][v[k].size() - 1].second; j++) str[i][j] = '?';
        ans.push_back({{v[k][0].first, v[k][0].second},
                       {v[k][0].first, v[k][v[k].size() - 1].second}});
      } else {
        for (i = 1; i < v[k].size(); i++) {
          if (v[k][i].second != v[k][i - 1].second) break;
        }
        if (i < v[k].size()) break;
        j = v[k][0].second;
        i = v[k][0].first;
        for (i; i <= v[k][v[k].size() - 1].first; i++) {
          if ((str[i][j] != 'a' + k) && (str[i][j] != '?')) break;
        }
        if (i <= v[k][v[k].size() - 1].first) break;
        i = v[k][0].first;
        for (i; i <= v[k][v[k].size() - 1].first; i++) str[i][j] = '?';
        ans.push_back({{v[k][0].first, v[k][0].second},
                       {v[k][v[k].size() - 1].first, v[k][0].second}});
      }
    }
    if (k < 0) {
      cout << "YES" << endl;
      cout << cnt << endl;
      if (!ans.empty()) {
        for (i = ans.size() - 1; i >= 0; i--)
          cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1
               << " " << ans[i].second.first + 1 << " "
               << ans[i].second.second + 1 << endl;
      }
    } else
      cout << "NO" << endl;
  }
  return 0;
}
