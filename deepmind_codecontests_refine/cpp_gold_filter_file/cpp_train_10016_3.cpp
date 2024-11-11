#include <bits/stdc++.h>
using namespace std;
int inf = INT_MAX;
long long modulo(long long num, long long MOD = 1000000007) {
  return ((num % MOD) + MOD) % MOD;
}
long long power(long long b, long long e, long long MOD = 1000000007) {
  long long ans = 1;
  while (e) {
    if (e % 2) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e /= 2;
  }
  return ans;
}
long long inv(long long num, long long MOD = 1000000007) {
  return power(modulo(num), MOD - 2, MOD);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, m, n, pos[100005], num;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> num;
      pos[num] = i;
    }
    int max_pos = -1;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      cin >> num;
      if (pos[num] > max_pos) {
        max_pos = pos[num];
        ans += (2 * (pos[num] - i) + 1);
      } else {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
