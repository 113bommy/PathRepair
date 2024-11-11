#include <bits/stdc++.h>
using namespace std;
vector<int> even, odd, graph[202], asw[202];
bool nprimes[2 * 10000 + 2], intree[202];
int rgraph[202][202], pai[202], thi[202];
int current;
void build_primes() {
  for (int i = 2; i * i <= 2 * 10000 + 2; i++)
    if (!nprimes[i])
      for (int j = i * i; j <= 2 * 10000 + 2; j += i) nprimes[j] = true;
}
bool bfs(int s, int t) {
  for (int i = 0; i < 202; i++) {
    pai[i] = -1;
    intree[i] = false;
  }
  pai[s] = pai[t] = -1;
  intree[s] = intree[t] = false;
  queue<int> q;
  q.push(s);
  intree[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < graph[v].size(); i++) {
      int w = graph[v][i];
      if (rgraph[v][w] > 0 && !intree[w]) {
        pai[w] = v;
        intree[w] = true;
        q.push(w);
      }
    }
  }
  return pai[t] != -1;
}
int edmondsKarp(int s, int t) {
  int mflow = 0;
  while (bfs(s, t)) {
    int maxPath = 1e9;
    for (int v = t; v != s; v = pai[v])
      maxPath = min(rgraph[pai[v]][v], maxPath);
    for (int v = t; v != s; v = pai[v]) {
      rgraph[pai[v]][v] -= maxPath;
      rgraph[v][pai[v]] += maxPath;
    }
    mflow += maxPath;
  }
  return mflow;
}
void dfs(int v, int parent) {
  if (intree[v]) return;
  intree[v] = true;
  asw[current].push_back(v);
  for (int i = 0; i < graph[v].size(); i++) {
    int w = graph[v][i];
    if (w != parent)
      if (thi[v] % 2 && rgraph[v][w] == 0)
        dfs(w, v);
      else if (thi[v] % 2 == 0 && rgraph[v][w] == 1)
        dfs(w, v);
  }
}
int main() {
  int n, s = 0, t = thi[201] = 201;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    thi[i + 1] = x;
    if (x % 2)
      odd.push_back(i + 1);
    else
      even.push_back(i + 1);
  }
  build_primes();
  for (int i = 0; i < odd.size(); i++) {
    graph[s].push_back(odd[i]);
    graph[odd[i]].push_back(s);
    rgraph[s][odd[i]] = 2;
  }
  for (int i = 0; i < even.size(); i++) {
    graph[even[i]].push_back(t);
    graph[t].push_back(even[i]);
    rgraph[even[i]][t] = 2;
  }
  for (int i = 0; i < odd.size(); i++)
    for (int j = 0; j < even.size(); j++)
      if (!nprimes[thi[odd[i]] + thi[even[j]]]) {
        graph[odd[i]].push_back(even[j]);
        graph[even[j]].push_back(odd[i]);
        rgraph[odd[i]][even[j]] = 1;
      }
  int mflow = edmondsKarp(s, t);
  if (mflow != n) {
    printf("Impossible");
    return 0;
  }
  for (int i = 0; i < 202; i++) intree[i] = false;
  current = 0;
  for (int i = 0; i < odd.size(); i++) {
    int v = odd[i];
    if (!intree[v]) {
      dfs(v, v);
      current++;
    }
  }
  printf("%d\n", current);
  for (int i = 0; i < current; i++) {
    printf("%d ", (int)asw[i].size());
    for (int j = 0; j < asw[i].size(); j++) printf("%d ", asw[i][j]);
    printf("\n");
  }
  return 0;
}
