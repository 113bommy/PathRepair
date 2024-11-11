#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100500;
int n, A[MAXN];
vector<int> G[MAXN], W;
map<int, int> L;
int depth[MAXN];
void bfs(int je) {
  queue<int> Q;
  Q.push(0);
  while (Q.size()) {
    int p = Q.front();
    Q.pop();
    if (depth[p] % 2 == je)
      W.push_back(A[p]);
    else
      L[A[p]]++;
    for (int i = (0); i < (int)(G[p].size()); i++) {
      int s = G[p][i];
      depth[s] = depth[p] + 1;
      Q.push(s);
    }
  }
}
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = (0); i < (int)(MAXN); i++) G[i].clear();
    for (int i = (0); i < (int)(n); i++) scanf("%d", &A[i]);
    for (int i = (1); i < (int)(n); i++) {
      int p;
      scanf("%d", &p);
      p--;
      G[p].push_back(i);
    }
    W.clear();
    L.clear();
    int sz = 0, p = 0;
    while (G[p].size()) {
      p = G[p][0];
      sz++;
    }
    depth[0] = 0;
    bfs(sz % 2);
    long long ans = 0;
    int XOR = 0;
    for (int i = (0); i < (int)(W.size()); i++) XOR ^= W[i];
    for (int i = (0); i < (int)(W.size()); i++) {
      int b = XOR ^ W[i];
      ans += L[b];
    }
    if (!ans) {
      long long w = W.size(), l = n - w;
      ans += w * (w - 1) / 2;
      ans += l * (l - 1) / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
