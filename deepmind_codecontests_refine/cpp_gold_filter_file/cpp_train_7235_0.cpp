#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[200005];
long long int x;
long long int ans;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      if (a[i] >= 0) {
        a[i] = a[i] + x;
        ans += abs(a[i]);
        x += (-a[i]);
      } else {
        a[i] = a[i] + x;
        ans += abs(a[i]);
        x += (-a[i]);
      }
    } else {
      x = (-a[i]);
      ans += abs(a[i]);
    }
  }
  printf("%I64d", ans);
  return 0;
}
