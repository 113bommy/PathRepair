#include <bits/stdc++.h>
using namespace std;
long long a[100009], b[100009], s[100009];
pair<long long, long long> p[100009];
long long ans;
int main() {
  long long n, second, sum = 0;
  cin >> n >> second;
  for (long long i = 0; i < n; i++) {
    cin >> s[i] >> a[i] >> b[i];
    int x = (s[i] - s[i] % second);
    if (x - second > 0) x -= second;
    ans += max(a[i], b[i]) * x;
    s[i] -= x, a[i] -= b[i], sum += s[i];
    ans += b[i] * s[i];
    p[i] = {a[i], s[i]};
  }
  p[n] = {0, (second - sum % second) % second};
  n++;
  sort(p, p + n);
  reverse(p, p + n);
  for (long long i = 0; i < n;) {
    long long X = 0, W = 0;
    while (i < n && X < second) {
      long long q = min(p[i].second, second - X);
      X += q;
      W += p[i].first * q;
      p[i].second -= q;
      if (p[i].second == 0) i++;
    }
    if (W < 0) break;
    ans += W;
  }
  cout << ans << endl;
}
