#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn], n;
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n == 1) {
      puts("1 0");
      continue;
    }
    int cur1 = 1, cur2 = n;
    while (cur1 + 1 <= cur2) {
      if (a[cur1] < a[cur2])
        a[cur2] -= a[cur1], cur1++;
      else if (a[cur1] > a[cur2])
        a[cur1] -= a[cur2], cur2--;
      else if (a[cur1] == a[cur2])
        cur1++, cur2--;
    }
    printf("%d %d\n", cur1, n - cur1);
  }
  return 0;
}
