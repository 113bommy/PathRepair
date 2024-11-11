#include <bits/stdc++.h>
using namespace std;
long long n, result[51][51][51], a[123456], b[12345];
pair<long long, long long> m[12345];
void inp() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i], a[i] *= (-1000);
  for (long long i = 1; i <= n; i++) cin >> b[i];
  for (long long i = 1; i <= n; i++) m[i].first = a[i], m[i].second = b[i];
  sort(m + 1, m + 1 + n);
  for (long long i = 0; i <= n; i++) m[i].first = -m[i].first;
}
bool check(long long need) {
  for (long long i = 0; i <= n; i++) {
    m[i].second = need * m[i].second - m[i].first;
    for (long long j = 0; j <= n; j++)
      for (long long k = 0; k <= n; k++) result[i][j][k] = -1e15;
  }
  for (long long i = 1; i <= n; i++) {
    if (m[i].first != m[i - 1].first)
      for (long long j = 0; j <= i; j++)
        for (long long k = 0; k <= i; k++) {
          result[i - 1][j][0] = max(result[i - 1][j][0], result[i - 1][j][k]);
          if (k != 0) result[i - 1][j][k] = -1e15;
        }
    result[0][0][0] = 0;
    for (long long j = 0; j <= i; j++) {
      for (long long k = 0; k <= i; k++) {
        if (k > 0 && j > 0)
          result[i][j][k] =
              max(result[i][j][k], result[i - 1][j - 1][k - 1] + m[i].second);
        if (k < i && j < i && j + 1 != k)
          result[i][j][k] = max(result[i][j][k], result[i - 1][j + 1][k]);
      }
    }
  }
  for (long long i = 0; i <= n; i++)
    m[i].second = (m[i].second + m[i].first) / need;
  for (long long j = 0; j <= n; j++)
    for (long long k = 0; k <= n; k++) {
      if (result[n][j][k] >= 0) return true;
    }
  return false;
}
void do_it() {
  long long l = 1, r = 1e9, kq;
  while (r >= l) {
    long long mid = (l + r) / 2;
    if (check(mid))
      kq = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << kq;
}
int main() {
  inp();
  do_it();
}
