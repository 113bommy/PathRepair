#include <bits/stdc++.h>
using namespace std;
const int N = 300100;
int n, q;
struct point {
  int x, idx;
  point(int _x = 0, int _idx = 0) {
    x = _x;
    idx = _idx;
  }
} M[N * 5];
int global;
struct interval {
  int a, b, idx;
  interval(int _a = 0, int _b = 0, int _idx = 0) {
    a = _a;
    b = _b;
    idx = _idx;
  }
} IN[N];
struct fenwick {
  int tree[1000005];
  int n;
  fenwick() {
    memset(tree, 0, sizeof(tree));
    n = 1000004;
  }
  inline void add(int x, int val) {
    for (; x < n; x += x & -x) tree[x] += val;
  }
  inline int get(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += tree[x];
    return ans;
  }
} F;
inline bool cmp1(const interval &A, const interval &B) { return A.b < B.b; }
inline bool cmp2(const point &A, const point &B) { return A.x < B.x; }
vector<int> V[N];
inline void load() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d %d", &IN[i].a, &IN[i].b);
  for (int i = 0; i < q; i++) {
    int k;
    scanf("%d", &k);
    V[i].push_back(0);
    M[global].x = 0;
    M[global++].idx = i;
    while (k--) {
      scanf("%d", &M[global].x);
      V[i].push_back(M[global].x);
      M[global++].idx = i;
    }
    V[i].push_back(1000001);
    M[global].x = 1000001;
    M[global++].idx = i;
  }
}
int GLOBAL[N];
int ANS[N];
inline void solve() {
  sort(IN, IN + n, cmp1);
  sort(M, M + global, cmp2);
  int index = 0;
  for (int i = 0; i < global; i++) {
    while (index < n && IN[index].b < M[i].x) {
      F.add(IN[index].a, 1);
      index++;
    }
    if (GLOBAL[M[i].idx] == 0)
      ANS[M[i].idx] += F.get(M[i].x), GLOBAL[M[i].idx]++;
    else {
      int tocka = V[M[i].idx][GLOBAL[M[i].idx] - 1];
      int how_much = F.get(M[i].x - 1) - F.get(tocka);
      ANS[M[i].idx] += how_much;
      GLOBAL[M[i].idx]++;
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", n - ANS[i]);
}
int main(void) {
  load();
  solve();
  return 0;
}
