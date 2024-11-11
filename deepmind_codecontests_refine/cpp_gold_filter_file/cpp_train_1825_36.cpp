#include <bits/stdc++.h>
using namespace std;
struct Part {
  char c;
  long long l;
  bool operator==(Part &b) { return c == b.c and l == b.l; }
  bool operator<=(Part &b) { return c == b.c and l <= b.l; }
};
long long n, m, pi[200001];
Part a[200001], b[200001];
long long ans;
void compress(Part *a, long long &n) {
  long long m = 0;
  for (long long i = 0; i < n; i++) {
    if (m == 0 or a[m - 1].c != a[i].c)
      a[m++] = a[i];
    else
      a[m - 1].l += a[i].l;
  }
  n = m;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> a[i].l >> a[i].c >> a[i].c;
  for (long long i = 0; i < m; i++) cin >> b[i].l >> b[i].c >> b[i].c;
  compress(a, n);
  compress(b, m);
  ans = 0;
  if (m == 1) {
    for (long long i = 0; i < n; i++) {
      if (b[0] <= a[i]) ans += a[i].l - b[0].l + 1;
    }
  } else if (m == 2) {
    for (long long i = 0; i < n - 1; i++) {
      if (b[0] <= a[i] and b[1] <= a[i + 1]) ans++;
    }
  } else {
    pi[1] = 0;
    for (long long i = 2; i < m - 1; i++) {
      long long j = pi[i - 1];
      while (j > 0 and !(b[j + 1] == b[i])) j = pi[j];
      if (b[j + 1] == b[i]) j++;
      pi[i] = j;
    }
    for (long long i = 1, j = 0; i < n - 1; i++) {
      while (j > 0 and !(b[j + 1] == a[i])) j = pi[j];
      if (b[j + 1] == a[i]) j++;
      if (j == m - 2) {
        if (b[0] <= a[i - j] and b[j + 1] <= a[i + 1]) ans++;
        j = pi[j];
      }
    }
  }
  cout << ans;
  return 0;
}
