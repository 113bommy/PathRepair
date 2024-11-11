#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr;
int dist[11111], maxs = 987654321;
int abs(int a) { return a > 0 ? a : -a; }
int main(void) {
  int n, m, k, poss = 1;
  cin >> n >> m >> k;
  for (int e = 0; e < k; e++) {
    int a, b;
    cin >> a >> b;
    if (a == n && b == m) poss = 0;
    arr.push_back(make_pair(a, b));
  }
  for (int e = 0; e < 11111; e++) dist[e] = 987654321;
  queue<pair<pair<int, int>, pair<int, int> > > q;
  q.push(make_pair(make_pair(1, 1), make_pair(0, 0)));
  while (!q.empty()) {
    int nowy = q.front().first.first, nowx = q.front().first.second,
        num = q.front().second.first, v = q.front().second.second;
    q.pop();
    if (dist[v] <= num) continue;
    dist[v] = num;
    if (abs(nowy - n) + abs(nowx - m) <= 1)
      maxs = min(maxs, num + poss);
    else if (abs(nowy - n) <= 1 || abs(nowx - m) <= 1)
      maxs = min(maxs, num + 1);
    for (int e = 0; e < arr.size(); e++) {
      if (e == v) continue;
      int nexty = arr[e].first, nextx = arr[e].second;
      if (abs(nowy - nexty) + abs(nowx - nextx) == 1) {
        if (dist[e] > num) {
          q.push(make_pair(make_pair(nexty, nextx), make_pair(num, e)));
        }
      } else if (abs(nowy - nexty) <= 2 || abs(nowx - nextx) <= 2) {
        if (dist[e] > num + 1) {
          q.push(make_pair(make_pair(nexty, nextx), make_pair(num + 1, e)));
        }
      }
    }
  }
  if (maxs == 987654321)
    cout << "-1";
  else
    cout << maxs;
}
