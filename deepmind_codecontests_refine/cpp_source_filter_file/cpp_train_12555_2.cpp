#include <bits/stdc++.h>
using namespace std;
deque<int> D[5000], adj[5000], A(5000);
int dir[5000];
int C[5000][5000];
int ft[5000];
bool compare(int i, int j) { return A[i] < A[j]; }
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    D[i].push_back(i);
  }
  for (int i = 0, u, v, w; i < N - 1; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    C[u][v] = C[v][u] = w;
  }
  bool fg[5000] = {0};
  queue<int> q, seq;
  q.push(0);
  fg[0] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0, d = (int)adj[v].size(); i < d; i++) {
      if (fg[adj[v][i]]) continue;
      dir[adj[v][i]] = v;
      fg[adj[v][i]] = 1;
      q.push(adj[v][i]);
      seq.push(adj[v][i]);
    }
  }
  int Remain = N;
  int day = 1;
  do {
    for (int i = 1; i < N; i++) {
      int v = seq.front();
      seq.pop();
      seq.push(v);
      sort(D[v].begin(), D[v].end(), compare);
      int u = dir[v];
      for (int i = 0, ss = D[v].size(); i < C[v][u] && i < ss; i++) {
        D[u].push_back(D[v][i]);
        D[v].pop_front();
      }
    }
    for (int i = 0; i < D[0].size(); i++) {
      ft[D[0][i]] = day;
      Remain--;
    }
    D[0].clear();
    day++;
  } while (Remain != 0);
  cout << "0";
  for (int i = 1; i < N; i++) cout << " " << ft[i];
  cout << endl;
}
