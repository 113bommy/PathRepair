#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[100005];
bool isvol[100005];
int dist[100005];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    d;
int main() {
  for (int i = 0; i < 100005; i++) {
    dist[i] = 1000000;
  }
  int n, m, k;
  cin >> n >> m >> k;
  int s, t;
  int end1, end2;
  int test;
  for (int i = 0; i < k; i++) {
    cin >> test;
    isvol[test] = true;
  }
  for (int i = 0; i < m; i++) {
    cin >> end1 >> end2;
    adjlist[end1].push_back(end2);
    adjlist[end2].push_back(end1);
  }
  cin >> s >> t;
  dist[t] = 0;
  d.push({0, t});
  int ans = 0;
  while (!d.empty()) {
    pair<int, int> v = d.top();
    d.pop();
    ans = max(v.first, ans);
    if (v.second == 1) {
      cout << ans << endl;
      return 0;
    }
    for (auto iter = adjlist[v.second].begin(); iter < adjlist[v.second].end();
         iter++) {
      if (isvol[v.second]) {
        if (dist[(*iter)] > 1) {
          dist[(*iter)] = 1;
          d.push({1, (*iter)});
        }
      } else {
        if (dist[(*iter)] > v.first + 1) {
          dist[(*iter)] = v.first + 1;
          d.push({v.first + 1, (*iter)});
        }
      }
    }
  }
  if (dist[s] == 1000000) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
