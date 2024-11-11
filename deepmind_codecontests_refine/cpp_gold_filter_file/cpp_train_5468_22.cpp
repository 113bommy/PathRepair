#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], t[maxn], r[maxn], st[maxn], dq[maxn];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int sz = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", t + i, r + i);
    while (sz && r[st[sz - 1]] <= r[i]) sz--;
    st[sz++] = i;
  }
  for (int i = n - 1; i >= r[st[0]]; i--) b[i] = a[i];
  int ds = 0, df = 0;
  for (int i = r[st[0]] - 1; i >= 0; i--) dq[ds++] = a[i];
  sort(dq, dq + ds);
  for (int i = 0; i < sz; i++) {
    int idx = r[st[i]];
    int jdx = (i + 1 < sz) ? r[st[i + 1]] : 0;
    for (int j = idx - 1; j >= jdx; j--)
      if (t[st[i]] == 2) {
        b[j] = dq[df++];
      } else {
        b[j] = dq[--ds];
      }
  }
  for (int i = 0; i < n; i++) printf("%d ", b[i]);
  printf("\n");
  return 0;
}
