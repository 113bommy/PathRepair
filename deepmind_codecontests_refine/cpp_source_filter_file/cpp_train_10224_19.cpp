#include <bits/stdc++.h>
using namespace std;
int const N = 200000;
int fn[N + 1], x[N + 1], n, m, an[N];
pair<int, int> y[N + 1];
void ad(int i) {
  while (i <= n) ++fn[i], i += i & -i;
}
int gt(int x) {
  int an = 0;
  for (int i = 17; i >= 0; --i)
    if (an | 1 << i <= n && fn[an | 1 << i] < x) {
      an |= 1 << i;
      x -= fn[an];
    }
  return an + 1;
}
struct Q {
  int k, j, id;
  void sc(int i) {
    scanf("%d%d", &k, &j);
    id = i;
  }
  bool operator<(Q const &o) const { return k < o.k; }
} qu[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (int)(n + 1); ++i) {
    scanf("%d", x + i);
    y[i] = make_pair(-x[i], i);
  }
  sort(y + 1, y + n + 1);
  scanf("%d", &m);
  for (int i = 0; i < (int)(m); ++i) qu[i].sc(i);
  sort(qu, qu + m);
  int k = 0;
  for (int i = 0; i < (int)(m); ++i) {
    while (k < qu[i].k) {
      ++k;
      ad(y[k].second);
    }
    an[qu[i].id] = x[gt(qu[i].j)];
  }
  for (int i = 0; i < (int)(m); ++i) printf("%d\n", an[i]);
}
