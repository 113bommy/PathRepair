#include <bits/stdc++.h>
using namespace std;
long long N, res;
int cub[35000005], a[35000005];
bool in(long long l, long long r, long long i) {
  if (l <= r) return i >= l && i <= r;
  return i >= l || i <= r;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (long long i = 1; i <= N; i++) cin >> a[i];
  for (long long j = 0; j < 24; j++) {
    long long ans = 0;
    long long md = (1 << (j + 1));
    for (long long i = 0; i < md; i++) cub[i] = 0;
    for (long long i = 1; i <= N; i++) cub[a[i] % md]++;
    long long l = md / 2, r = md - 1;
    long long sum = 0;
    for (long long i = l; i <= r; i++) sum += cub[i];
    for (long long i = 0; i < md; i++) {
      ans += ((long long)sum * (long long)cub[i]);
      if (in(l, r, i)) ans -= cub[i];
      sum -= cub[r];
      l = (l - 1 + md) % md;
      r = (r - 1 + md) % md;
      sum += cub[l];
    }
    ans /= 2;
    if (ans & 1) res ^= (1 << j);
  }
  cout << res << "\n";
  return 0;
}
