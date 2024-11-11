#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
typedef struct {
  int a, b, c;
} iii;
void mosA(vector<int> a) {
  for (int i = 0; i < a.size(); i++) printf("%d ", a[i]);
  printf("\n");
}
void mosP(vector<pair<int, int> > a) {
  for (int i = 0; i < a.size(); i++) printf("%d %d\n", a[i].first, a[i].second);
  printf("\n");
}
long long min_especial(long long a, long long b) {
  if (a != -1 && b != -1)
    return min(a, b);
  else
    return max(a, b);
}
bool ord(int a, int b) { return b < a; }
long long ans, k;
int q, n, m, t, a, b, c, u, f, l, x, z, y, s, d, h, r;
template <class T, int SZ>
struct Fenwick {
  T tree[SZ];
  int tam = 0;
  void adjust(int p, T v) {
    for (int i = p; i < tam; i += (i & -i)) tree[i] += v;
  }
  void limpiar() { memset(tree, 0, sizeof(T) * tam); }
  T sum(int p) {
    T s = 0;
    for (int i = p; i; i -= (i & -i)) s += tree[i];
    return s;
  }
};
struct Fenwick<int, 100005> F;
int R[100005];
vector<iii> V[100005];
map<int, int> M;
bool B[100005];
int main() {
  scanf("%d", &n);
  int pos = 0;
  int indiceNuevo = 1;
  for (int i = 0; i < (n); i++) {
    scanf("%d%d%d", &a, &b, &c);
    int m = M[c];
    if (!m) m = M[c] = indiceNuevo++;
    if (a == 3) {
      V[m].push_back({a, b, pos++});
      B[m] = true;
    } else
      V[m].push_back({a, b, c});
  }
  indiceNuevo--;
  for (int i = 1; i <= indiceNuevo; i++) {
    if (B[i]) {
      vector<int> v;
      map<int, int> mapa;
      for (iii x : V[i]) v.push_back(x.b);
      sort(v.begin(), v.end());
      int ind = 1;
      for (int k = 0; k < v.size(); k++) {
        if (k == v.size() || v[k] != v[k + 1]) mapa[v[k]] = ind++;
      }
      for (iii& x : V[i]) x.b = mapa[x.b];
    }
  }
  for (int i = 1; i <= indiceNuevo; i++) {
    if (B[i]) {
      F.limpiar();
      F.tam = V[i].size();
      for (iii x : V[i]) {
        if (x.a == 1) {
          F.adjust(x.b, 1);
          continue;
        }
        if (x.a == 2) {
          F.adjust(x.b, -1);
          continue;
        }
        R[x.c] = F.sum(x.b);
      }
    }
  }
  for (int i = 0; i < (pos); i++) {
    printf("%d\n", R[i]);
  }
  return 0;
}
