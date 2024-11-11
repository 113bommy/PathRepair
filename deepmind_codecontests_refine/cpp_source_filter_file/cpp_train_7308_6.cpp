#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200000;
long long fenw[MAXN];
long long get(long long i) {
  long long ans = 0;
  for (; i >= 0; i &= (i + 1), i--) ans += fenw[i];
  return ans;
}
void upd(long long i, long long x) {
  for (; i < MAXN; i |= (i + 1)) fenw[i] += x;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> brr(n);
  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
    arr[i]--;
    brr[arr[i]] = i;
  }
  long long cans = 0;
  for (long long k = 1; k <= n; ++k) {
    long long ind = brr[k - 1];
    long long p = get(ind);
    cans += k - 1 - p;
    cans -= min(p, k - 1 - p);
    upd(ind, 1);
    if (k == 1) {
      cout << cans << ' ';
      continue;
    }
    if (k % 2 == 1) {
      long long l = 0, r = n;
      while (r - l > 1) {
        long long m = (l + r) / 2;
        if (get(m) < (k + 1) / 2)
          l = m;
        else
          r = m;
      }
      long long indk2 = r;
      if (ind != indk2) cans += abs(indk2 - ind) - abs(get(indk2) - get(ind));
      cout << cans << ' ';
    } else {
      long long l = -1, r = n;
      while (r - l > 1) {
        long long m = (l + r) / 2;
        if (get(m) < k / 2)
          l = m;
        else
          r = m;
      }
      long long indk21 = r;
      l = -1, r = n;
      while (r - l > 1) {
        long long m = (l + r) / 2;
        if (get(m) < k / 2 + 1)
          l = m;
        else
          r = m;
      }
      long long indk22 = r;
      if (ind < indk21)
        cans += (indk21 - ind) - (get(indk21) - get(ind));
      else if (indk22 < ind)
        cans += (ind - indk22) - (get(ind) - get(indk22));
      else
        cans += (indk22 - indk21) - (get(indk22) - get(indk21));
      cout << cans << ' ';
    }
  }
  return 0;
}
