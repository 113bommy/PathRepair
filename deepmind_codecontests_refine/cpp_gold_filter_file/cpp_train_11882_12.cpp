#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100100;
const long long AA = 1000000;
long long n;
long long num[MAXN];
long long snum[MAXN];
long long nused[MAXN];
long long loc[MAXN];
long long l[2 * MAXN], r[2 * MAXN];
bool lucky(long long x) {
  while (x > 0) {
    if ((x % 10 != 4) && (x % 10 != 7)) return false;
    x /= 10;
  }
  return true;
}
long long findloc(long long x) {
  long long lo = 0, hi = n - 1;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (x > snum[mid])
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> num[i];
    num[i] *= AA;
    snum[i] = num[i];
  }
  sort(snum, snum + n);
  for (long long i = 0; i < MAXN; i++) nused[i] = 0;
  for (long long i = 0; i < n; i++) {
    long long lo = findloc(num[i]);
    loc[lo + nused[lo]] = i;
    num[i] += nused[lo];
    nused[lo]++;
  }
  for (int i = 0; i < MAXN; i++) {
    if (nused[i]) {
      for (int j = i + 1; j < i + nused[i]; j++) snum[j] += j - i;
      i += nused[i] - 1;
    }
  }
  long long lnum = -1;
  for (long long i = 0; i < n; i++)
    if (lucky(num[loc[i]] / AA) && (nused[i] > 0)) {
      lnum = i;
      break;
    }
  if (lnum == -1) {
    bool check = true;
    for (long long i = 0; i < n - 1; i++)
      if (num[i] > num[i + 1]) check = false;
    if (check) {
      cout << "0\n";
      return 0;
    } else {
      cout << "-1\n";
      return 0;
    }
  }
  long long k = 0;
  long long cur = 0;
  while (cur < n) {
    if (cur == lnum) {
      cur++;
      continue;
    }
    if (loc[lnum] != cur) {
      l[k] = loc[lnum];
      r[k] = cur;
      k++;
      swap(num[loc[lnum]], num[cur]);
      swap(loc[lnum], loc[findloc(num[loc[lnum]])]);
    }
    if (loc[cur] != cur) {
      l[k] = loc[cur];
      r[k] = cur;
      k++;
      swap(num[cur], num[loc[cur]]);
      swap(loc[lnum], loc[cur]);
    }
    cur++;
  }
  cout << k << "\n";
  for (long long i = 0; i < k; i++) cout << l[i] + 1 << " " << r[i] + 1 << "\n";
  return 0;
}
