#include <bits/stdc++.h>
using namespace std;
int num[555555];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int i;
  long long sum = 0;
  int ll = 1000000009, rr = -1;
  for (i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    ll = min(ll, num[i]);
    rr = max(rr, num[i]);
    sum += num[i];
  }
  sort(num, num + n);
  int tt = sum / n;
  if (sum % n) tt++;
  int l = max(ll, tt);
  int r = rr;
  int maxnum, minnum;
  while (l < r) {
    int mid = (l + r) / 2;
    long long temp = 0;
    for (i = n - 1; i >= 0; i--) {
      if (num[i] > mid) temp += num[i] - mid;
    }
    if (temp <= k) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (sum % n) tt--;
  maxnum = r;
  reverse(num, num + n);
  l = ll, r = min(rr, tt);
  while (l < r) {
    int mid = (l + r + 1) / 2;
    long long temp = 0;
    for (i = n - 1; i >= 0; i--) {
      if (num[i] < mid) temp += mid - num[i];
    }
    if (temp <= k) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  minnum = l;
  printf("%d\n", maxnum - minnum);
  return 0;
}
