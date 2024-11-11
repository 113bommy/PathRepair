#include <bits/stdc++.h>
using namespace std;
long long N, K;
long long sz[100010], U[100010], D[100010];
vector<pair<int, int>> adjlist[100010];
bool check_diam(int x) {
  queue<int> q;
  long long s = 0, counter = N;
  for (int i = 1; i <= N; i++) {
    if (adjlist[i].size() >= 3) {
      s++;
    }
    if (adjlist[i].size() == 1) {
      q.push(i);
    }
    U[i] = 0;
    D[i] = 0;
    sz[i] = adjlist[i].size();
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    pair<int, int> p;
    for (auto to : adjlist[v]) {
      if (!U[to.first]) {
        p = to;
        break;
      }
    }
    if (D[v] + p.second <= x) {
      if (sz[p.first] == 3) s--;
      D[p.first] = max(D[p.first], D[v] + p.second);
      sz[p.first]--;
      counter--;
      U[v] = 1;
      if (sz[p.first] == 1) {
        q.push(p.first);
      }
    }
  }
  if (!s && counter <= K) {
    return true;
  } else {
    return false;
  }
}
int main(int argc, const char* argv[]) {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;
  for (int i = 1; i < N; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    adjlist[u].push_back({v, x});
    adjlist[v].push_back({u, x});
  }
  int lo = 0, hi = 100010;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (check_diam(md)) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  cout << lo << endl;
  return 0;
}
