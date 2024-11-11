#include <bits/stdc++.h>
using namespace std;
const int NMAX = 3005;
int n, m;
vector<int> e[NMAX];
int s[2], t[2], l[2];
int d[NMAX][NMAX];
void bfs(int sid, int* d) {
  for (int i = 0; i < NMAX; i++) d[i] = 0x7FFF;
  d[sid] = 0;
  priority_queue<pair<int, int> > pq;
  pq.push(make_pair(0, sid));
  while (!pq.empty()) {
    pair<int, int> z = pq.top();
    pq.pop();
    int vid = z.second;
    for (auto it = e[vid].begin(); it != e[vid].end(); it++) {
      if (d[*it] == 0x7FFF) {
        d[*it] = z.first - 1;
        pq.push(make_pair(z.first - 1, *it));
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    e[v1].push_back(v2);
    e[v2].push_back(v1);
  }
  cin >> s[0] >> t[0] >> l[0];
  cin >> s[1] >> t[1] >> l[1];
  s[0]--;
  t[0]--;
  s[1]--;
  t[1]--;
  int maxl = max(l[0], l[1]);
  for (int i = 0; i < n; i++) bfs(i, d[i]);
  if (d[s[0]][t[0]] > l[0] || d[s[1]][t[1]] > l[1]) {
    cout << -1;
    return 0;
  }
  int minway = d[s[0]][t[0]] + d[s[1]][t[1]];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int w1 = d[i][j] + min(d[i][s[0]] + d[j][t[0]], d[i][t[0]] + d[j][s[0]]);
      if (w1 <= l[0]) {
        int w2 =
            d[i][j] + min(d[i][s[1]] + d[j][t[1]], d[i][t[1]] + d[j][s[1]]);
        if (w2 <= l[1]) minway = min(minway, w1 + w2 - d[i][j]);
      }
    }
  }
  cout << m - minway;
  return 0;
}
