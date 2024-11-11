#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn], b[maxn];
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i]);
  }
  int l = 0, r = 0, cnt = 0;
  long long sa = 0, sb = 0;
  while (l < n && r < m) {
    if (sa == 0 && sb == 0) {
      sa += a[l++];
      sb += b[r++];
    }
    if (sa > sb) {
      sb += b[r++];
    } else if (sa < sb) {
      sa += a[l++];
    } else if (sa == sb) {
      cnt++;
      sa = sb = 0;
    }
  }
  while (l < n) sa += a[l++];
  while (r < m) sb += b[r++];
  if (sa != sb) {
    printf("-1\n");
  } else {
    printf("%d\n", cnt + (sa == 0 ? 0 : 1));
  }
}
