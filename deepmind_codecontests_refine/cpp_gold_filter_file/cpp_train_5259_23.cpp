#include <bits/stdc++.h>
using namespace std;
int b[1000000 + 1];
int main() {
  int i, n, j, ans;
  ans = n;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  j = 1;
  for (i = 1; i <= n; i++) {
    if (b[i] < b[i + 1])
      j++;
    else {
      ans = min(ans, n - j);
      j = 1;
    }
  }
  printf("%d\n", ans);
}
