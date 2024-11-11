#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
int d, s;
int dp[505][5005];
pair<pair<int, int>, int> kotteke[505][5005];
queue<pair<int, int> > q;
int len = inf;
pair<pair<int, int>, int> beg;
void bfs() {
  dp[0][0] = 0;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i <= 9; ++i) {
      if (p.second + i > s) continue;
      if (dp[(p.first * 10 + i) % d][p.second + i] != -1) continue;
      dp[(p.first * 10 + i) % d][p.second + i] = dp[p.first][p.second] + 1;
      kotteke[(p.first * 10 + i) % d][p.second + i] = make_pair(p, i);
      if (p.second + i == s) {
        if ((p.first * 10 + i) % d == 0) {
          if (len > dp[(p.first * 10 + i) % d][p.second + i]) {
            len = dp[(p.first * 10 + i) % d][p.second + i];
            beg = make_pair(p, i);
          }
        }
      }
      q.push(make_pair((p.first * 10 + i) % d, p.second + i));
    }
  }
}
void print(pair<pair<int, int>, int> p) {
  if (p.first == make_pair(0, 0)) {
    cout << p.second;
    return;
  }
  print(kotteke[p.first.first][p.first.second]);
  cout << p.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(dp, -1, sizeof(dp));
  cin >> d >> s;
  bfs();
  if (len == inf)
    cout << -1;
  else
    print(beg);
}
