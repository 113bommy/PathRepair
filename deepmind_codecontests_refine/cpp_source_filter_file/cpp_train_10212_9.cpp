#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
const long long inf = 0x3f3f3f3f;
long long n, m, a[maxn], num[maxn];
long long solve(long long x) {
  long long ans = 0, nw = 0, dt = 0;
  memset(num, 0, sizeof(num));
  num[n] = 1;
  for (long long i = 1; i <= n; i++) {
    if (a[i] >= x) {
      dt += num[nw + n];
      nw++;
    } else {
      nw--;
      dt -= num[nw + n];
    }
    num[nw + n]++;
    ans += dt;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  cout << solve(m) - solve(m + 1);
  return ~~(0 ^ 0 ^ 0);
}
