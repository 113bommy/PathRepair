#include <bits/stdc++.h>
using namespace std;
int n;
long long A, cf, cm, m;
pair<int, int> a[111111];
long long REM[111111], sum[111111];
int res[111111];
bool ok(int x, long long rem, int n) {
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid].first <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }
  long long need = 1LL * x * (l + 1) - (l >= 0 ? sum[l] : 0);
  return (need <= rem);
}
int getMin(long long rem, int n) {
  int l = 0, r = A + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(mid, rem, n)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  long long second = 0;
  for (int i = 0; i < n; i++) {
    second += a[i].first;
    sum[i] = second;
  }
  long long best = -1LL;
  int bk = -1;
  long long rem = m;
  for (int k = 0; k <= n; k++) {
    if (rem < 0) {
      break;
    }
    REM[k] = rem;
    long long cur = cf * k;
    cur += cm * getMin(rem, n - k);
    if (cur > best) {
      best = cur;
      bk = k;
    }
    if (k < n) {
      rem -= (A - a[n - 1 - k].first);
    }
  }
  cout << best << endl;
  int mn = getMin(REM[bk], n - bk);
  for (int i = 0; i < n; i++) {
    int pos = a[i].second;
    if (i < n - bk) {
      res[pos] = max(mn, a[i].first);
    } else {
      res[pos] = A;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", res[i]);
  }
  puts("");
  return 0;
}
