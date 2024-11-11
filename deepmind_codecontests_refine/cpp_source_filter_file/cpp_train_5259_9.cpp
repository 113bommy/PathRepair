#include <bits/stdc++.h>
using namespace std;
int arr[1000000 + 7];
int main(void) {
  int n;
  int val;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    arr[val] = i + 1;
  }
  int t = 1, res = -1;
  for (int i = 2; i <= n; i++) {
    if (arr[i - 1] < arr[i]) {
      t++;
    } else
      t = 1;
    res = max(res, t);
  }
  printf("%d\n", n - res);
  return 0;
}
