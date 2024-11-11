#include <bits/stdc++.h>

using namespace std;

struct edge
{
  int to, cost;
};

typedef pair< int, int > Pi;
const int INF = 1LL << 30;

int N, M, P;
int v1[100], v2[100];
double dp1[100], dp2[100];
vector< vector< edge > > g;

void Dijkstra(int s, int *v, double *dp)
{
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  fill_n(v, N, INF);
  fill_n(dp, N, 0);

  que.emplace(0, s);
  v[s] = 0;
  dp[s] = 1;

  while(!que.empty()) {
    auto p = que.top();
    que.pop();
    if(p.first > v[p.second]) continue;
    for(auto &e : g[p.second]) {
      if(p.first + e.cost < v[e.to]) {
        v[e.to] = p.first + e.cost;
        dp[e.to] = dp[p.second];
        que.emplace(v[e.to], e.to);
      } else if(p.first + e.cost == v[e.to]) {
        dp[e.to] += dp[p.second];
      }
    }
  }
}

int main()
{
  cout << fixed << setprecision(10);

  while(cin >> N >> M >> P, N) {
    g.resize(N);

    while(M--) {
      int X, Y, Z;
      cin >> X >> Y >> Z;
      g[X].emplace_back((edge) {Y, Z});
      g[Y].emplace_back((edge) {X, Z});
    }
    Dijkstra(0, v1, dp1);
    Dijkstra(N - 1, v2, dp2);

    while(P--) {
      int A;
      cin >> A;
      if(v1[A] + v2[A] == v1[N - 1])
        cout << (double) dp1[A] * dp2[A] / dp1[N - 1] << endl;
      else
        cout << 0 << endl;
    }
    cout << endl;

    g.clear();
  }
}