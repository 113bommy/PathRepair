#include <bits/stdc++.h>
using namespace std;
int n, m, o, re = 0;
long long res = 0;
int a[200010], ans[200010];
bool chk[200010];
int main() {
  int i, j, k, l;
  long long ll, rr, mid;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] += i;
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    ans[i] = a[i] - i;
    if (i > 0 && ans[i] < ans[i - 1]) break;
  }
  if (i < n) {
    printf(":(");
    return 0;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
