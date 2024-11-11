#include <bits/stdc++.h>
using namespace std;
long long int v[300001];
long long int f(long long int k) {
  long long int low = 1, high = 300000, mid, ans = 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (v[mid] <= k) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return ans;
}
int main() {
  long long int t = 1, n, m, i, j, k, sum = 0, ans = 0;
  scanf("%lld", &n);
  scanf("%lld", &k);
  if (k > (n * (n - 1)) / 2) {
    printf("Impossible");
    return 0;
  }
  v[1] = 0;
  for (i = 2; i < 300001; i++) {
    v[i] = v[i - 1] + (i - 1);
  }
  long long int count = n, l = 0;
  char x[1000000];
  while (n != 0 && k != 0) {
    i = f(k);
    n = n - i;
    k = k - (i * (i - 1)) / 2;
    m = i;
    for (j = 0; j < i; j++) x[l++] = '(';
    for (j = 0; j < i; j++) {
      x[l++] = ')';
      m--;
      while (n != 0 && k != 0 && k >= m) {
        k = k - m;
        n = n - 1;
        x[l++] = '(';
        x[l++] = ')';
      }
    }
  }
  for (i = 0; i < n; i++) {
    x[l++] = '(';
    x[l++] = ')';
  }
  if (k != 0) {
    printf("Impossible");
    return 0;
  }
  for (i = 0; i < l; i++) {
    printf("%c", x[i]);
  }
  return 0;
}
