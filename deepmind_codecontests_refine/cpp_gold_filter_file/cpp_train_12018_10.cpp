#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], flag[100005];
int main() {
  int i, n;
  while (cin >> n) {
    for (i = 0; i <= 100005; i++) flag[i] = -1;
    int ff = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d %d", &a[i], &b[i]);
      if (flag[b[i]] + 1 == a[i]) flag[b[i]] = a[i];
      if (a[i] > flag[b[i]] + 1) {
        ff = 1;
      }
    }
    if (ff == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
