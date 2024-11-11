#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
void help(long long x, long long y, long long w, long long *a) {
  ans = max(ans, y);
  if (x < 1) return;
  long long qw = min(a[x], (w - y) / x);
  long long i = max((long long)0, qw - 5);
  for (long long j = i; j <= qw; j++) {
    long long z = y + j * x;
    help(x - 1, z, w, a);
  }
}
int main() {
  long long w;
  cin >> w;
  long long a[9];
  for (long long i = 1; i < 9; i++) cin >> a[i];
  help(8, 0, w, a);
  cout << ans;
  return 0;
}
