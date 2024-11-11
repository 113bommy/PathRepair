#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int M = 200000;
int n, Q, delta;
multiset<int> Ans;
set<int> tree;
int f[N], P[N], H[N], id[N];
int g[M * 5], g2[M * 5];
int dfs(int *g, int x, int sl, int sr, int pos) {
  if (pos <= sl) return g[x];
  int sm = (sl + sr) / 2;
  if (pos <= sm) return max(dfs(g, x * 2, sl, sm, pos), g[2 * x + 1]);
  return dfs(g, x * 2 + 1, sm + 1, sr, pos);
}
void mod(int *g, int x, int sl, int sr, int pos, int val) {
  if (sl == sr) {
    g[x] = val;
    return;
  }
  int sm = (sl + sr) / 2;
  if (pos <= sm)
    mod(g, x * 2, sl, sm, pos, val);
  else
    mod(g, x * 2 + 1, sm + 1, sr, pos, val);
  g[x] = max(g[x * 2], g[x * 2 + 1]);
}
void del1(int p) { mod(g, 1, 1, M + 10, H[p] + M, 0); }
void ins1(int p) { mod(g, 1, 1, M + 10, H[p] + M, f[p]); }
void ins2(int p) { mod(g2, 1, 1, n, p, f[p]); }
void del2(int p) { mod(g2, 1, 1, n, p, 0); }
int main() {
  cin >> n >> Q;
  delta = 0;
  memset(g, 0, sizeof g);
  memset(g2, 0, sizeof g2);
  for (int q = (1); q <= (Q); q++) {
    int op;
    scanf("%d", &op);
    delta++;
    if (q - 10 > 0 && P[q - 10] != -1) {
      int p = P[q - 10];
      ins2(p);
    }
    if (op == 1) {
      int p, h;
      scanf("%d%d", &p, &h);
      P[q] = p;
      id[p] = q;
      tree.insert(p);
      H[p] = h - delta;
      f[p] = 1;
      for (int q0 = (q - 11); q0 <= (q - 1); q0++)
        if (q0 > 0 && P[q0] != -1) {
          int p0 = P[q0];
          if (p < p0 && H[p] < H[p0]) f[p] = max(f[p], f[p0] + 1);
        }
      f[p] = max(f[p], dfs(g2, 1, 1, n, p) + 1);
      ins1(p);
      vector<int> K;
      for (int q0 = (q); q0 >= (q - 11); q0--)
        if (q0 > 0 && P[q0] != -1) K.push_back(P[q0]);
      sort((K).begin(), (K).end(), greater<int>());
      for (auto p0 : K) {
        del1(p0);
        if (id[p0] <= q - 10) del2(p0);
        for (auto p1 : K)
          if (p0 < p1 && H[p0] < H[p1]) f[p0] = max(f[p0], f[p1] + 1);
        ins1(p0);
        if (id[p0] <= q - 10) ins2(p0);
      }
    } else {
      int x;
      scanf("%d", &x);
      P[q] = -1;
      auto it = tree.begin();
      static int List[20];
      for (int i = (1); i <= (x - 1); i++) {
        List[i] = *it;
        it++;
      }
      int p = *it;
      P[id[p]] = -1;
      tree.erase(it);
      del1(p);
      if (id[p] <= q - 10) del2(p);
      for (int i = (1); i <= (x - 1); i++) {
        del1(List[i]);
        if (id[List[i]] <= q - 10) del2(List[i]);
      }
      for (int i = (x - 1); i >= (1); i--) {
        int p = List[i];
        f[p] = dfs(g, 1, 1, M + 10, H[p] + M) + 1;
        ins1(p);
        if (id[p] <= q - 10) ins2(p);
      }
    }
    cout << g[1] << endl;
  }
  return 0;
}
