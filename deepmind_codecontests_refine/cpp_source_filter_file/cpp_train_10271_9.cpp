#include <bits/stdc++.h>
using namespace std;
long a[100005], v[100005];
long t1[100005], t2[100005], tc[100005], t[100005];
pair<double, long> q[100005];
long c[100005];
long long mov(long a[], long na, long n) {
  long i = 0, j = na, tot = 0;
  long long s = 0;
  while (tot < n) {
    if (j < n && (i == na || a[i] > a[j])) {
      c[tot] = a[j];
      ++tot;
      ++j;
      s += na - i;
    } else {
      c[tot] = a[i];
      ++tot;
      ++i;
    }
  }
  for (long k = 0; k < n; ++k) a[k] = c[k];
  return s;
}
long long SORT(long a[], long l, long r) {
  if (l == r) return 0;
  long mid = (l + r) >> 1;
  long long s = SORT(a, l, mid) + SORT(a, mid + 1, r);
  s += mov(a + l, mid - l + 1, r - l + 1);
  return s;
}
int main() {
  long n, w;
  cin >> n >> w;
  for (long i = 0; i < n; ++i) scanf("%ld%ld", &a[i], &v[i]);
  for (long i = 0; i < n; ++i) {
    q[i].first = -a[i] / (double)(v[i] + w + (double)0.000009);
    q[i].second = i;
  }
  sort(q, q + n);
  for (long i = 0; i < n; ++i) t1[i] = q[i].second;
  for (long i = 0; i < n; ++i) {
    q[i].first = -a[i] / (double)(v[i] - w - (double)0.000009);
    q[i].second = i;
  }
  sort(q, q + n);
  for (long i = 0; i < n; ++i) t2[i] = q[i].second;
  for (long i = 0; i < n; ++i) tc[t2[i]] = i;
  for (long i = 0; i < n; ++i) t[i] = tc[t1[i]];
  long long s = SORT(t, 0, n - 1);
  cout << s << endl;
  return 0;
}
