#include <bits/stdc++.h>
using namespace std;
long long a[100100];
long long s[100100];
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
    s[i] = s[i - 1] + a[i];
  }
  if (sum % 2 == 1)
    printf("NO\n");
  else {
    int flag = 0;
    long long mid = sum / 2;
    for (int i = 1; i < n; i++) {
      int k = lower_bound(s + i + 1, s + 1 + n, mid + a[i]) - (s);
      if (s[k] == mid + a[i]) {
        flag = 1;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      int k = lower_bound(s, s + i - 1, mid - a[i]) - (s);
      if (s[k] == mid - a[i]) {
        flag = 1;
        break;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
