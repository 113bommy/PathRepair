#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int nn[maxn], ss[maxn];
struct node {
  int x, y;
};
node w[maxn];
int mm[maxn];
bool comp(node a, node b) { return a.x < b.x; }
int main() {
  int n, a;
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    ss[i] = a;
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &nn[i]);
    mm[nn[i]] = i;
  }
  k = 0;
  int sum = 0;
  for (i = 1; i <= n; i++) {
    if (ss[i] == nn[i]) continue;
    int id = 0;
    for (j = i + 1; j <= n; j++) {
      if (ss[j] == nn[i]) {
        id = j;
        break;
      }
    }
    while (id != i) {
      for (j = i; j < id; j++) {
        int t;
        if (mm[ss[j]] >= id) {
          t = j;
          j = id;
          id = t;
          t = ss[j];
          ss[j] = ss[id];
          ss[id] = t;
          w[k].x = id;
          w[k++].y = j;
          sum += abs(j - id);
          break;
        }
      }
    }
  }
  printf("%d\n%d\n", sum, k);
  for (i = 0; i < k; i++) {
    printf("%d %d\n", w[i].y, w[i].x);
  }
  return 0;
}
