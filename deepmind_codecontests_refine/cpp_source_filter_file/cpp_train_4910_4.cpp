#include <bits/stdc++.h>
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
using namespace ::std;
const long long maxn = 2e5 + 500;
const long long inf = 1e9 + 800;
const long long mod = 1e9 + 7;
bool h[maxn];
deque<long long> d;
long long key[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long v;
    cin >> v;
    h[v] = 1;
  }
  for (long long i = 0; i < n; i++) {
    long long v;
    cin >> v;
    d.push_back(v);
  }
  fill(key, key + maxn, -1);
  for (long long t = 0; t < n; t++) {
    key[d[t]] = t + 1;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans = max(ans, key[i] - i);
  }
  ans += n + 1;
  if (h[1] == 0) {
    long long u;
    for (long long i = 0; i < n; i++) {
      if (d[i] == 1) {
        u = i;
      }
    }
    bool good = 1;
    for (long long i = u; i < n; i++) {
      if (d[i] != i - u + 1) {
        good = 0;
        break;
      }
    }
    if (good) {
      for (long long i = d.back() + 1; i <= n; i++) {
        if (!h[i] && key[i] > i - d.back() - 1) {
          good = 0;
          break;
        }
      }
      if (good) {
        cout << n - d.back() << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}
