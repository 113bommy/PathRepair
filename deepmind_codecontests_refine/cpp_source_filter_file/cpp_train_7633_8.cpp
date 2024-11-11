#include <bits/stdc++.h>
using namespace std;
struct grr {
  int x, y, z;
};
bool foo(grr a, grr b) { return a.y < b.y; }
int N, M, k = 0, k1 = 0, tn = 0, pos = 0, res[100023], k2 = 0;
grr a[100023], b[100023];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    a[i].z = i;
  }
  while ((k < N) || (k1 != 0)) {
    if ((k1 < M) && (pos == 0) && (k < N)) {
      b[k1].x = a[k].x;
      b[k1].y = a[k].y;
      b[k1].z = a[k].z;
      k++;
      k1++;
      tn = max(a[k - 1].x, tn);
      continue;
    }
    sort(b, b + k1, foo);
    tn += b[0].y - pos;
    pos = b[0].y;
    res[b[0].z] = tn;
    k2 = 1;
    for (int i = 1; i < k1; i++) {
      if (b[i].y == b[i - 1].y) {
        res[b[i].z] = tn;
        k2++;
      } else {
        tn += 1 + k2 / 2;
        tn += b[i].y - pos;
        pos = b[i].y;
        k2 = 0;
        res[b[i].z] = tn;
      }
    }
    if (k2 != 0) tn += 1 + k2 / 2;
    k1 = 0;
    tn += pos;
    pos = 0;
  }
  for (int i = 0; i < N; i++) printf("%d ", res[i]);
  return 0;
}
