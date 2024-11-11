#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int v[1000001];
int main() {
  long long nowsum = 0;
  long long offset = 0;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    nowsum += abs(a[i] - (i + 1));
    if (a[i] < i + 1) {
      v[i + 1 - a[i]]++;
      offset--;
    } else {
      offset++;
    }
  }
  ans = nowsum;
  int r = 0;
  for (int i = 0; i < n - 1; i++) {
    nowsum += offset;
    nowsum -= a[i];
    nowsum += abs(a[i] - n);
    if (a[i] != n) {
      offset -= 2;
      if (n - a[i] + i < n) v[n - a[i] + i + 1]++;
    }
    offset += 2 * v[i + 1];
    if (ans > nowsum) {
      ans = nowsum;
      r = n - 1 - i;
    }
  }
  printf("%I64d %d\n", ans, r);
  return 0;
}
