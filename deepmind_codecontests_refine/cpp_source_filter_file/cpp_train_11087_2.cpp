#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100002], m[100002], i, j, ans[100002];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  m[n - 1] = 0;
  ans[n - 1] = 0;
  for (i = n - 2; i >= 0; i--) {
    m[i] = max(m[i + 1], a[i + 1]);
    ans[i] = m[i] - a[i] + 1;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
