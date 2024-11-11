#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
const long long INF = 1e16;
char b[1010][1010];
long long xs, ys, xe, ye;
long long d[1010][1010];
bool vis[1010][1010];
void fuck_me_man_i_am_stupid() {
  d[xs][ys] = 0;
  queue<pair<long long, long long> > q;
  q.push(make_pair(xs, ys));
  while (q.empty() == false) {
    long long x = q.front().first;
    long long y = q.front().second;
    long long curd = d[x][y];
    q.pop();
    long long steps = 0;
    for (long long i = x - 1;
         i >= 1 && steps < k && d[i][y] > d[x][y] + 1 && b[i][y] == '.'; i--) {
      if (vis[i][y] == false) {
        d[i][y] = d[x][y] + 1;
        vis[i][y] = true;
        q.push(make_pair(i, y));
      }
      steps++;
    }
    steps = 0;
    for (long long i = x + 1;
         i <= n && steps < k && d[i][y] > d[x][y] + 1 && b[i][y] == '.'; i++) {
      if (vis[i][y] == false) {
        d[i][y] = d[x][y] + 1;
        vis[i][y] = true;
        q.push(make_pair(i, y));
      }
      steps++;
    }
    steps = 0;
    for (long long i = y - 1;
         i >= 1 && steps < k && d[x][i] > d[x][y] + 1 && b[x][i] == '.'; i--) {
      if (vis[x][i] == false) {
        d[x][i] = d[x][y] + 1;
        vis[x][i] = true;
        q.push(make_pair(x, i));
      }
      steps++;
    }
    steps = 0;
    for (long long i = y + 1;
         i <= m && steps < k && d[x][i] > d[x][y] + 1 && b[x][i] == '.'; i++) {
      if (vis[x][i] == false) {
        d[x][i] = d[x][y] + 1;
        vis[x][i] = true;
        q.push(make_pair(x, i));
      }
      steps++;
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> b[i][j];
  }
  cin >> xs >> ys >> xe >> ye;
  for (long long i = 0; i <= 1002; i++) {
    for (long long j = 0; j <= 1002; j++) d[i][j] = INF;
  }
  fuck_me_man_i_am_stupid();
  d[xe][ye] == INF ? cout << "-1\n" : cout << d[xe][ye] << endl;
  return 0;
}
