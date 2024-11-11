#include <bits/stdc++.h>
using namespace std;
int mod1 = int(1e9) + 7;
vector<long long> bs;
vector<pair<long long, long long> > a;
long long n;
long long getmin(long long m, long long w) {
  int l = w, r = n - 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (m >= bs[mid]) {
      r = mid;
    } else
      l = mid;
  }
  m -= bs[r];
  return m / n + a[r].first;
}
int main() {
  long long aa, cf, cm, m;
  scanf(
      "%lld"
      "%lld"
      "%lld"
      "%lld"
      "%lld",
      &n, &aa, &cf, &cm, &m);
  a = vector<pair<long long, long long> >(n);
  for (int i = 0; i < (int)(n); ++i) {
    long long al;
    scanf("%lld", &al);
    a[i] = make_pair(al, i);
  }
  sort((a).begin(), (a).end());
  reverse((a).begin(), (a).end());
  bs = vector<long long>(n);
  long long ssum = 0;
  bs[n - 1] = 0;
  for (int i = (int)(n - 1) - 1; i >= 0; --i) {
    bs[i] = bs[i + 1] + (a[i].first - a[i + 1].first) * (n - 1 - i);
  }
  int nm = -1;
  ssum = 0;
  long long rrmin = getmin(m, -1);
  rrmin = min(aa, rrmin);
  long long mmax = cm * rrmin;
  if (rrmin == aa) {
    mmax += n * cf;
  } else {
    int cnt = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (a[i].first == aa) cnt++;
    }
    mmax += cnt * cf;
  }
  for (int i = 0; i < (int)(n); ++i) {
    ssum += aa - a[i].first;
    m -= aa - a[i].first;
    if (m < 0) break;
    long long rmin = getmin(m, i);
    rmin = min(aa, rmin);
    long long cand = cf * (i + 1) + cm * rmin;
    if (cand > mmax) {
      mmax = cand;
      nm = i;
      rrmin = rmin;
    }
  }
  for (int i = 0; i <= nm; i++) {
    a[i].first = aa;
  }
  for (int i = 0; i < (int)(n); ++i) {
    a[i].first = max(a[i].first, rrmin);
  }
  vector<long long> ans = vector<long long>(n);
  for (int i = (int)(n)-1; i >= 0; --i) {
    ans[a[i].second] = a[i].first;
  }
  printf(
      "%lld"
      "\n",
      mmax);
  for (int i = 0; i < (int)(n); ++i) {
    printf(
        "%lld"
        " ",
        ans[i]);
  }
  printf("\n");
  return 0;
}
