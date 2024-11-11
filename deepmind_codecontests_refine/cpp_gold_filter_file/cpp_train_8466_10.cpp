#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct TNode {
  long long a, b;
} nod[10050];
int main() {
  long long a1, a2, b1, b2, u, minl, k, i, j;
  while (scanf("%I64d%I64d", &n, &m) != EOF) {
    u = n;
    for (i = 0; i < n; i++) {
      scanf("%I64d%I64d", &nod[i].a, &nod[i].b);
      if (nod[i].a == 0) u--;
    }
    m -= u;
    minl = 1 << 30;
    for (i = 0; i < n; i++) {
      if (nod[i].a == 0) continue;
      k = nod[i].b / nod[i].a;
      if (nod[i].b % nod[i].a) k++;
      minl = min(minl, k);
    }
    for (k = 1, u = 0;; k++) {
      for (i = j = 0; i < n; i++) {
        a1 = nod[i].a / nod[i].b;
        a2 = nod[i].a % nod[i].b;
        b1 = k / nod[i].b;
        b2 = k % nod[i].b;
        j = j + (a1 * b1 * nod[i].b + a1 * b2 + a2 * b1 + (a2 * b2) / nod[i].b);
      }
      if (j == m) u++;
      if (j > m) break;
    }
    printf("%I64d\n", u);
  }
  return 0;
}
