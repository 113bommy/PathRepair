#include <bits/stdc++.h>
using namespace std;
double dist(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) * 1. + (y1 - y2) * (y1 - y2));
}
int main() {
  int a, b;
  cin >> a >> b;
  int Ax, Ay, Bx, By;
  cin >> Ax >> Ay >> Bx >> By;
  int n;
  cin >> n;
  vector<int> x1(n + 2), y1(n + 2), x2(n + 2), y2(n + 2);
  for (int i = 1; i <= n; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  x1[0] = x2[0] = Ax;
  y1[0] = y2[0] = Ay;
  x2[n + 1] = x1[n + 1] = Bx;
  y2[n + 1] = y1[n + 1] = By;
  for (int i = 0; i < n + 2; i++)
    if (x1[i] == x2[i] && y1[i] > y2[i])
      swap(y1[i], y2[i]);
    else if (y1[i] == y2[i] && x1[i] > x2[i])
      swap(x1[i], x2[i]);
  vector<vector<double> > graph(n + 2, vector<double>(n + 2));
  for (int i = 0; i < n + 2; i++) {
    for (int j = i + 1; j < n + 2; j++) {
      double res = 0;
      if (x1[i] == x2[i] && x1[j] == x2[j]) {
        if (y2[i] < y1[j] || y2[j] < y1[i])
          res = min(dist(x1[i], y1[i], x2[j], y2[j]),
                    dist(x1[j], y1[j], x2[i], y2[i]));
        else
          res = abs(x1[i] - x2[j]);
      } else if (y1[i] == y2[i] && y1[j] == y2[j]) {
        if (x2[i] < x1[j] || x2[j] < x1[i])
          res = min(dist(x1[i], y1[i], x2[j], y2[j]),
                    dist(x1[j], y1[j], x2[i], y2[i]));
        else
          res = abs(y1[i] - y2[j]);
      } else if (x1[i] == x2[i]) {
        if ((y2[i] < y1[j] || y1[i] > y2[j]) &&
            (x2[i] < x1[j] || x1[i] > x2[j])) {
          res = min(dist(x1[i], y1[i], x2[j], y2[j]),
                    dist(x1[j], y1[j], x2[i], y2[i]));
          res = min(res, dist(x1[i], y1[i], x1[j], y1[j]));
          res = min(res, dist(x2[j], y2[j], x2[i], y2[i]));
        } else if ((y2[i] < y1[j] || y1[i] > y2[j])) {
          res = min(abs(y1[i] - y1[j]), abs(y2[j] - y2[j]));
        } else {
          res = min(abs(x1[i] - x1[j]), abs(x2[i] - x2[j]));
        }
      } else {
        if ((y2[i] < y1[j] || y1[i] > y2[j]) &&
            (x2[i] < x1[j] || x1[i] > x2[j])) {
          res = min(dist(x1[i], y1[i], x2[j], y2[j]),
                    dist(x1[j], y1[j], x2[i], y2[i]));
          res = min(res, dist(x1[i], y1[i], x1[j], y1[j]));
          res = min(res, dist(x2[j], y2[j], x2[i], y2[i]));
        } else if ((y2[i] < y1[j] || y1[i] > y2[j])) {
          res = min(abs(y1[i] - y1[j]), abs(y2[j] - y2[j]));
        } else {
          res = min(abs(x1[i] - x1[j]), abs(x2[i] - x2[j]));
        }
      }
      graph[i][j] = graph[j][i] = (res - 0.0000001) < a ? a + b : 0;
      if (graph[i][j] > 0 && j == n + 1) graph[i][j] = graph[j][i] = res + b;
    }
  }
  vector<pair<double, int> > next;
  vector<double> costs(n + 2);
  next.push_back(make_pair(0.0, 0));
  set<int> inds;
  inds.insert(0);
  while (!next.empty() && next.front().second != n + 1) {
    int cur = next.front().second;
    double cost = next.front().first;
    next.erase(next.begin());
    inds.erase(inds.find(cur));
    for (int i = 0; i < n + 2; i++) {
      if (graph[i][cur] == 0) continue;
      if (cost + graph[i][cur] < costs[i] || costs[i] == 0) {
        costs[i] = cost + graph[i][cur];
        if (inds.find(i) != inds.end()) {
          for (int j = 0; j < next.size(); j++)
            if (next[j].second == i) next.erase(next.begin() + j);
        }
        inds.insert(i);
        next.push_back(make_pair(costs[i], i));
      }
    }
  }
  cout.precision(15);
  if (next.empty())
    cout << -1 << endl;
  else
    cout << costs[n + 1] - b << endl;
}
