#include <bits/stdc++.h>
using namespace std;
int t, n, i, temp;
int a[5001];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    fill(a, a + 5001, -1);
    bool judge = false;
    for (i = 1; i <= n; i++) {
      scanf("%d", &temp);
      if (a[temp] != -1) {
        if (i - a[temp] > 1) judge = true;
      } else
        a[temp] = i;
    }
    judge ? printf("YES\n") : printf("NO\n");
  }
  return 0;
}
