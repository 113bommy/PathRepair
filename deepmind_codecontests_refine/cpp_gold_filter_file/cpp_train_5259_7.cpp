#include <bits/stdc++.h>
using namespace std;
int n;
int A[100007] = {0};
int main() {
  scanf("%d", &n);
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    A[x] = i;
  }
  int ans = 0, l = 1;
  for (int i = 2; i <= n; i++) {
    if (A[i] > A[i - 1])
      l++;
    else
      ans = max(ans, l), l = 1;
  }
  ans = max(ans, l);
  printf("%d\n", n - ans);
  return 0;
}
