#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, ans, A[100005];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);
  i = 0;
  while (i < n - 1 && A[i] <= A[i + 1]) i++;
  ans = n - i - 1;
  if (ans == 0) {
    printf("0\n");
    return 0;
  }
  i++;
  while (i < n - 1 && A[i] <= A[i + 1]) i++;
  if (i < n - 1 || A[n - 1] >= A[0])
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
