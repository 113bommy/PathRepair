#include <bits/stdc++.h>
using namespace std;
int type;
int N, Q, root = 1;
int dist[100010], lanac[100010], length[100010], A[100010], B[100010];
vector<int> v[100010];
vector<int> loga[100010];
void inc(int lan, int i, int val) {
  for (; i < loga[lan].size(); i += i & -i) {
    loga[lan][i] += val;
  }
}
int sum(int lan, int lo, int hi) {
  int ret = 0;
  for (; hi > 0; hi -= hi & -hi) ret += loga[lan][hi];
  for (--lo; lo > 0; lo -= lo & -lo) ret -= loga[lan][lo];
  return ret;
}
void dfs(int node, int lan, int d, int exNode) {
  dist[node] = d;
  lanac[node] = lan;
  length[lan] = max(length[lan], d);
  for (int i = 0; i < v[node].size(); ++i) {
    if (v[node][i] == exNode) continue;
    if (node == root) {
      dfs(v[node][i], i + 1, 1, node);
      continue;
    }
    dfs(v[node][i], lan, d + 1, node);
  }
}
int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
    if (v[a].size() > 2) root = a;
    if (v[b].size() > 2) root = b;
    A[i + 1] = a;
    B[i + 1] = b;
  }
  dfs(root, 0, 0, -1);
  for (int i = 0; i < v[root].size(); ++i) {
    for (int j = 0; j <= length[i + 1] + 5; ++j) loga[i + 1].push_back(0);
  }
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d", &type);
    if (type == 1) {
      int ind;
      scanf("%d", &ind);
      int a = A[ind], b = B[ind];
      if (dist[a] > dist[b]) swap(a, b);
      inc(lanac[b], dist[b], -1);
      continue;
    }
    if (type == 2) {
      int ind;
      scanf("%d", &ind);
      int a = A[ind], b = B[ind];
      if (dist[a] > dist[b]) swap(a, b);
      inc(lanac[b], dist[b], 1);
      continue;
    }
    if (type == 3) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (a == root) {
        if (sum(lanac[b], 1, dist[b]) == 0) {
          printf("%d\n", dist[b]);
        } else {
          printf("-1\n");
        }
        continue;
      }
      if (b == root) {
        if (sum(lanac[a], 1, dist[a]) == 0) {
          printf("%d\n", dist[a]);
        } else {
          printf("-1\n");
        }
        continue;
      }
      if (a != root && b != root) {
        if (lanac[a] == lanac[b]) {
          if (sum(lanac[a], dist[a] + 1, dist[b]) != 0)
            printf("-1\n");
          else
            printf("%d\n", abs(dist[a] - dist[b]));
        } else {
          if (sum(lanac[b], 1, dist[b]) != 0 ||
              sum(lanac[a], 1, dist[a]) != 0) {
            printf("-1\n");
            continue;
          }
          printf("%d\n", dist[a] + dist[b]);
        }
      }
    }
  }
  return 42 - 42;
}
