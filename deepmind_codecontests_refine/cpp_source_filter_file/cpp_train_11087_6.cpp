#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num[100002], i, j, ans[100002], max;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%d", &num[i]);
  ans[n] = 0;
  max = 0;
  for (i = n; i >= 1; i--) {
    if (max < num[i]) {
      max = num[i];
      ans[i] = 0;
      ++max;
    } else
      ans[i] = max - num[i];
  }
  for (i = 1; i <= n; i++)
    if (i != n)
      printf("%d ", ans[i]);
    else
      printf("%d\n", ans[i]);
  return 0;
}
