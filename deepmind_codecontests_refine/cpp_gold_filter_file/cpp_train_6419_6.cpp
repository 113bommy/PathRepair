#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
const int MAXN = 1003;
const long long INF = 1LL << 62LL;
vector<pair<long long, int> > adj1[MAXN], adj2[MAXN];
int N, M;
long long dist[MAXN], s[MAXN], e[MAXN];
void dijkstra(int strt) {
  for (int i = 0; i < N; i++) {
    dist[i] = INF;
  }
  dist[strt] = 0;
  set<pair<long long, int> > s;
  s.insert(pair<long long, int>(dist[strt], strt));
  while (!s.empty()) {
    strt = s.begin()->second;
    s.erase(pair<long long, int>(dist[strt], strt));
    for (int i = 0; i < adj1[strt].size(); i++) {
      int e = adj1[strt][i].first, cst = adj1[strt][i].second;
      if (dist[strt] + cst < dist[e]) {
        s.erase(pair<long long, int>(dist[e], e));
        dist[e] = dist[strt] + cst;
        s.insert(pair<long long, int>(dist[e], e));
      }
    }
  }
}
int main(int argc, char** argv) {
  int S, E;
  cin >> N >> M >> S >> E;
  S--;
  E--;
  for (int i = 0; i < M; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    a--;
    b--;
    adj1[a].push_back(pair<long long, int>(b, d));
    adj1[b].push_back(pair<long long, int>(a, d));
  }
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> e[i];
  }
  for (int i = 0; i < N; i++) {
    dijkstra(i);
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (dist[j] <= s[i]) {
        adj2[i].push_back(pair<long long, int>(j, e[i]));
      }
    }
  }
  for (int i = 0; i < N; i++) {
    adj1[i] = adj2[i];
  }
  dijkstra(S);
  if (dist[E] == INF)
    cout << -1 << endl;
  else
    cout << dist[E] << endl;
  return 0;
}
