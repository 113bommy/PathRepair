#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;
const long long M = 1e18;
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int pre[5 * N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> m;
    int a[n], mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
      pre[a[i]]++;
    }
    for (int i = 1; i < 5 * N; i++) pre[i] += pre[i - 1];
    long long ans = 0;
    for (int v : a) {
      if (m[v] > 0) {
        continue;
      }
      int k = ceil((float)mx / v);
      long long sum = 0;
      for (int i = 1; i <= k; i++) {
        sum += (pre[(i + 1) * v - 1] - pre[i * v - 1]) * 1ll * i * v;
      }
      m[v] = 1;
      ans = max(ans, sum);
    }
    cout << ans;
  }
}
