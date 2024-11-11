#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000], ans[100000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    ans[i] = 1000000;
    scanf("%d", &a[i]);
  }
  ans[n] = 1000000;
  ans[0] = -1;
  for (int i = 0; i < n; ++i) {
    int l = 0;
    int r = i + 1;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (ans[mid] < a[i])
        l = mid;
      else
        r = mid;
    }
    ans[l + 1] = min(ans[l + 1], a[i]);
  }
  for (int i = n; i > 0; --i)
    if (ans[i] < 1000000) {
      printf("%d\n", i);
      return 0;
    }
  return 0;
}
