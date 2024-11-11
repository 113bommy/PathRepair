#include <bits/stdc++.h>
using namespace std;
void execute();
int main() {
  ios_base::sync_with_stdio(0);
  execute();
  return 0;
}
int in[1000][1000];
set<int> msn[1000], msm[1000];
map<int, pair<int, int> > ksn[1000], ksm[1000];
void execute() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> in[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) msn[i].insert(in[i][j]);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) msm[i].insert(in[j][i]);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (auto it = msn[i].begin(); it != msn[i].end(); it++) {
      ksn[i][(*it)].first = cnt;
      ksn[i][(*it)].second = msn[i].size() - 1 - cnt;
      cnt++;
    }
  }
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (auto it = msm[i].begin(); it != msm[i].end(); it++) {
      ksm[i][(*it)].first = cnt;
      ksm[i][(*it)].second = msn[i].size() - 1 - cnt;
      cnt++;
    }
  }
  for (int i = 0; i < n; i++, cout << '\n')
    for (int j = 0; j < m; j++) {
      cout << max(ksn[i][in[i][j]].first, ksm[j][in[i][j]].first) + 1 +
                  max(ksn[i][in[i][j]].second, ksm[j][in[i][j]].second)
           << ' ';
    }
}
