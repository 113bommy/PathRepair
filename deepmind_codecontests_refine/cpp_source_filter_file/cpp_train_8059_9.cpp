#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
inline int getBit(int x, int pos) { return ((x >> pos) & 1); }
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)(1e5) + 10;
int n, q, k;
char str[maxn];
int a[maxn];
int ps[maxn];
int f[maxn];
int main() {
  scanf("%d%d%d", &n, &k, &q);
  scanf("%s", str);
  for (int i = 0; i < n; i++) {
    a[i + 1] = str[i] - '0';
    ps[i + 1] = ps[i] + a[i + 1];
  }
  for (int i = 0; i < k - 1; i++) {
    for (int lst = i, j = i + k; j <= n; lst = j, j += k) {
      f[j] = (f[lst] + (a[j] == 0) + ps[j - 1] - ps[lst]);
    }
  }
  while (q--) {
    int lf, rg;
    scanf("%d%d", &lf, &rg);
    printf("%d\n", f[rg] - f[lf - 1]);
  }
  return 0;
}
