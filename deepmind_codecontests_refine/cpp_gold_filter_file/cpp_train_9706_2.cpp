#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000, INF = 1000000000;
int N, a[MAXN], at, answer = INF, dist[MAXN], good;
vector<int> vals[MAXN], adj[MAXN], start;
map<int, int> ind;
bool visited[MAXN];
queue<pair<int, pair<int, int> > > next1;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    good = max(good, a[i]);
  }
  good = sqrt(good);
  for (int i = 0; i < N; i++) {
    int x = a[i];
    for (int j = 2; j <= sqrt(x); j++) {
      int cnt = 0;
      while (x % j == 0) {
        x /= j;
        cnt++;
      }
      if (cnt % 2 == 1) {
        vals[i].push_back(j);
      }
    }
    if (vals[i].empty() && x == 1) {
      cout << 1 << endl;
      return 0;
    }
    vals[i].push_back(x);
    if (vals[i].size() == 1) {
      vals[i].push_back(1);
    }
    assert(vals[i].size() == 2);
    for (int j : vals[i]) {
      if (ind.find(j) == ind.end()) {
        ind[j] = at;
        if (j <= good) {
          start.push_back(at);
        }
        at++;
      }
    }
    adj[ind[vals[i][0]]].push_back(ind[vals[i][1]]);
    adj[ind[vals[i][1]]].push_back(ind[vals[i][0]]);
  }
  for (int j : start) {
    memset(visited, false, sizeof(visited));
    next1.push(make_pair(0, make_pair(j, j)));
    while (!next1.empty()) {
      int d = next1.front().first;
      int x = next1.front().second.first;
      int p = next1.front().second.second;
      next1.pop();
      if (visited[x]) {
        continue;
      }
      visited[x] = true;
      dist[x] = d;
      bool skip = false;
      for (int i : adj[x]) {
        if (i != p || skip) {
          if (visited[i]) {
            answer = min(answer, dist[i] + dist[x] + 1);
          } else {
            next1.push(make_pair(d + 1, make_pair(i, x)));
          }
        } else
          skip = true;
      }
    }
  }
  if (answer == INF) answer = -1;
  cout << answer << endl;
}
