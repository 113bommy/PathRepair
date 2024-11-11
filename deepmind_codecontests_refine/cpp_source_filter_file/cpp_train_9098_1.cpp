#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 922337203685477;
const long long mininf = -922337203685477;
const long long nax = 3e5 + 20;
long long n, m, alive[nax], ans[nax], l, r, x;
long long f(long long xx) {
  if (xx == alive[xx]) {
    return xx;
  } else {
    return alive[xx] = f(alive[xx]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (long long i = 1; i <= n + 5; i++) {
    alive[i] = i;
  }
  for (long long i = 1; i <= m; i++) {
    cin >> l >> r >> x;
    for (long long j = l; j <= r; j = f(j + 1)) {
      if (j == x) {
        continue;
      }
      alive[j] = f(j + 1);
      ans[j] = x;
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
