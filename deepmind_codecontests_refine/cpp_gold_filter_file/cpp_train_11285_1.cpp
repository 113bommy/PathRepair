#include <bits/stdc++.h>
using namespace std;
const int nm = 100002;
int n;
int a[nm];
bool f[nm];
void nhap() {
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
}
int dd(int n) {
  int l = 0;
  while (n) {
    l++;
    n /= 2;
  }
  return (l);
}
bool bit(int i, int n) { return ((n >> i) & 1); }
bool kt(int i) {
  int j, t = (1 << i) - 1, d = 0;
  memset(f, 0, sizeof(f));
  for (j = 1; j <= n; ++j) {
    if (bit(i, a[j])) {
      f[j] = 1;
      t = t & a[j];
      d++;
    }
  }
  if (t % (1 << i) == 0) {
    printf("%d\n", d);
    for (j = 1; j <= n; ++j)
      if (f[j]) printf("%d ", a[j]);
    return (1);
  }
  return (0);
}
void xuli() {
  int i;
  for (i = 29; i >= 0; --i) {
    if (kt(i)) break;
  }
}
int main() {
  nhap();
  xuli();
}
