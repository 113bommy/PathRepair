#include <bits/stdc++.h>
using namespace std;
const int MX = 5 * 1e5;
long long N, X, Y, arr[MX];
long long pref[MX * 4 + 10];
long long num[MX * 4 + 10];
long long vis[MX * 4 + 10];
int ch(long long mid, long long j) { return abs(j - mid) * Y <= X; }
long long Co(int l, int r, int w) {
  if (l > r) return 0;
  if (w == 0) return num[r] - num[l - 1];
  return pref[r] - pref[l - 1];
}
int main() {
  scanf("%I64d%I64d%I64d", &N, &X, &Y);
  for (int i = 0; i < N; i++) {
    scanf("%I64d", &arr[i]);
    num[arr[i]]++;
  }
  for (int i = 1; i < 2 * 1e6 + 2; i++) {
    pref[i] += pref[i - 1];
    pref[i] += num[i] * i;
    num[i] += num[i - 1];
  }
  long long best = 1e18;
  for (long long i = 2; i < 2 * 1e6 + 2; i++) {
    if (vis[i]) continue;
    long long cur = 0;
    for (long long j = i; j < 2 * 1e6 + 2; j += i) {
      vis[j]++;
      long long lo = j - i + 1, hi = j, who = 0;
      while (lo <= hi) {
        long long mid = lo + hi;
        mid /= 2;
        if (ch(mid, j)) {
          hi = mid - 1;
          who = mid;
        } else
          lo = mid + 1;
      }
      long long a = abs(Co(who, j, 1) - Co(who, j, 0) * j) * Y;
      a += Co(j - i + 1, who - 1, 0) * X;
      cur += a;
    }
    best = min(best, cur);
  }
  cout << best << "\n";
  return 0;
}
