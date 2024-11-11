#include <bits/stdc++.h>
using namespace std;
const int MI = 1e9;
const int MAX = 1e5 + 5;
int n, a[MAX];
char b[MAX];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", b);
  int l = -MI;
  int r = MI;
  int t = 1, p = 5;
  while (p <= n) {
    if (t == 1) {
      if (b[p - 1] == '1') {
        for (int i = p - 4; i < p; i++) l = max(l, a[i] + 1);
        p += 4;
        t ^= 1;
      } else
        p++;
    } else {
      if (b[p - 1] == '0') {
        for (int i = p - 4; i < p; i++) r = min(r, a[i] - 1);
        p += 4;
        t ^= 1;
      } else
        p++;
    }
  }
  printf("%d %d\n", l, r);
  return 0;
}
