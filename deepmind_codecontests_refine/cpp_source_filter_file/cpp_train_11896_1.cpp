#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void mad(long long &a, long long b) {
  a = (a + b) % 1000000007;
  if (a < 0) a += 1000000007;
}
long long gcd(long long a, long long b) {
  if (!a) return b;
  return gcd(b % a, a);
}
void solve() {
  long long n, d, m;
  cin >> n >> d >> m;
  vector<long long> a, b;
  a.push_back(0);
  b.push_back(0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > m)
      b.push_back(x);
    else
      a.push_back(x);
  }
  sort(a.begin() + 1, a.end(), greater<long long>());
  sort(b.begin() + 1, b.end(), greater<long long>());
  long long sa = a.size() - 1;
  long long sb = b.size() - 1;
  for (int i = 1; i <= sa; i++) a[i] += a[i - 1];
  for (int i = 1; i <= sb; i++) b[i] += b[i - 1];
  long long ans = 0;
  for (long long i = 1; i <= sb; i++) {
    long long req = (i - 1) * d;
    int j = sa;
    if (req > sb - i) j = sa - req + sb - i;
    if (j < 0) break;
    ans = max(ans, b[i] + a[j]);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
