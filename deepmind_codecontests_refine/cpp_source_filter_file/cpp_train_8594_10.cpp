#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n;
char a[2000000];
long long lsum1[2000000], lsum2[2000000];
long long rsum1[2000000], rsum2[2000000];
long long getsum(long long sum[], int x, int y) {
  if (x > y) return 0;
  return sum[y] - (x ? sum[x - 1] : 0);
}
int main() {
  int i, j, k, l;
  cin >> n;
  scanf("%s", a);
  for (i = 0; i < n; i++) {
    if (a[i] == 'D')
      lsum1[i] = 1, lsum2[i] = i;
    else
      rsum1[i] = 1, rsum2[i] = -i;
  }
  partial_sum(lsum1, lsum1 + n, lsum1);
  partial_sum(lsum2, lsum2 + n, lsum2);
  partial_sum(rsum1, rsum1 + n, rsum1);
  partial_sum(rsum2, rsum2 + n, rsum2);
  for (i = 0; i < n; i++) {
    int s1 = getsum(rsum1, 0, i - 1), s2 = getsum(lsum1, i + 1, n - 1);
    int s3;
    if (a[i] == 'D') {
      if (s1 == s2)
        s3 = 0;
      else if (s1 > s2)
        s3 = 1, s1 = s2 + 1;
      else
        s2 = s1, s3 = 0;
    } else {
      if (s1 == s2)
        s3 = 1;
      else if (s1 < s2)
        s3 = 0, s2 = s1 + 1;
      else
        s1 = s2, s3 = 1;
    }
    int low, high, mid;
    int t1, t2;
    low = i + 1, high = n - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (getsum(lsum1, i + 1, mid) >= s2)
        high = mid - 1;
      else
        low = mid + 1;
    }
    t2 = low;
    low = 0, high = i - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (getsum(rsum1, mid, i - 1) >= s1)
        low = mid + 1;
      else
        high = mid - 1;
    }
    t1 = high;
    long long ans = 0;
    if (s2) ans += 2 * (getsum(lsum2, i + 1, t2) - i * s2);
    if (s1) ans += 2 * (getsum(rsum2, t1, i - 1) + i * s1);
    if (s3 == 0)
      ans += i + 1;
    else
      ans += n - i;
    printf("%lld ", ans);
  }
  return 0;
}
