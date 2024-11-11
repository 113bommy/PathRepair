#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int add(int a, int b) {
  long long x = a + b;
  if (x >= 1000000007) x -= 1000000007;
  if (x < 0) x += 1000000007;
  return x;
}
long long mul(long long a, long long b) { return (a * b) % 1000000007; }
long long pw(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed() {
  long long a = rng();
  return a;
}
int t, n, mb, p;
int vv[20000002];
int aib[100002], mxx[100002];
void upd(int nod, int val) {
  for (; nod <= mb; nod += (nod & (-nod))) aib[nod] = max(aib[nod], val);
}
int compute(int nod) {
  int ans = 0;
  for (; nod; nod -= (nod & (-nod))) ans = max(ans, aib[nod]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t >> n >> mb >> p;
  for (; t; --t) {
    for (int j = 1; j <= n; ++j) cin >> vv[j];
    int maxx = n;
    for (int j = 1; j < min(p, mb); ++j)
      for (int x = 1; x <= n; ++x) vv[j * n + x] = vv[x], maxx = j * n + x;
    int ans = 0;
    for (int j = 1; j <= maxx; ++j) {
      if (mxx[vv[j]] != vv[j]) {
        int ax = 1 + compute(vv[j] - 1);
        if (ax > mxx[vv[j]]) mxx[vv[j]] = ax, upd(vv[j], ax);
        ans = max(ans, ax);
      }
    }
    cout << ans << '\n';
    memset(aib, 0, sizeof(aib));
    memset(mxx, 0, sizeof(mxx));
  }
  return 0;
}
