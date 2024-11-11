#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (!b) ? a : gcd(b, a % b);
}
int t = 1;
int ti;
const int N = 1e5 + 5;
long long int n, k;
long long int a[N];
void solve() {
  cin >> n >> k;
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  int l = 0, r = n - 1;
  sort(a, a + n);
  long long int diff = a[r] - a[l];
  long long int cntl = 0, cntr = 0;
  while (l < r && k > 0) {
    long long int dl = a[l + 1] - a[l];
    long long int dr = a[r] - a[r - 1];
    cntl = l + 1;
    cntr = n - r;
    if (cntl < cntr) {
      if (dl * cntl <= k) {
        k -= cntl * dl;
        diff -= dl;
        l += 1;
      } else {
        diff -= k / cntl;
        break;
      }
    } else {
      if (dr * cntr <= k) {
        k -= cntr * dr;
        diff -= dr;
        r -= 1;
      } else {
        diff -= k / cntr;
        break;
      }
    }
  }
  cout << diff;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
