#include <bits/stdc++.h>
using namespace std;
const int c = 128;
const int d = 10000;
long long r[c][d];
long long n;
int k;
int a[c];
long long ans;
long long get(long long n, long long k) {
  if (k == 0) return n;
  if (n < d && r[k][n] >= 0) return r[k][n];
  long long res = get(n, k - 1) - get(n / a[k], k - 1);
  if (n < d) r[k][n] = res;
  return res;
}
int main() {
  cin >> n >> k;
  int i;
  for (i = 1; i <= k; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + k + 1);
  memset(r, -1, sizeof(r));
  ans = get(n, k);
  cout << ans << '\n';
  return 0;
}
