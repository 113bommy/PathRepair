#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, m;
  int a[5];
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &m);
    sort(a, a + 3);
    if (m > a[0] + a[1] + a[2] - 3 || m < a[2] - a[1] - 2)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
