#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x = Sub(x - y); }
inline int Mul(int x, int y) { return (int)((unsigned long long)x * y % mod); }
inline int Mul(int x, int y, int z) {
  return (int)((unsigned long long)x * y % mod * z % mod);
}
int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}
int Inv(int x) { return Pow(x, mod - 2); }
template <class T>
inline void Max(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void Min(T &x, T y) {
  if (y < x) x = y;
}
void Reverse(vector<int> &v) { reverse(v.begin(), v.end()); }
void Concat(vector<int> &a, vector<int> &b) {
  copy(b.begin(), b.end(), inserter(a, a.end()));
}
const int maxn = 1e6;
int n, S, T, A, B;
vector<int> g[maxn];
int label[maxn], origin[maxn], target[maxn];
int par[maxn], dep[maxn];
int id[maxn], ord[maxn];
int spos[maxn], tpos[maxn];
void Die(void) {
  puts("-1");
  exit(0);
}
void DfsI(int u) {
  for (int v : g[u]) {
    if (v == par[u]) continue;
    dep[v] = dep[u] + 1;
    par[v] = u;
    DfsI(v);
  }
}
void InitTree(int r) {
  par[r] = -1;
  dep[r] = 0;
  DfsI(r);
}
vector<int> GetPath(int s, int t) {
  vector<int> L1, L2;
  while (dep[s] > dep[t]) {
    L1.push_back(s);
    s = par[s];
  }
  while (dep[t] > dep[s]) {
    L2.push_back(t);
    t = par[t];
  }
  while (s != t) {
    L1.push_back(s);
    s = par[s];
    L2.push_back(t);
    t = par[t];
  }
  L1.push_back(s);
  Reverse(L2);
  Concat(L1, L2);
  return L1;
}
int Dist(int s, int t) { return (int)GetPath(s, t).size() - 1; }
void DfsF(int u, vector<int> &L) {
  L.push_back(u);
  int cnt = 0;
  for (int v : g[u]) {
    if (v == par[u] || label[v] == target[v]) continue;
    if (++cnt == 1) {
      DfsF(v, L);
    } else {
      Die();
    }
  }
}
void FindOrDie(int u) {
  vector<int> line1, line2;
  int cnt = 0;
  for (int v : g[u]) {
    if (v == par[u] || label[v] == target[v]) continue;
    switch (++cnt) {
      case 1:
        DfsF(v, line1);
        break;
      case 2:
        DfsF(v, line2);
        break;
      default:
        Die();
    }
  }
  A = line1.back();
  B = cnt == 2 ? line2.back() : u;
  int tot1 = (int)(line1.size() + line2.size());
  int tot2 = 0;
  for (int i = 0; i < n; ++i) {
    if (label[i] != target[i]) ++tot2;
  }
  if (tot1 != tot2) Die();
}
long long Solve(int low) {
  vector<int> path = GetPath(A, B);
  int clk = 0;
  for (int x : path) {
    if (x != low) {
      id[x] = clk;
      ord[clk++] = x;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (label[i] != -1) {
      spos[label[i]] = i;
    }
    if (target[i] != -1) {
      tpos[target[i]] = i;
    }
  }
  int c = id[tpos[label[path[0]]]];
  for (int i = 0; i < path.size(); ++i) {
    int u = path[i];
    if (u == low) continue;
    int p = label[u];
    if ((id[tpos[p]] - id[spos[p]] + clk) % clk != c) {
      Die();
    }
  }
  return Dist(S, A) + (long long)(c - 1) * (clk + 1) + 1 + Dist(B, T);
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", label + i);
    if (--label[i] == -1) {
      S = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", target + i);
    if (--target[i] == -1) {
      T = i;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  InitTree(T);
  memcpy((origin), (label), sizeof(label));
  vector<int> path = GetPath(S, T);
  for (int i = 0; i < (int)path.size() - 1; ++i) {
    swap(label[path[i]], label[path[i + 1]]);
  }
  int low = -1;
  for (int i = 0; i < n; ++i) {
    if (label[i] != target[i] && (low == -1 || dep[i] < dep[low])) {
      low = i;
    }
  }
  if (low == -1) {
    int dist = (int)path.size() - 1;
    printf("0 %d\n", dist);
    return 0;
  }
  low = par[low];
  FindOrDie(low);
  long long ans = Solve(low);
  swap(A, B);
  Min(ans, Solve(low));
  if (A > B) swap(A, B);
  printf("%d %d %lld\n", A + 1, B + 1, ans);
  return 0;
}
