#include <bits/stdc++.h>
using namespace std;
bool have(long long *a, long long m, long long x, long long n) {
  priority_queue<long long, vector<long long>, greater<long long> > q;
  long long x1 = 0;
  for (long long i = 0; i < n; ++i) {
    q.push(a[i]);
    if (m + a[i] < 0) {
      ++x1;
      if (q.empty() || x1 > x) return false;
      long long m1 = q.top();
      q.pop();
      m -= m1;
    }
    m += a[i];
  }
  return true;
}
long long bin(long long r, long long *a, long long x, long long n) {
  long long l = -1000000000000000, ans = 0;
  while (l < (r - 1)) {
    ans = (l + r) / 2;
    if (have(a, ans, x, n))
      r = ans;
    else
      l = ans;
  }
  return ans;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long *a = (long long *)malloc(sizeof(long long) * n);
  long long *b = (long long *)malloc(sizeof(long long) * m);
  long long *q = (long long *)malloc(sizeof(long long) * n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < m; ++i) cin >> b[i];
  for (long long i = 0; i < n; ++i) {
    long long pr = (i) ? q[i - 1] : 1000000000000000;
    q[i] = bin(pr, a, i, n);
  }
  for (long long i = 0; i < m; ++i)
    cout << lower_bound(q, q + n, b[i], greater<long long>()) - q << endl;
  return 0;
}
