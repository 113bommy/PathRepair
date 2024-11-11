#include <bits/stdc++.h>
using namespace std;
typedef struct node1 {
  int x;
  int y;
  long long int cap;
  long long int flow;
} edge;
vector<edge> e;
vector<int> Adj[210];
vector<int> Adj1[201];
vector<int> g1[210];
int isprime[100001];
int curr[210];
int a[210];
int d[210];
bool visited[210];
int source;
int sink;
int id = 0;
stack<int> s1;
void DFS1(int u, int p) {
  visited[u] = true;
  s1.push(u);
  for (vector<int>::iterator it = Adj1[u].begin(); it != Adj1[u].end(); it++) {
    if (!visited[(*it)] && (*it) != p) {
      DFS1((*it), u);
    } else if (visited[(*it)] && (*it) != p) {
      while (!s1.empty()) {
        g1[id].push_back(s1.top());
        s1.pop();
      }
    }
  }
  return;
}
void AddEdge(int source, int sink, long long int cap) {
  edge e1 = {source, sink, cap, 0LL};
  edge e2 = {sink, source, 0LL, 0LL};
  Adj[source].push_back(e.size());
  e.push_back(e1);
  Adj[sink].push_back(e.size());
  e.push_back(e2);
}
int BFS(int source, int sink, int n) {
  queue<int> Q1;
  for (int i = 0; i <= (n + 1); i++) {
    d[i] = -1;
  }
  Q1.push(source);
  d[source] = 0;
  while (!Q1.empty() && d[sink] < 0) {
    int x = Q1.front();
    Q1.pop();
    for (vector<int>::iterator it = Adj[x].begin(); it != Adj[x].end(); it++) {
      int id = (*it);
      int y = e[id].y;
      if (d[y] < 0 && e[id].flow < e[id].cap) {
        Q1.push(y);
        d[y] = d[x] + 1;
      }
    }
  }
  if (d[sink] != -1) {
    return 1;
  } else {
    return 0;
  }
}
long long int DFS(int x, long long int flow) {
  if (!flow) {
    return 0LL;
  }
  if (x == sink) {
    return flow;
  }
  for (; curr[x] < (int)Adj[x].size(); curr[x]++) {
    int id = Adj[x][curr[x]];
    int y = e[id].y;
    if (d[y] != (d[x] + 1)) {
      continue;
    }
    long long int pushed = DFS(y, min(flow, e[id].cap - e[id].flow));
    if (pushed) {
      e[id].flow = e[id].flow + pushed;
      e[id ^ 1].flow = e[id ^ 1].flow - pushed;
      return pushed;
    }
  }
  return 0LL;
}
long long int max_flow(int source, int sink, int n) {
  long long int flow = 0;
  long long int pushed;
  while (BFS(source, sink, n)) {
    for (int i = 0; i <= (n + 1); i++) {
      curr[i] = 0;
    }
    while (pushed = DFS(source, INT_MAX)) {
      flow = flow + pushed;
    }
  }
  return flow;
}
void seive() {
  for (int i = 2; i <= 100000; i++) {
    isprime[i] = true;
  }
  for (int i = 2; i <= 100000; i++) {
    if (isprime[i]) {
      for (int j = (i + i); j <= 100000; j = j + i) {
        isprime[j] = false;
      }
    }
  }
}
int main() {
  seive();
  int n;
  scanf("%d", &n);
  long long int count_e = 0;
  long long int count_o = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) {
      count_e++;
    } else {
      count_o++;
    }
  }
  source = 0;
  sink = 201;
  for (int i = 1; i <= n; i++) {
    for (int j = (i + 1); j <= n; j++) {
      if (isprime[a[i] + a[j]]) {
        if (a[i] % 2 == 1 && a[j] % 2 == 0) {
          AddEdge(i, j, 1);
        } else if (a[i] % 2 == 0 && a[j] % 2 == 1) {
          AddEdge(j, i, 1);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] % 2 == 0) {
      AddEdge(i, sink, 2);
    } else {
      AddEdge(source, i, 2);
    }
  }
  long long int flow = max_flow(source, sink, 203);
  bool poss = true;
  if (flow != 2 * count_e) {
    poss = false;
  }
  if (poss) {
    for (vector<edge>::iterator it = e.begin(); it != e.end(); it++) {
      edge t1 = (*it);
      if (t1.x != source && t1.x != sink && t1.y != source && t1.y != sink) {
        if (a[t1.x] % 2 == 1 && t1.flow == t1.cap) {
          Adj1[t1.x].push_back(t1.y);
          Adj1[t1.y].push_back(t1.x);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        DFS1(i, i);
        while (!s1.empty()) {
          s1.pop();
        }
        id++;
      }
    }
    printf("%d \n", id);
    for (int i = 0; i < id; i++) {
      printf("%d ", g1[i].size());
      for (vector<int>::iterator it = g1[i].begin(); it != g1[i].end(); it++) {
        printf("%d ", (*it));
      }
      printf("\n");
    }
  } else {
    printf("Impossible\n");
  }
  return 0;
}
