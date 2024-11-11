#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, K;
vector<int> G[maxn];
bool isfort[maxn];
int out[maxn];
int deadseq[maxn];
bool dead[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= K; i++) {
    int x;
    scanf("%d", &x);
    isfort[x] = true;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  set<pair<double, int> > heap;
  for (int i = 1; i <= n; i++) {
    if (!isfort[i]) {
      for (int v : G[i]) {
        if (!isfort[v]) {
          out[i]++;
        }
      }
      heap.insert(make_pair((double)out[i] / G[i].size(), i));
    }
  }
  double mx = -1;
  int opt = -1;
  int sz = heap.size();
  for (int i = 1; i <= sz; i++) {
    pair<double, int> tmp = *heap.begin();
    heap.erase(heap.begin());
    if (mx < tmp.first) {
      mx = tmp.first;
      opt = i;
    }
    int u = tmp.second;
    dead[u] = true;
    deadseq[i] = u;
    for (int v : G[u]) {
      if (!isfort[v] && !dead[v]) {
        heap.erase(make_pair((double)out[v] / G[v].size(), v));
        heap.insert(make_pair((double)(--out[v]) / G[v].size(), v));
      }
    }
  }
  printf("%d\n", sz - opt + 1);
  for (int i = 1; i <= sz - opt + 1; i++) {
    printf("%d ", deadseq[sz - i + 1]);
  }
  puts("");
  return 0;
}
