#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int a[200002];
int b[200002];
int p[200002];
int main() {
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    p[t - 1] = i;
  }
  int cur = int(2e9);
  for (int i = n - 1; i >= 0; --i) {
    int pos = p[i];
    b[pos] = min(r, cur - 1 + a[pos]);
    if (cur <= b[pos] - a[pos] || b[pos] < l) {
      puts("-1");
      return 0;
    }
    cur = b[pos] - a[pos];
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", b[i], " \n"[i + 1 == n]);
  }
  return 0;
}
