#include <bits/stdc++.h>
using namespace std;
const int N = 302;
vector<pair<pair<int, int>, pair<int, int> > > wow;
vector<pair<pair<int, int>, pair<int, int> > > wow1;
deque<int> lis[N][N];
int main() {
  int n, m, i, j, k, l;
  cin >> n >> m;
  string s;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> s;
      for (k = 0; k < s.size(); k++) {
        lis[i][j].push_back((s[i] - '0'));
      }
    }
  }
  for (i = 2; i <= m; i++) {
    while (lis[1][i].size()) {
      j = lis[1][i].back();
      lis[1][1].push_front(j);
      wow.push_back({{1, i}, {1, 1}});
      lis[1][i].pop_back();
    }
  }
  for (i = 2; i <= n; i++) {
    while (lis[i][1].size()) {
      j = lis[i][1].back();
      lis[1][1].push_front(j);
      wow.push_back({{i, 1}, {1, 1}});
      lis[i][1].pop_back();
    }
  }
  for (i = 2; i <= n; i++) {
    for (j = 2; j <= m; j++) {
      while (lis[i][j].size()) {
        if (lis[i][j].back() == 1) {
          lis[1][j].push_front(lis[i][j].back());
          wow.push_back({{i, j}, {1, j}});
        } else {
          lis[i][1].push_front(lis[i][j].back());
          wow.push_back({{i, j}, {i, 1}});
        }
        lis[i][j].pop_back();
      }
    }
  }
  for (i = 3; i <= n; i++) {
    while (lis[i][1].size()) {
      lis[i][1].pop_back();
      lis[2][1].push_front(0);
      wow.push_back({{i, 1}, {2, 1}});
    }
  }
  for (i = 3; i <= m; i++) {
    while (lis[1][i].size()) {
      lis[1][i].pop_back();
      lis[1][2].push_front(1);
      wow.push_back({{1, i}, {1, 2}});
    }
  }
  while (lis[1][1].size()) {
    if (lis[1][1].back() == 1) {
      lis[1][1].pop_back();
      lis[1][2].push_front(1);
      wow.push_back({{1, 1}, {1, 2}});
    } else {
      lis[1][1].pop_back();
      lis[2][1].push_front(0);
      wow.push_back({{1, 1}, {2, 1}});
    }
  }
  lis[2][1].clear();
  lis[1][2].clear();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> s;
      for (k = 0; k < s.size(); k++) {
        lis[i][j].push_back((s[i] - '0'));
      }
    }
  }
  for (i = 2; i <= m; i++) {
    while (lis[1][i].size()) {
      j = lis[1][i].front();
      lis[1][1].push_back(j);
      wow1.push_back({{1, i}, {1, 1}});
      lis[1][i].pop_front();
    }
  }
  for (i = 2; i <= n; i++) {
    while (lis[i][1].size()) {
      j = lis[i][1].front();
      lis[1][1].push_back(j);
      wow1.push_back({{i, 1}, {1, 1}});
      lis[i][1].pop_front();
    }
  }
  for (i = 2; i <= n; i++) {
    for (j = 2; j <= m; j++) {
      while (lis[i][j].size()) {
        if (lis[i][j].front() == 1) {
          lis[1][j].push_back(lis[i][j].front());
          wow1.push_back({{i, j}, {1, j}});
        } else {
          lis[i][1].push_back(lis[i][j].front());
          wow1.push_back({{i, j}, {i, 1}});
        }
        lis[i][j].pop_front();
      }
    }
  }
  for (i = 3; i <= n; i++) {
    while (lis[i][1].size()) {
      lis[i][1].pop_front();
      lis[2][1].push_back(0);
      wow1.push_back({{i, 1}, {2, 1}});
    }
  }
  for (i = 3; i <= m; i++) {
    while (lis[1][i].size()) {
      lis[1][i].pop_front();
      lis[1][2].push_back(1);
      wow1.push_back({{1, i}, {1, 2}});
    }
  }
  while (lis[1][1].size()) {
    if (lis[1][1].front() == 1) {
      lis[1][1].pop_front();
      lis[1][2].push_back(1);
      wow1.push_back({{1, 1}, {1, 2}});
    } else {
      lis[1][1].pop_front();
      lis[2][1].push_back(0);
      wow1.push_back({{1, 1}, {2, 1}});
    }
  }
  cout << wow.size() + wow1.size() << "\n";
  for (i = 0; i < wow.size(); i++) {
    cout << wow[i].first.first << " " << wow[i].first.second << " "
         << wow[i].second.first << " " << wow[i].second.second << "\n";
  }
  for (i = wow1.size() - 1; i >= 0; i--) {
    cout << wow1[i].second.first << " " << wow1[i].second.second << " "
         << wow1[i].first.first << " " << wow1[i].first.second << "\n";
  }
}
