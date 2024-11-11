#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long g = a[0];
  for (long long i = 1; i < n; ++i) {
    g = gcd(g, abs(a[i] - a[i - 1]));
  }
  long long ans = 0;
  for (long long i = 0; i < n - 1; ++i) {
    long long y = a[i + 1] - a[i];
    y /= g;
    y--;
    ans += y;
  }
  cout << ans << '\n';
  return 0;
}
