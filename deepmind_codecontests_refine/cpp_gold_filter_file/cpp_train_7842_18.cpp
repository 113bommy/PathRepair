#include <bits/stdc++.h>
using namespace std;
long long overflow(long long a, long long b) { return (a * b) < 0; }
long long up(long long w, long long on) {
  if (w % on == 0) return w / on;
  return w / on + 1;
}
int main() {
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  long long rem = 0, last = 1;
  if (t == 1)
    cout << n << '\n';
  else {
    if (k == 1)
      cout << max(0LL, up(n * b + 1 - t, b)) << '\n';
    else {
      while (!overflow(last * k, k + b - 1) &&
             (last * k * (k + b - 1)) <= t * (k - 1) + b)
        ++rem, last *= k;
      cout << max(0LL, n - rem) << '\n';
    }
  }
  return 0;
}
