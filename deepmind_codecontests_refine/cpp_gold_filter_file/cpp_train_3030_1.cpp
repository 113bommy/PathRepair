#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
void ans(bool b) {
  if (b) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  if (0) cout << fixed << setprecision(6);
  long long n;
  cin >> n;
  vector<vector<long long>> graph(n + 1);
  for (long long i = (0); i <= ((long long)(n - 1) - 1); i++) {
    long long a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<long long> bfs(n);
  for (long long i = (0); i <= ((long long)(n)-1); i++) {
    cin >> bfs[i];
  }
  long long idx = 0;
  vector<long long> q = {1};
  vector<bool> vis(n + 1);
  vis[1] = true;
  vector<long long> father(n + 1, -1);
  vector<long long> d(n + 1);
  long long dist = 0;
  while (!q.empty()) {
    vector<long long> nq;
    for (long long a : q) {
      d[a] = dist;
      for (long long b : graph[a]) {
        father[b] = a;
        if (vis[b]) {
          continue;
        }
        nq.push_back(b);
        vis[b] = true;
      }
    }
    dist++;
    q = move(nq);
  }
  vector<long long> nbfs = bfs;
  sort((nbfs).begin(), (nbfs).end());
  nbfs.resize(unique((nbfs).begin(), (nbfs).end()) - nbfs.begin());
  if (((long long)(nbfs).size()) != n) {
    ans(0);
  }
  nbfs = bfs;
  for (long long &a : nbfs) {
    a = d[a];
  }
  for (long long i = (1); i <= (n - 1); i++) {
    if (nbfs[i] < nbfs[i - 1]) {
      ans(0);
    }
  }
  if (bfs[0] != 1) {
    ans(0);
  }
  long long nxtIdx = 0;
  while (nxtIdx != n && d[bfs[nxtIdx]] == 0) {
    nxtIdx++;
  }
  vis = vector<bool>(n + 1);
  vis[1] = true;
  for (long long a : bfs) {
    set<long long> toVisit;
    for (long long b : graph[a]) {
      if (vis[b]) {
        continue;
      }
      toVisit.insert(b);
      vis[b] = true;
    }
    while (!toVisit.empty()) {
      if (nxtIdx == n || !toVisit.count(bfs[nxtIdx])) {
        ans(0);
      }
      toVisit.erase(bfs[nxtIdx++]);
    }
  }
  ans(1);
}
