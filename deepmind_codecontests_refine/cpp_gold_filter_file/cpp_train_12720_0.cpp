#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6;
long long cnt[MAXN], pcnt[MAXN], pmx[MAXN];
void upd(long long &mx1, long long &mx2) {
  if (mx2 > mx1) {
    swap(mx1, mx2);
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, maxa = 0;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    maxa = max(maxa, arr[i]);
    cnt[arr[i]]++;
  }
  sort(arr.begin(), arr.end());
  for (long long i = 1; i < MAXN; i++) {
    pcnt[i] = pcnt[i - 1];
    pcnt[i] += cnt[i];
    pmx[i] = pmx[i - 1];
    if (cnt[i] > 0) {
      pmx[i] = i;
    }
  }
  auto getPref = [&](long long l, long long r) {
    r = min(MAXN - 1, r);
    return pcnt[r] - pcnt[l - 1];
  };
  auto checkOne = [&](long long y, long long k, long long all) {
    long long maxs = 0;
    long long maxOst = 0;
    k--;
    while (k > 0) {
      long long R = y * (k + 1) - 1;
      if (pmx[R] >= k * y) {
        maxOst = max(maxOst, pmx[R] % y);
      }
      long long x = (k * y + maxOst) / 2;
      x = min(x, all - k);
      maxs = max(maxs, x * y);
      k--;
    }
    return maxs;
  };
  auto checkTwo = [&](long long y, long long k, long long all) {
    long long mx1 = 0, mx2 = 0;
    long long maxs = 0;
    k--;
    while (k >= 0) {
      long long R = y * (k + 1) - 1;
      long long f = pmx[R];
      long long s = f;
      if (cnt[f] == 1) {
        s = pmx[f - 1];
      }
      if (f % y > mx2 && f >= y * k) {
        mx2 = f % y;
        upd(mx1, mx2);
      }
      if (s % y > mx2 && s >= y * k) {
        mx2 = s % y;
        upd(mx1, mx2);
      }
      long long x1 = k * y + mx1;
      long long x2 = k * y + mx2;
      if (getPref(x1, MAXN) < 2) {
        x1 = 0;
      }
      if (getPref(x2, MAXN) < 2) {
        x2 = 0;
      }
      x1 = min(x1, all - 2 * k - 1);
      x2 = min(x2, all - 2 * k);
      if (x1 > 1) {
        maxs = max(maxs, x1 * y);
      }
      if (x2 > 1) {
        maxs = max(maxs, x2 * y);
      }
      k--;
    }
    return maxs;
  };
  long long answer = 0;
  for (long long i = 2; i <= maxa; i++) {
    long long all = 0;
    long long k = 1;
    while (i * k <= maxa) {
      k++;
      all += getPref(i * (k - 1), i * k - 1) * (k - 1);
    }
    answer = max(answer, checkOne(i, k, all));
    answer = max(answer, checkTwo(i, k, all));
  }
  cout << answer << '\n';
  return 0;
}
