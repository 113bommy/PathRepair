#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  long long int val;
  long long int idx;
};
long long int n, m, cf, cm, k;
node arr[100100];
long long int A[100100];
long long int myfunc(node f1, node f2) { return f1.val < f2.val; }
long long int binL(long long int val, long long int ll) {
  long long int l = 1;
  long long int h = ll;
  long long int mid;
  long long int ans = 1;
  while (l <= h) {
    mid = (l + h) / 2;
    if (A[mid] <= val) {
      ans = mid;
      l = mid + 1;
    } else
      h = mid - 1;
  }
  return ans;
}
long long int cal() {
  long long int ans = 0;
  long long int sum = 0;
  long long int ix;
  long long int mval;
  long long int tot = 0;
  for (long long int i = 1; i <= n; i++) tot = arr[i].val;
  tot = (m * n) - tot;
  if (k >= tot) {
    ans = (n * cf) + (m * cm);
    ix = 1;
    mval = m;
  }
  if (arr[n].val < m) {
    long long int idx = binL(k, n);
    long long int left = k - A[idx];
    long long int ww = (left / idx) + arr[idx].val;
    if (ww < m && ww * cm >= ans) {
      ans = ww * cm;
      ix = n + 1;
      mval = ww;
    }
  }
  for (long long int i = n; i > 1; i--) {
    sum = sum + arr[i].val;
    long long int need = ((n - i + 1) * m) - sum;
    long long int left = k - need;
    if (left < 0) break;
    long long int idx = binL(left, i - 1);
    long long int ex = left - A[idx];
    long long int ww = arr[idx].val + (ex / idx);
    if (ww > m) ww = m;
    long long int uu = (n - i + 1) * cf;
    long long int vv = ww * cm;
    if (ans <= uu + vv) {
      ans = uu + vv;
      ix = i;
      mval = ww;
    }
  }
  for (int i = ix; i <= n; i++) {
    arr[i].val = m;
  }
  for (int i = 1; i < ix; i++) {
    arr[i].val = max(mval, arr[i].val);
  }
  return ans;
}
int main() {
  scanf("%lld%lld%lld%lld%lld", &n, &m, &cf, &cm, &k);
  for (long long int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i].val);
    arr[i].idx = i;
  }
  sort(arr + 1, arr + n + 1, myfunc);
  long long int sum = 0;
  for (long long int i = 1; i <= n; i++) {
    sum = sum + arr[i].val;
    A[i] = (arr[i].val * i) - sum;
  }
  printf("%lld\n", cal());
  long long int CC[100100];
  for (long long int i = 1; i <= n; i++) {
    CC[arr[i].idx] = arr[i].val;
  }
  for (long long int i = 1; i <= n; i++) printf("%lld ", CC[i]);
  printf("\n");
  return 0;
}
