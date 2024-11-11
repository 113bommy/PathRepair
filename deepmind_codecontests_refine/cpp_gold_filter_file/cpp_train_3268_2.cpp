#include <bits/stdc++.h>
using namespace std;
int a[100010];
long long int dp[10 * 100010], fp[100010], t[10 * 100010 * 4];
const long long int mod = 1e9 + 7;
void update(int node, int lo, int hi, int in, int val) {
  if (lo == hi) {
    t[node] = (t[node] + val) % mod;
    return;
  }
  int md = (lo + hi) >> 1;
  if (in <= md)
    update(node << 1, lo, md, in, val);
  else
    update(node << 1 | 1, md + 1, hi, in, val);
  t[node] = (t[node << 1] + t[node << 1 | 1]) % mod;
}
long long int query(int node, int lo, int hi, int l, int r) {
  if (lo >= l and hi <= r) return t[node];
  if (lo > r or hi < l) return 0;
  int md = (lo + hi) >> 1;
  return (query(node << 1, lo, md, l, r) +
          query(node << 1 | 1, md + 1, hi, l, r)) %
         mod;
}
long long int cp[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long int ans = 0;
  update(1, 0, 1e6, 0, 1);
  for (int i = 0; i < n; ++i) {
    long long int rem = query(1, 0, 1e6, 0, a[i]);
    long long int eff = (rem - dp[a[i]] + mod) % mod;
    long long int tar = (eff * a[i]) % mod;
    dp[a[i]] = rem;
    update(1, 0, 1e6, a[i], tar);
    cp[i] = tar;
  }
  for (int i = 0; i < n; ++i) {
    ans = (ans + cp[i]) % mod;
  }
  cout << ans << endl;
}
