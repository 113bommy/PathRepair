#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long long md = 1e9 + 7;
vector<long long> fact;
long long pw(long long x, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * x) % md;
    x = (x * x) % md;
    p >>= 1;
  }
  return ret;
}
long long back(long long x) { return pw(x, md - 2); }
long long C(long long n, long long k) {
  long long ret = fact[n];
  ret = (ret * back(fact[k])) % md;
  ret = (ret * back(fact[n - k])) % md;
  return ret;
}
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  fact.resize(n + 1);
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % md;
  if (k + 1 >= n) {
    cout << fact[n] << '\n';
    return 0;
  }
  vector<long long> good(n + 1);
  for (int i = 1; i <= k + 1; i++) good[i] = fact[i - 1];
  queue<long long> q;
  long long sum = 0;
  for (int i = 2; i < k + 2; i++) {
    long long cur = (good[i] * back(fact[i - 1])) % md;
    q.push(cur);
    sum += cur;
    if (sum >= md) sum -= md;
  }
  for (int i = k + 2; i <= n; i++) {
    good[i] = (sum * fact[i - 2]) % md;
    sum -= q.front();
    if (sum < 0) sum += md;
    q.pop();
    long long cur = (good[i] * back(fact[i - 1])) % md;
    q.push(cur);
    sum += cur;
    if (sum >= md) sum -= md;
  }
  long long ans = fact[n];
  for (int pos = 1; pos <= n; pos++) {
    long long sub = (good[pos] * (C(n - 1, n - pos))) % md;
    sub = (sub * fact[n - pos]) % md;
    ans -= sub;
    if (ans < 0) ans += md;
  }
  cout << ans;
  return 0;
}
