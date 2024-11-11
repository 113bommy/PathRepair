#include <bits/stdc++.h>
using namespace std;
long long int ABS(long long int a) {
  if (a < 0) return (-a);
  return a;
}
vector<long long int> g[100001];
vector<long long int> p[100001];
map<pair<long long int, long long int>, int> l;
int visited[100001];
long long int ans[100001][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  priority_queue<pair<long long int, long long int> > q;
  long long int n, m, count = 0, z = 0;
  cin >> n >> m;
  for (int i = (0); i < (m); ++i) {
    long long int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back(b);
    g[b].push_back(a);
    p[a].push_back(c);
    p[b].push_back(c);
    l[make_pair(a, b)] = c;
    if (c == 1) z++;
  }
  for (int i = (1); i < (n + 1); ++i) ans[i][0] = 1000000000LL;
  long long int start = 1;
  ans[start][1] = 0;
  ans[start][0] = 0;
  visited[start] = -1;
  q.push(make_pair(0, start));
  while (!q.empty()) {
    long long int a = q.top().second;
    long long int d = q.top().first;
    q.pop();
    for (long long int ii = 0; ii < g[a].size(); ii++) {
      long long int i = g[a][ii];
      if (visited[i] == 1) continue;
      if (ans[i][0] > d + 1 or
          (ans[i][0] == d + 1 and ans[i][1] <= ans[a][1] + p[a][ii])) {
        ans[i][0] = d + 1;
        ans[i][1] = ans[a][1] + p[a][ii];
        ans[i][2] = a;
      }
      if (visited[i] == 0 and i != n) {
        visited[i] = -1;
        q.push(make_pair(-ans[i][0], i));
      }
    }
    visited[a] = 1;
  }
  vector<long long int> aens[3];
  long long int i = n;
  while (i != 1) {
    long long int nei = ans[i][2];
    if (l.find(make_pair(i, nei)) != l.end()) {
      if (l[make_pair(i, nei)] == 0) {
        aens[0].push_back(i);
        aens[1].push_back(nei);
        aens[2].push_back(1);
      }
      l[make_pair(i, nei)] = 2;
    } else {
      if (l[make_pair(nei, i)] == 0) {
        aens[0].push_back(i);
        aens[1].push_back(nei);
        aens[2].push_back(1);
      }
      l[make_pair(nei, i)] = 2;
    }
    i = nei;
  }
  for (auto &it : l) {
    if (it.second == 1) {
      aens[0].push_back(it.first.first);
      aens[1].push_back(it.first.second);
      aens[2].push_back(0);
    }
  }
  cout << aens[1].size() << "\n";
  for (int i = (0); i < (aens[1].size()); ++i)
    cout << aens[0][i] << " " << aens[1][i] << " " << aens[2][i] << "\n";
  return 0;
}
