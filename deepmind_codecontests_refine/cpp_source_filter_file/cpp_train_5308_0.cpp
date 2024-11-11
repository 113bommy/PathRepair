#include <bits/stdc++.h>

using namespace std;


const int INF = 1 << 30;

typedef vector< int > vi;

vi operator+(const vi &t, const vi &s)
{
  vi ret(52);
  for(int i = 0; i < 52; i++) ret[i] = t[i] + s[i];
  return (ret);
}

vi operator-(const vi &t)
{
  vi ret(52);
  for(int i = 0; i < 52; i++) ret[i] = t[i] * -1;
  return (ret);
}

vi operator*(const vi &t, int k)
{
  vi ret(52);
  for(int i = 0; i < 52; i++) ret[i] = t[i] * k;
  return (ret);
}

struct Primal_Dual
{
  typedef pair< vi, int > Pi;

  struct edge
  {
    int to, cap;
    vi cost;
    int rev;
  };

  vector< vector< edge > > graph;
  vector< vi > potential, min_cost;
  vector< int > prevv, preve;

  Primal_Dual(int V) : graph(V) {}

  void add_edge(int from, int to, int cap, vi cost)
  {
    graph[from].push_back((edge) {to, cap, cost, (int) graph[to].size()});
    graph[to].push_back((edge) {from, 0, -cost, (int) graph[from].size() - 1});
  }

  vi min_cost_flow(int s, int t, int f)
  {
    int V = graph.size();
    vi ret(52, 0);
    priority_queue< Pi, vector< Pi >, greater< Pi > > que;
    potential.assign(V, vi(52, 0));
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while(f > 0) {
      min_cost.assign(V, vi(52, INF));
      que.push(Pi(vi(52, 0), s));
      min_cost[s] = vi(52, 0);

      while(!que.empty()) {
        Pi p = que.top();
        que.pop();
        if(min_cost[p.second] < p.first) continue;
        for(int i = 0; i < graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          vi nextCost = min_cost[p.second] + e.cost + potential[p.second] + -potential[e.to];
          if(e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.push(Pi(min_cost[e.to], e.to));
          }
        }
      }
      if(min_cost[t][0] == INF) return (vi(52, -1));
      for(int v = 0; v < V; v++) potential[v] = potential[v] + min_cost[v];
      int addflow = f;
      for(int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret = ret + potential[t] * addflow;
      for(int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }
};

const string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int main()
{
  int N;
  string S[50];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  Primal_Dual flow(N + N + 2);
  const int s = N + N, t = N + N + 1;
  vi vc(52, 0);
  for(int i = 0; i < N; i++) flow.add_edge(s, i, 1, vc);
  for(int i = 0; i < N; i++) flow.add_edge(i + N, t, 1, vc);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      vc[temp.find(S[i][j])]--;
      flow.add_edge(i, j + N, 1, vc);
      vc[temp.find(S[i][j])]++;
    }
  }

  auto cost = flow.min_cost_flow(s, t, N);
  for(int i = 0; i < 52; i++) cout << string(-cost[i], temp[i]);
  cout << endl;