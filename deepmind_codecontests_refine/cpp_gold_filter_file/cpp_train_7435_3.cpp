#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100005];
  int b[100005];
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    if (b[i] % 2 == 0) {
      long long num = b[i] / 2;
      if (a[i] < num) {
        ans--;
      } else {
        ans += num * num;
      }
    }
    if (b[i] % 2 != 0) {
      long long num = b[i] / 2;
      if (num == 0) {
        ans--;
      }
      if (a[i] < num + 1) {
        ans--;
      } else {
        ans += (num) * (num + 1);
      }
    }
  }
  printf("%I64d", ans);
  return 0;
}
