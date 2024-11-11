#include <bits/stdc++.h>
using namespace std;
long s[100005], a[100005], b[100005];
const long maxint = 2147483647;
long getans(long a[], int n) {
  long sum = -maxint, b = 0;
  int i;
  for (i = 1; i <= n; i++) {
    if (b > 0)
      b += a[i];
    else
      b = a[i];
    sum = sum > b ? sum : b;
  }
  return sum;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i;
    memset(s, 0, sizeof(s));
    for (i = 1; i <= n; i++) {
      scanf("%ld", &a[i]);
      s[i] = s[i - 1] + a[i];
    }
    long mid = getans(a, n);
    printf("%ld\n", 2 * mid - s[n]);
  }
  return 0;
}
