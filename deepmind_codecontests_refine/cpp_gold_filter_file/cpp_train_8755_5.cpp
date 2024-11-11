#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int maxn = 1e5 + 5;
struct segment {
  long long le;
  long long ri;
} seg[maxn];
bool cmp(segment &a, segment &b) { return a.le < b.le; }
multiset<long long> s;
int main() {
  int n;
  long long x, y, ans = 0;
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> seg[i].le >> seg[i].ri;
    s.insert(seg[i].ri);
  }
  sort(seg + 1, seg + n + 1, cmp);
  multiset<long long>::iterator it;
  for (int i = 1; i <= n; i++) {
    long long l = seg[i].le, r = seg[i].ri;
    it = s.lower_bound(seg[i].le);
    if (it == s.begin()) {
      ans = (ans + x + y * (r - l) % mod) % mod;
    } else {
      it--;
      long long r0 = *it;
      if ((l - r0) * y - x <= 0) {
        ans = (ans + y * (r - r0) % mod) % mod;
        s.erase(s.find(r0));
      } else {
        ans = (ans + x + y * (r - l) % mod) % mod;
      }
    }
  }
  cout << ans << endl;
}
