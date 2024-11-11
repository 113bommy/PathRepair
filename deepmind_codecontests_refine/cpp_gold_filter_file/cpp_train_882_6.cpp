#include <bits/stdc++.h>
using namespace std;
long long mem[(1 << 18) + 1][20];
long long c[20][20];
long long arr[19];
long long n, m, k;
long long solve(long long mask, long long last, long long rem) {
  if (rem <= 0) return 0;
  long long &ret = mem[mask][last];
  if (ret != -1) return ret;
  ret = 0;
  for (long long i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      ret = max(ret, solve(mask | (1 << i), i, rem - 1) + arr[i] + c[last][i]);
    }
  }
  return ret;
}
int main() {
  cin >> n >> m >> k;
  memset(mem, -1, sizeof(mem));
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < k; i++) {
    long long f, l, g;
    cin >> f >> l >> g;
    f--;
    l--;
    c[f][l] = g;
  }
  cout << solve(0, 19, m);
  return 0;
}
