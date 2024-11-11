#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000010;
int n;
int a[MAX_N], p[MAX_N], f[MAX_N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; ++i) {
    int j;
    scanf("%d", &j);
    p[j - 1] = i;
  }
  for (int i = 0; i <= n - 1; ++i) {
    scanf("%d", &a[i]);
    a[i] = p[a[i] - 1];
  }
  int top = 0;
  f[0] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int l = 0, r = top, t = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (a[f[mid]] >= a[i]) {
        t = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    if (t == top) ++top;
    f[++t] = i;
  }
  printf("%d\n", ++top);
  return 0;
}
