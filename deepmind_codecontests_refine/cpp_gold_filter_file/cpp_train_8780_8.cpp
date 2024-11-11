#include <bits/stdc++.h>
using namespace std;
int n, m, ans, A[200010], B[200010], dat[200010];
unsigned long long cpow[200010], C = 1313131, hA, hB, dt2[200010];
void insert(int x, int v) {
  for (; x < 200010; x += x & -x) dat[x] += v;
}
int query(int x, int r = 0) {
  for (; x > 0; x -= x & -x) r += dat[x];
  return r;
}
void Uinsert(int x, unsigned long long v) {
  for (; x > 0; x -= x & -x) dt2[x] += v;
}
unsigned long long Uquery(int x, unsigned long long r = 0) {
  for (; x < 200010; x += x & -x) r += dt2[x];
  return r;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, a; i <= n; i++) scanf("%d", &a), A[a] = i;
  for (int i = 1, a; i <= m; i++) scanf("%d", &a), B[a] = i;
  for (int i = cpow[0] = 1; i <= m; i++) cpow[i] = cpow[i - 1] * C;
  for (int i = 1; i <= n; i++) insert(B[i], 1), Uinsert(B[i], cpow[i]);
  for (int i = 1; i <= n; i++) hA += cpow[i] * A[i];
  for (int i = 1; i <= n; i++) hB += cpow[i] * query(B[i]);
  if (hA * cpow[0] == hB) ans++;
  for (int i = n + 1; i <= m; i++) {
    int id = query(B[i - n]);
    insert(B[i - n], -1);
    hB -= cpow[i - n] * id;
    Uinsert(B[i - n], -cpow[i - n]);
    hB -= Uquery(B[i - n]);
    insert(B[i], 1);
    id = query(B[i]);
    hB += cpow[i] * id;
    hB += Uquery(B[i]);
    Uinsert(B[i], cpow[i]);
    if (hA * cpow[i - n] == hB) ans++;
  }
  printf("%d\n", ans);
}
