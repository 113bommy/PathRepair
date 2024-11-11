#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int p;
int main() {
  int i;
  int n;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  long long ans = a[n];
  a[n + 1] = -1;
  long long temp = a[n];
  for (i = n - 1; i >= 1; i--) {
    if (a[i] >= temp) {
      temp--, temp = max(temp, (long long)0);
      ans += temp;
    } else {
      temp = min(a[i], temp);
      ans += temp;
    }
  }
  printf("%I64d", ans);
}
