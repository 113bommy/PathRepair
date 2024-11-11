#include <bits/stdc++.h>
using namespace std;
const char infile[] = "input.in";
const char outfile[] = "output.out";
ifstream fin(infile);
ofstream fout(outfile);
const int MAXN = 100005;
const int oo = 0x3f3f3f3f;
typedef vector<pair<int, int> > Graph[MAXN];
const inline int min(const int &a, const int &b) {
  if (a > b) return b;
  return a;
}
const inline int max(const int &a, const int &b) {
  if (a < b) return b;
  return a;
}
const inline void Get_min(int &a, const int b) {
  if (a > b) a = b;
}
const inline void Get_max(int &a, const int b) {
  if (a < b) a = b;
}
int N, M;
int dp[MAXN];
Graph G;
vector<int> T[MAXN];
int main() {
  cin.sync_with_stdio(false);
  fin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    int x, y, z;
    fin >> x >> y >> z;
    G[x].push_back(make_pair(y, z));
    G[y].push_back(make_pair(x, z));
  }
  for (int i = 1; i <= N; ++i) {
    int x;
    fin >> x;
    for (int j = 1; j <= x; ++j) {
      int y;
      fin >> y;
      T[i].push_back(y);
    }
  }
  memset(dp, oo, sizeof(dp));
  dp[1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      Q;
  Q.push(make_pair(dp[1], 1));
  while (!Q.empty()) {
    int Node = Q.top().second;
    int time = Q.top().first;
    Q.pop();
    if (dp[Node] < time) continue;
    vector<int>::iterator iter =
        lower_bound(T[Node].begin(), T[Node].end(), time);
    while (iter != T[Node].end() && *iter == time) {
      ++time;
      ++iter;
    }
    for (vector<pair<int, int> >::iterator it = G[Node].begin(),
                                           fin = G[Node].end();
         it != fin; ++it)
      if (dp[it->first] > time + it->second) {
        dp[it->first] = time + it->second;
        Q.push(make_pair(dp[it->first], it->first));
      }
  }
  if (dp[N] == oo)
    fout << "-1\n";
  else
    fout << dp[N] << '\n';
  return 0;
}
