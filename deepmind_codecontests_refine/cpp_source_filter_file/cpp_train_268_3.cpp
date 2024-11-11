#include <bits/stdc++.h>
using namespace std;
long n, k, m, t[45];
long i, j, strSum, ans;
void qsort(int b, int e) {
  long l = b, r = e;
  long piv = t[(l + r) / 2];
  while (l <= r) {
    while (t[l] < piv) l++;
    while (t[r] > piv) r--;
    if (l <= r) swap(t[l++], t[r--]);
  }
  if (b < r) qsort(b, r);
  if (e > l) qsort(l, e);
}
int main() {
  cin >> n >> k >> m;
  for (i = 0; i < k; ++i) cin >> t[i];
  qsort(0, k - 1);
  strSum = 0;
  for (i = 0; i < k; ++i) strSum += t[i];
  ans = 0;
  for (i = 0; i < n + 1 && m >= strSum * i; ++i) {
    long lans = i * (k + 1);
    long lm = m - strSum * i;
    for (j = i; j < k && lm >= t[j]; ++j) {
      if (lm >= t[j] * (n - i)) {
        lm -= t[j] * (n - i);
        if (j == k - 1)
          lans += (n - i) * 2;
        else
          lans += n - i;
      } else {
        long cnt = lm / t[j];
        lm -= t[j] * cnt;
        if (j == k - 1)
          lans += cnt * 2;
        else
          lans += cnt;
      }
    }
    if (lans > ans) ans = lans;
  }
  cout << ans;
  getchar();
  getchar();
  return 0;
}
