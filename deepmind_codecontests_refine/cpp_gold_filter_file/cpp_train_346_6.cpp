#include <bits/stdc++.h>
using namespace std;
long long int a[7][11] = {{0},
                          {0},
                          {0, 1, 2},
                          {0, 1, 2, 3, 2},
                          {0, 1, 2, 3, 4, 3, 2},
                          {0, 1, 2, 3, 4, 5, 4, 3, 2},
                          {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2}};
long long int MOD[300000][20];
class segment_tree {
 public:
  long long int z;

 private:
  class segment {
   public:
    long long int size, sum[11];
    segment() {
      size = 0;
      memset(sum, 0, sizeof sum);
    }
  };
  inline segment merge(segment a, segment b) {
    segment t;
    t.size = a.size + b.size;
    for (long long int i = 1; i <= 2 * (z - 1); i++)
      t.sum[i] = a.sum[i] + b.sum[MOD[i - 1 + a.size][2 * (z - 1)] + 1];
    return t;
  }

 public:
  segment kd[262145];
  inline void update(long long int root, long long int bas, long long int son,
                     long long int x, long long int val) {
    if (x < bas or son < x) return;
    if (bas == son) {
      kd[root].size = 1;
      for (long long int i = 1; i <= 2 * (z - 1); i++)
        kd[root].sum[i] = val * a[z][i];
      return;
    }
    update(root * 2, bas, (bas + son) / 2, x, val);
    update(root * 2 + 1, (bas + son) / 2 + 1, son, x, val);
    kd[root] = merge(kd[root * 2], kd[root * 2 + 1]);
  }
  inline segment query(long long int root, long long int bas, long long int son,
                       long long int x, long long int y) {
    if (y < bas or son < x) return segment();
    if (x <= bas and son <= y) return kd[root];
    return merge(query(root * 2, bas, (bas + son) / 2, x, y),
                 query(root * 2 + 1, (bas + son) / 2 + 1, son, x, y));
  }
} ST[7];
long long int n, m;
int main() {
  for (long long int i = 0; i <= 290000; i++)
    for (long long int j = 1; j <= 18; j++) MOD[i][j] = i % j;
  for (long long int c = 2; c <= 6; c++) ST[c].z = c;
  cin >> n;
  long long int t, x, y, c;
  for (long long int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    for (long long int c = 2; c <= 6; c++) ST[c].update(1, 1, n, i, x);
  }
  cin >> m;
  while (m--) {
    scanf("%lld", &t);
    if (t == 1) {
      scanf("%lld %lld", &x, &c);
      for (long long int cc = 2; cc <= 6; cc++) ST[cc].update(1, 1, n, x, c);
    } else {
      scanf("%lld %lld %lld", &x, &y, &c);
      printf("%lld\n", ST[c].query(1, 1, n, x, y).sum[1]);
    }
  }
}
