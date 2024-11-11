#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 300005;
int N, M, Q;
int group[MAX_N];
int diam[MAX_N];
vector<int> edges[MAX_N];
int T;
int seen[MAX_N];
int far = -1;
int farVertex = -1;
int get(int a) {
  if (group[a] != a) {
    group[a] = get(group[a]);
  }
  return group[a];
}
void join(int a, int b) {
  int d1 = diam[get(a)];
  int d2 = diam[get(b)];
  if (d1 < d2) {
    swap(d1, d2);
  };
  int big = (d1 / 2) + (d1 % 2);
  int other = (d2 / 2) + (d2 % 2);
  int brand = max(d1, big + other + 1);
  diam[get(b)] = brand;
  group[get(a)] = get(b);
}
void dfs(int u, int d) {
  for (int i = 0; i < edges[u].size(); i++) {
    int v = edges[u][i];
    if (seen[v] != T) {
      seen[v] = T;
      dfs(v, d + 1);
    }
  }
  if (d > far) {
    far = d;
    farVertex = u;
  }
}
int main() {
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 0; i < N; i++) {
    group[i] = i;
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
    group[get(a)] = get(b);
  }
  for (int i = 0; i < N; i++) {
    if (seen[i] == 0) {
      T++;
      seen[i] = T;
      far = -1;
      farVertex = -1;
      dfs(i, 0);
      int f = farVertex;
      far = -1;
      farVertex = -1;
      T++;
      seen[f] = T;
      dfs(f, 0);
      diam[get(i)] = far;
    }
  }
  for (int i = 0; i < Q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a;
      scanf("%d", &a);
      printf("%d\n", diam[get(a - 1)]);
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      if (get(a) != get(b)) {
        join(a - 1, b - 1);
      }
    }
  }
  return 0;
}
