#include <bits/stdc++.h>
using namespace std;
const double PI = atan(1) * 4;
const int cst = 100000;
int n;
pair<long long, long long> pt[111111];
int w[111111];
set<pair<long long, long long> > st[222222];
vector<int> prior[222222];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    cin >> pt[i].first >> pt[i].second;
    while ((int)prior[pt[i].first].size() <= pt[i].second)
      prior[pt[i].first].push_back(0);
    st[pt[i].second - pt[i].first + cst].insert(
        make_pair((pt[i].second + 1) * (pt[i].first + 1), i));
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
    w[i] += cst;
  }
  vector<int> res;
  long long cur = 0, prev = -1;
  for (int i = 1; i <= n; ++i) {
    if (st[w[i]].empty()) {
      puts("NO");
      return 0;
    }
    cur = st[w[i]].begin()->first;
    int ind = st[w[i]].begin()->second;
    prior[pt[ind].first][pt[ind].second] = i;
    res.push_back(ind);
    st[w[i]].erase(st[w[i]].begin());
  }
  for (int i = 0; i <= 200000; ++i) {
    for (int j = 0; j <= (int)prior[i].size(); ++j) {
      if (j + 1 < (int)prior[i].size() && prior[i][j + 1] < prior[i][j]) {
        puts("NO");
        return 0;
      }
      if (j < (int)prior[i + 1].size() && prior[i + 1][j] < prior[i][j]) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (int i = 0; i <= (int)res.size() - 1; ++i)
    cout << pt[res[i]].first << ' ' << pt[res[i]].second << endl;
}
