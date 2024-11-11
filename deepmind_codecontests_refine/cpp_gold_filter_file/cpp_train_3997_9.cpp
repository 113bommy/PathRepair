#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100005;
struct query {
  long long l, r, val;
} q[NMAX];
long long n, m, k, i, j, b[NMAX], st, dr;
long long sir[NMAX], aux, B[NMAX];
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (i = 1; i <= n; i++) scanf("%I64d", &sir[i]);
  for (i = 1; i <= m; i++)
    scanf("%I64d%I64d%I64d", &q[i].l, &q[i].r, &q[i].val);
  for (i = 1; i <= k; i++) {
    scanf("%I64d%I64d", &st, &dr);
    b[st]++;
    b[dr + 1]--;
  }
  for (i = 1; i <= m; i++) {
    aux += b[i];
    q[i].val *= aux;
    st = q[i].l;
    dr = q[i].r;
    B[st] += q[i].val;
    B[dr + 1] -= q[i].val;
  }
  for (aux = 0, i = 1; i <= n; i++) {
    aux += B[i];
    printf("%I64d ", sir[i] + aux);
  }
  return 0;
}
