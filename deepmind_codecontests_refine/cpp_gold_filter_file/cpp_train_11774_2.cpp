#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
template <typename T>
using v = vector<T>;
const long long inf = 4611686018427387903;
void read() {}
template <typename Arg, typename... Args>
void read(Arg& arg, Args&... args) {
  cin >> (arg);
  read(args...);
}
void print() {}
template <typename Arg, typename... Args>
void print(Arg arg, Args... args) {
  cout << (arg) << " ";
  print(args...);
}
void debug() { cout << endl; }
template <typename Arg, typename... Args>
void debug(Arg arg, Args... args) {
  cout << (arg) << " ";
  debug(args...);
}
int getInt() {
  int a;
  cin >> a;
  return a;
}
const int N = 2e5 + 1;
int n, m;
v<vector<int>> pos;
int k;
void run() {
  read(n, m, k);
  v<pair<int, int>> g[++n];
  for (int i = (0); i < (m); i++) {
    int v, u;
    read(v, u);
    g[v].push_back({u, i});
    g[u].push_back({v, i});
  }
  bool vis[n];
  for (int i = (1); i < (n); i++) vis[i] = 0;
  vis[1] = 1;
  queue<int> bfs;
  bfs.push(1);
  queue<pair<int, int>> posEdgesTo;
  vector<int> posEdges[n];
  int leftToVisit = n - 2;
  while (1) {
    set<int> willBeVisited;
    queue<int> nxt;
    while (!bfs.empty()) {
      int cur = bfs.front();
      bfs.pop();
      for (pair<int, int> z : g[cur]) {
        int i = z.first;
        if (willBeVisited.count(i)) posEdgesTo.push(z);
        if (vis[i]) continue;
        vis[i] = 1;
        willBeVisited.insert(i);
        nxt.push(i);
        posEdgesTo.push(z);
        leftToVisit--;
      }
    }
    bfs = nxt;
    if (leftToVisit == 0) {
      while (!posEdgesTo.empty()) {
        int i = posEdgesTo.front().first;
        int d = posEdgesTo.front().second;
        posEdges[i].push_back(d);
        posEdgesTo.pop();
      }
      int tot = 1;
      for (int i = (1); i < (n); i++)
        if (posEdges[i].empty())
          continue;
        else
          pos.push_back(posEdges[i]);
      for (vector<int> i : pos) tot = min(((int)i.size()) * tot, k);
      cout << tot;
      cout << endl;
      n = ((int)pos.size());
      int po[n];
      for (int i = (0); i < (n); i++) po[i] = 0;
      for (int i = (0); i < (tot); i++) {
        v<bool> paaa = v<bool>(m, 0);
        for (int j = (0); j < (n); j++) paaa[pos[j][po[j]]] = 1;
        for (bool j : paaa) cout << j;
        cout << endl;
        for (int j = n - 1; j >= 0; j--) {
          po[j]++;
          if (po[j] != ((int)pos[j].size()))
            break;
          else
            po[j] = 0;
        }
      }
      return;
    } else {
      while (!posEdgesTo.empty()) {
        int i = posEdgesTo.front().first;
        int d = posEdgesTo.front().second;
        posEdges[i].push_back(d);
        posEdgesTo.pop();
      }
    }
  }
}
int32_t main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  run();
  return 0;
}
