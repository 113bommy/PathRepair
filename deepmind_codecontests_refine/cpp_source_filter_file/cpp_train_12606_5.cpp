#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
set<long long> diff;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, a, b, ans = 0;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> a >> b;
    ans += a;
    diff.insert(b - a);
  }
  long long cnt = 0;
  for (long long i : diff) {
    if (ans <= m) {
      cout << cnt;
      return 0;
    }
    ans += i;
    cnt++;
  }
  if (ans <= m) {
    cout << cnt;
    return 0;
  }
  cout << -1;
  return 0;
}
