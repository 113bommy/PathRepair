#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000;
struct UFT {
  int links[MAX_N], ranks[MAX_N], sizes[MAX_N];
  UFT() {}
  void init(int n) {
    for (int i = 0; i < n; i++) links[i] = i, ranks[i] = sizes[i] = 1;
  }
  int root(int i) {
    int i0 = i;
    while (links[i0] != i0) i0 = links[i0];
    return (links[i] = i0);
  }
  int rank(int i) { return ranks[root(i)]; }
  int size(int i) { return sizes[root(i)]; }
  bool same(int i, int j) { return root(i) == root(j); }
  int merge(int i0, int i1) {
    int r0 = root(i0), r1 = root(i1), mr;
    if (r0 == r1) return r0;
    if (ranks[r0] == ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      ranks[r0]++;
      mr = r0;
    } else if (ranks[r0] > ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      mr = r0;
    } else {
      links[r0] = r1;
      sizes[r1] += sizes[r0];
      mr = r1;
    }
    return mr;
  }
};
UFT uft;
bool ngs[MAX_N];
int main() {
  int n;
  scanf("%d", &n);
  uft.init(n);
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    uft.merge(u, v);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    if (uft.same(u, v)) ngs[uft.root(u)] = true;
  }
  int maxg = 0;
  for (int i = 0; i < m; i++)
    if (!ngs[i] && i == uft.root(i) && maxg < uft.size(i)) maxg = uft.size(i);
  printf("%d\n", maxg);
  return 0;
}
