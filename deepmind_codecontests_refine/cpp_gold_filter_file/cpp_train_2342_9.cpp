#include <bits/stdc++.h>
using namespace std;
int n;
long long int a[100005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", a + i);
  for (int i = 0; i < n; i++) {
    long long int mini = LLONG_MAX;
    if (i - 1 >= 0) mini = min(mini, a[i] - a[i - 1]);
    if (i + 1 < n) mini = min(mini, a[i + 1] - a[i]);
    long long int maxi = 0;
    maxi = max(maxi, a[i] - a[0]);
    maxi = max(maxi, a[n - 1] - a[i]);
    printf("%I64d %I64d\n", mini, maxi);
  }
}
