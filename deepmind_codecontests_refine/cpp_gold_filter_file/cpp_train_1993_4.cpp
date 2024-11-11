#include <bits/stdc++.h>
using namespace std;
long long n, k, a[5005], las[5005], c, mem[5005][5005];
long long solve(long long p = 0, long long rem = k) {
  if (p == n || !rem) return 0;
  if (~mem[p][rem]) return mem[p][rem];
  mem[p][rem] =
      max(solve(p + 1, rem), las[p] - p + 1 + solve(las[p] + 1, rem - 1));
  return mem[p][rem];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      if (a[j] - a[i] < 6)
        c = j;
      else
        break;
    }
    las[i] = c;
  }
  memset(mem, -1, sizeof(mem));
  cout << solve();
  return 0;
}
