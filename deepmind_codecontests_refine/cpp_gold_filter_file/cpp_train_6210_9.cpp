#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100500, INF = 1e9;
typedef int node;
const int neutro = 0;
struct RMQ {
  int sz;
  node t[4 * 100500];
  node &operator[](int p) { return t[sz + p]; }
  void init(int n) {
    sz = 1 << (32 - __builtin_clz(n));
    for (int i = (0); i < (int)(2 * sz); i++) t[i] = neutro;
  }
  void updall() {
    for (int i = ((int)sz) - 1; i >= 0; i--) {
      t[i] = max(t[2 * i], t[2 * i + 1]);
    }
  }
  node get(int i, int j) { return get(i, j, 1, 0, sz); }
  node get(int i, int j, int n, int a, int b) {
    if (j <= a || i >= b) return neutro;
    if (i <= a && b <= j) return t[n];
    int c = (a + b) / 2;
    return max(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
  }
  void set(int p, node val) {
    for (p += sz; p > 0 && t[p] != val;) {
      t[p] = val;
      p /= 2;
      val = max(t[p * 2], t[p * 2 + 1]);
    }
  }
} sol;
int n;
int N, a[100500];
vector<int> RT;
void lis() {
  RT.resize(N);
  for (int i = (0); i < (int)(N); i++) RT[i] = 0;
  sol.init(n);
  for (int i = (0); i < (int)(n); i++) sol[i] = 0;
  sol.updall();
  for (int i = (0); i < (int)(N); i++) {
    int p = a[i];
    RT[i] = sol.get(0, p + 1) + 1;
    sol.set(p, max(sol[p], RT[i]));
  }
  for (int i = (1); i < (int)(N); i++) RT[i] = max(RT[i], RT[i - 1]);
}
int m;
int L[100500], R[100500];
vector<int> Res1, Res2;
int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = (0); i < (int)(m); i++) L[i] = 0;
    for (int i = (0); i < (int)(n); i++) {
      int l, r;
      scanf("%d %d", &l, &r);
      l--;
      L[l]++;
      L[r]--;
    }
    for (int i = (1); i < (int)(m); i++) L[i] += L[i - 1];
    for (int i = (0); i < (int)(m); i++) R[i] = L[m - 1 - i];
    N = m;
    for (int i = (0); i < (int)(m); i++) a[i] = L[i];
    lis();
    Res1 = RT;
    for (int i = (0); i < (int)(m); i++) a[i] = R[i];
    lis();
    Res2 = RT;
    int ans = max(Res1[m - 1], Res2[m - 1]);
    for (int i = (0); i < (int)(m - 1); i++) {
      ans = max(ans, Res1[i] + Res2[m - 2 - i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
