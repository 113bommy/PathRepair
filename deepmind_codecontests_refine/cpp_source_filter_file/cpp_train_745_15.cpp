#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
constexpr int MOD = 1e9 + 7;
long long n, k, fact[N], lim, ans;
vector<int> remain;
int build(int p, long long num, int limit) {
  if (p == limit) return num <= lim;
  return build(p + 1, num * 10 + 4, limit) + build(p + 1, num * 10 + 7, limit);
}
bool is(int x) {
  while (x) {
    if ((x % 10) != 4 && (x % 10) != 7) return false;
    x /= 10;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  lim = max(0ll, n - 13);
  fact[0] = 1;
  for (int i = 1; i <= 14; i++) fact[i] = fact[i - 1] * i;
  if (n <= 13 && fact[n] < k) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i < 10; i++) ans += build(0, 0, i);
  for (int i = max(1ll, n - 13); i <= n; i++) remain.push_back(i);
  for (int i = max(1ll, n - 13); i <= n; i++) {
    int p = 0;
    while (fact[n - i] < k) {
      k -= fact[n - i];
      p++;
    }
    if (is(i) && is(remain[p])) ans++;
    remain.erase(remain.begin() + p);
  }
  cout << ans << '\n';
  return 0;
}
