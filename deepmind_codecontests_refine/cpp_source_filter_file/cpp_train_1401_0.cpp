#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ans[23333];
long long n;
bool is(long long x) {
  if (x == 1) return false;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
void solve(long long sum) {
  for (int i = 2; i <= n; i++) {
    if (ans[i] == 1 && is(i) && is(sum - i)) {
      ans[i] = 2;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n) {
    long long sum = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) ans[i] = 1;
    if (is(sum))
      ;
    else if (sum & 1) {
      if (is(n - 2))
        ans[2] = 2;
      else {
        ans[3] = 3;
        solve(sum - 3);
      }
    } else {
      solve(sum);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
  }
  return 0;
}
