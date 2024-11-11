#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
long long add(long long a, long long b, long long MOD) { return (a + b) % MOD; }
long long mul(long long a, long long b, long long MOD) {
  return (a * b + MOD) % MOD;
}
int a[MAXN];
bool used[MAXN];
void solve() {
  int p, k;
  cin >> p >> k;
  for (int i = 0; i < p; i++) {
    a[i] = mul(k, i, p);
  }
  long long MOD = 1e9 + 7;
  long long ans = 1;
  if (!k) {
    for (int i = 1; i < p; i++) {
      ans = mul(ans, p, MOD);
    }
    cout << ans;
    return;
  }
  for (int i = 0; i < p; i++) {
    if (used[i]) continue;
    int len = 1;
    used[i] = 1;
    int v = a[i];
    for (; !used[v]; v = a[v]) {
      used[v] = 1;
      len++;
    }
    if (len == 1) {
      continue;
    }
    ans = mul(ans, p, MOD);
  }
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
