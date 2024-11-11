#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int mxn = 1e6 + 1;
vector<int> prime[mxn];
void pre() {
  for (int i = 2; i < mxn; i++) {
    if (prime[i].empty()) {
      for (int j = i; j < mxn; j += i) prime[j].push_back(i);
    }
  }
}
int get(int p, int x) {
  if (p == 1) return x;
  int n = prime[p].size();
  int ret = n;
  for (int mask = 1; mask < (1 << n); mask++) {
    int sign = -1;
    int val = 1;
    for (int i = 0; i < n; i++) {
      if ((1 << i) & mask) {
        sign *= -1;
        val *= prime[p][i];
      }
    }
    ret += sign * (x / val);
  }
  return ret;
}
void solve() {
  int x, p, k;
  cin >> x >> p >> k;
  int less = get(p, x);
  42;
  int ans, low = 0, high = 1e8, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    42;
    if (get(p, mid) >= k + less) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
