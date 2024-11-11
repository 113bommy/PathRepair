#include <bits/stdc++.h>
using namespace std;
int d, s;
pair<int, int> dp[510][5100];
queue<pair<int, int> > q;
int main(void) {
  for (int i = 0; i <= 500; ++i) {
    for (int j = 0; j <= 5000; ++j) {
      dp[i][j] = {-1, -1};
    }
  }
  dp[0][0] = {0, 0};
  cin >> d >> s;
  for (int i = 1; i < 10; ++i) {
    if (i <= s) {
      q.push({i % d, i});
      dp[i % d][i] = {0, 0};
    }
  }
  while (!q.empty()) {
    pair<int, int> a = q.front();
    q.pop();
    for (int i = 0; i < 10; ++i) {
      if (a.second + i <= s &&
          dp[(a.first * 10 + i) % d][a.second + i] == make_pair(-1, -1)) {
        dp[(a.first * 10 + i) % d][a.second + i] = {a.first, a.second};
        q.push({(a.first * 10 + i) % d, a.second + i});
      }
    }
  }
  if (dp[0][s] == make_pair(-1, -1)) {
    cout << -1 << endl;
    return 0;
  }
  int x = 0;
  int y = s;
  vector<int> v;
  while (x != 0 || y != 0) {
    pair<int, int> tmp = dp[x][y];
    v.push_back(y - tmp.second);
    x = tmp.first;
    y = tmp.second;
  }
  for (int i = v.size() - 1; i >= 0; --i) {
    cout << v[i];
  }
  cout << endl;
  return 0;
}
