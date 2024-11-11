#include <bits/stdc++.h>
using namespace std;
long long row[1000];
long long col[1000];
long long n, m;
long long fc(long long x) {
  long long res = 0;
  for (long long i = 0; i < m; i++) {
    res += col[i] * 1LL * (1 + 2 * i - 2 * x) * 1LL * (1 + 2 * i - 2 * x);
  }
  return res;
}
long long fr(long long x) {
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    res += row[i] * 1LL * (1 + 2 * i - 2 * x) * 1LL * (1 + 2 * i - 2 * x);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long x, y;
  long long ans = 0;
  long long cur;
  long long a;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a;
      row[i] += a;
      col[j] += a;
    }
  }
  long long l, m1, m2, r;
  l = 0;
  r = m;
  while (r - l >= 3) {
    m1 = l + (r - l) / 3;
    m2 = l + 2 * (r - l) / 3;
    if (fc(m1) < fc(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  cur = fc(l);
  x = l;
  long long tmp;
  for (long long i = l + 1; i <= r; i++) {
    tmp = fc(i);
    if (tmp < cur) {
      cur = tmp;
      x = i;
    }
  }
  ans += cur;
  l = 0;
  r = n;
  while (r - l >= 3) {
    m1 = l + (r - l) / 3;
    m2 = l + 2 * (r - l) / 3;
    if (fr(m1) < fr(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  cur = fr(l);
  y = l;
  for (long long i = l + 1; i <= r; i++) {
    tmp = fr(i);
    if (tmp < cur) {
      cur = tmp;
      y = i;
    }
  }
  ans += cur;
  cout << ans * 4 << "\n" << y << " " << x;
  return 0;
}
