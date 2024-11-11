#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void swap(int &x, int &y) {
  x ^= y;
  y ^= x;
  x ^= y;
}
class dsu {
 public:
  unordered_map<int, int> p, sz;
  unordered_map<int, pair<int, int>> gp;
  void make_set(int x, bool gender) {
    p[x] = x;
    sz[x] += 1;
    if (gender == 1)
      gp[x].first++;
    else
      gp[x].second++;
  }
  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }
  void merge(int a, int b, bool ga, bool gb) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b), swap(ga, gb);
    p[b] = a;
    sz[a] += sz[b];
    if (gb)
      gp[a].first++;
    else
      gp[a].second++;
    sz.erase(b);
  }
};
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res % p * x % p) % p;
    y >>= 1;
    x = (x % p * x % p) % p;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y >>= 1;
    x = (x * x);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  long long a[n];
  long long ans = -1;
  for (int i = 0; i < n; i++) cin >> a[i], ans = max(ans, a[i]);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        ans = max(ans, (a[i] | a[j] | a[k]));
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  fastio();
  int t = 1;
  while (t--) {
    solve();
  }
}
