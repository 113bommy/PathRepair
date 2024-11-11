#include <bits/stdc++.h>
using namespace std;
int a[300001];
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum += a[i];
  }
  long long ans = sum;
  sort(a, a + n);
  for (int i = 0; i < n - 1; i++) {
    ans += sum;
    sum -= a[i];
  }
  printf("%I64d", ans);
  return 0;
}
