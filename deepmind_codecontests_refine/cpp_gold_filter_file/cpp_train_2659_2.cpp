#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, i, cnt = 0;
  scanf("%d%d", &n, &h);
  int a[n];
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    if (a[i] > h) {
      cnt += 2;
    } else
      cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
