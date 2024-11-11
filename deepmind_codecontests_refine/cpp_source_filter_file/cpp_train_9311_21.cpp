#include <bits/stdc++.h>
using namespace std;
const long MaxArray = 102107;
long n, ans;
long a[MaxArray];
void solve(long l, long r) {
  while (a[r + 1] > a[r] && r < n) {
    r++;
  }
  ans = max(ans, r - l + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long l = 1, r = 1;
  long tmp;
  while (r <= n) {
    r++;
    while (a[r] > a[r - 1] && r <= n) {
      r++;
    }
    long tmp = r - l;
    if (l > 1 && r <= n) {
      tmp++;
    }
    ans = max(ans, tmp);
    if (a[r - 2] + 1 < a[r]) {
      solve(l, r);
    }
    if (a[r - 1] + 1 < a[r + 1]) {
      solve(l, r + 1);
    }
    l = r;
  }
  cout << ans;
  return 0;
}
