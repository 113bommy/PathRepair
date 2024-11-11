#include <bits/stdc++.h>
using namespace std;
const int maxN = 200042, maxTS = 1 << 19, INF = 1 << 23;
struct Tree {
  int offset;
  int sm[maxTS], mx[maxTS], mn[maxTS], d1[maxTS], d2[maxTS], d3[maxTS];
  void setLeaf(int v, int d) {
    sm[v] = mx[v] = mn[v] = d;
    d1[v] = d2[v] = d3[v] = -INF;
  }
  void updt(int v) {
    int a = v * 2, b = v * 2 + 1;
    sm[v] = sm[a] + sm[b];
    mx[v] = max(mx[a], sm[a] + mx[b]);
    mn[v] = min(mn[a], sm[a] + mn[b]);
    d1[v] = max({d1[a], -sm[a] + d1[b], mx[a] - 2 * (sm[a] + mn[b])});
    d2[v] = max({d2[a], -sm[a] + d2[b], sm[a] + mx[b] - 2 * mn[a]});
    d3[v] = max({d3[a], d3[b], d1[a] + sm[a] + mx[b], mx[a] - sm[a] + d2[b]});
  }
  void init(int n, char* t) {
    for (offset = 1; offset < n; offset *= 2)
      ;
    for (int i = (0); i < (n); i++) setLeaf(offset + i, t[i] == '(' ? 1 : -1);
    for (int i = (offset + n); i < (offset * 2); i++)
      mn[i] = INF, mx[i] = d1[i] = d2[i] = d3[i] = -INF;
    for (int i = offset - 1; i > 0; i--) updt(i);
  }
  void change(int v) {
    v += offset;
    setLeaf(v, -sm[v]);
    for (v /= 2; v != 0; v /= 2) updt(v);
  }
  int query() { return max(d1[1], d3[1]); }
} tree;
char in[maxN];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  scanf("%s", in);
  n = (n - 1) * 2;
  tree.init(n, in);
  printf("%d\n", tree.query());
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    tree.change(a - 1);
    tree.change(b - 1);
    printf("%d\n", tree.query());
  }
  return 0;
}
