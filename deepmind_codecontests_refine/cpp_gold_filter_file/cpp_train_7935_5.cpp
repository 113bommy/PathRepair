#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
struct node {
  int v, id;
  friend bool operator<(node a, node b) { return a.v < b.v; }
};
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int b[maxn], a[maxn];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    set<int> s;
    cin >> n;
    for (int i = 1; i <= 1000; ++i) b[i] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], s.insert(a[i]);
    int ans = 1;
    bool ok = 0;
    for (int i = 2; i <= 1000; i++) {
      for (int j = 1; i * j <= 1000; j++) {
        if (!b[i * j] && s.count(i * j)) ok = 1;
        if (!b[i * j]) b[i * j] = ans;
      }
      if (ok) ans++, ok = 0;
    }
    cout << ans - 1 << '\n';
    for (int i = 1; i <= n; ++i) {
      printf("%d%c", b[a[i]], i == n ? '\n' : ' ');
    }
  }
  return 0;
}
