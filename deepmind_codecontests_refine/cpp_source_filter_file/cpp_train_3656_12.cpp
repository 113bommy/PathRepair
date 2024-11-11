#include <bits/stdc++.h>
using namespace std;
void File() {}
int vis[501][5010] = {0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  File();
  int d, sum;
  cin >> d >> sum;
  map<string, pair<int, int>> mp;
  queue<pair<pair<int, int>, string>> q;
  for (int i = 1; i < 10; i++) {
    q.push({{i % d, i}, string(1, '0' + i)});
    vis[i % d][i] = 1;
  }
  while (q.size()) {
    int md = q.front().first.first;
    int sm = q.front().first.second;
    string cur = q.front().second;
    q.pop();
    if (!md && sm == sum) return cout << cur << "\n", 0;
    if (sm >= sum) continue;
    if (cur.size() == 5001) break;
    for (int i = 0; i < 10; i++) {
      int nmd = (md * 10) + i;
      nmd %= d;
      int nsm = sm + i;
      if (!vis[nmd][nsm]) {
        vis[nmd][nsm] = 1;
        q.push({{nmd, nsm}, cur + string(1, i + '0')});
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}
