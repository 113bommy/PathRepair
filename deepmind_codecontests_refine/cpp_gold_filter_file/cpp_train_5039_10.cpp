#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, M = 30, LG = 30, base = 2;
const int MOD = 1e9 + 7, mod = 1e9 + 9;
const long long INF = 1e9, inf = 1e18;
long long n, p[N], sum, cnt, ans;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) {
    sum += p[i];
    cnt = max(cnt + p[i], (long long)0);
    ans = max(ans, cnt);
  }
  ans = 2 * ans - sum;
  return cout << ans, 0;
}
