#include <bits/stdc++.h>
const long double PI = 3.141592653589793238L;
const long long N = 2000005;
using namespace std;
long long ans[1 << 20], tmp[1 << 20];
pair<pair<long long, long long>, long long> a[101];
long long n, m, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, a, b, T;
  cin >> n >> a >> b >> T;
  long long t[n + 1];
  for (long long i = (long long)(1); i <= (long long)(n); ++i) {
    char ch;
    cin >> ch;
    t[i] = b * (ch == 'w');
  }
  if (T < 1 + t[1]) {
    cout << "0\n";
    return 0;
  }
  T -= 1 + t[1];
  long long ans = 1;
  long long l[n + 1];
  long long curr = 0;
  for (long long i = (long long)(2); i <= (long long)(n); ++i) {
    if (curr + a + 1 + t[i] > T) {
      curr = 2e9;
      l[i] = curr;
      continue;
    }
    curr += a + 1 + t[i];
    l[i] = curr;
    ans = max(ans, i);
  }
  long long r[n + 1];
  curr = 0;
  for (long long i = (long long)(n); i >= (long long)(2); --i) {
    if (curr + a + 1 + t[i] > T) {
      curr = 2e9;
      r[i] = curr;
      continue;
    }
    curr += a + 1 + t[i];
    r[i] = curr;
    ans = max(ans, n - i + 2);
  }
  for (long long i = (long long)(2); i <= (long long)(n); ++i) {
    long long low = i + 1, high = n;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (l[i] + a * (i - 1) + r[mid] <= T)
        ans = max(ans, i + n - mid + 1), high = mid - 1;
      else
        low = mid + 1;
    }
  }
  for (long long i = (long long)(n); i >= (long long)(2); --i) {
    long long low = 2, high = i - 1;
    while (low <= high) {
      long long mid = (low + high) / 2;
      if (r[i] + a * (n - i + 1) + l[mid] <= T)
        ans = max(ans, mid + n - i + 1), low = mid + 1;
      else
        high = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
