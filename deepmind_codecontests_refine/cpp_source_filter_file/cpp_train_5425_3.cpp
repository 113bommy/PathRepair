#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n, m, e, t, f;
int a[maxn], b[maxn], c[maxn], d[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &e, &f);
    b[e] = f;
    b[f] = e;
  }
  for (int i = 1; i <= 2 * n; i++) d[i] = a[i] + (b[i] == 0 ? 0 : 100);
  scanf("%d", &t);
  if (t == 2) {
    scanf("%d", &e);
    c[e] = 1;
  } else
    e = 0;
  c[0] = 1;
  for (int i = 0; i < n; i++) {
    if (c[b[e]] == 0) {
      cout << b[e] << endl;
      c[b[e]] = 1;
    } else {
      int op = -1, bes = 0;
      for (int j = 1; j <= 2 * n; j++) {
        if (c[j]) continue;
        if (d[j] > op) {
          bes = j;
          op = d[j];
        }
      }
      cout << bes << endl;
      c[bes] = 1;
    }
    if (i == n - 1 && t == 2) break;
    scanf("%d", &e);
    c[e] = 1;
  }
  getchar();
  getchar();
}
