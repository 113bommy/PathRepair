#include <bits/stdc++.h>
using namespace std;
long long int powMod(long long int x, long long int y) {
  long long int p = 1;
  while (y) {
    if (y % 2) {
      p = (p * x) % 1000000007;
    }
    y /= 2;
    x = (x * x) % 1000000007;
  }
  return p;
}
long long int invMod(long long int x) { return powMod(x, 1000000007 - 2); }
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
void solve() {
  long long int n, b;
  cin >> n >> b;
  long long int a[n];
  set<long long int> s, s1, s2;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  sort(a, a + n);
  long long int k = 1;
  if ((8 * b) / n < 32) k = pow(2, (8 * b) / n);
  if ((8 * b) / n > 32 || s.size() <= k) {
    cout << 0;
  } else {
    long long int bad = s.size() - k;
    long long int pre[bad + 1], suf[bad + 1];
    pre[0] = 0;
    long long int x = 0;
    for (long long int i = 0; i <= bad; i++) {
      while (s1.size() != i + 1) {
        s1.insert(a[x]);
        x++;
      }
      pre[i] = x - 1;
    }
    x = n - 1;
    for (long long int i = 0; i <= bad; i++) {
      while (s2.size() != i + 1) {
        s2.insert(a[x]);
        x--;
      }
      suf[i] = x + 1;
    }
    long long int ans = n;
    for (long long int i = 0; i < bad + 1; i++) {
      ans = min(pre[i] + n - 1 - suf[bad - i], ans);
    }
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
