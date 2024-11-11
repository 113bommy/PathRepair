#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007ll;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
template <typename t1, typename t2>
inline bool upmax(t1 &a, t2 b) {
  if (a < (t1)b) {
    a = (t1)b;
    return true;
  } else
    return false;
}
template <typename t1, typename t2>
inline bool upmin(t1 &a, t2 b) {
  if (a > (t1)b) {
    a = (t1)b;
    return true;
  } else
    return false;
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int INF = 1000000404;
const long long LINF = 4000000000000000404ll;
const long double PI = acos(-1.0);
const long double EPS = 1e-9;
int SQ = 318;
int timer = 0;
int a[200100];
int nxt[200100];
long long pref[200100];
void solve() {
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  nxt[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1)
      nxt[i] = nxt[i + 1];
    else
      nxt[i] = i;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long p = 1;
    long long s = 0;
    int j = i;
    for (int step = 0; step < 70 && j <= n; step++) {
      if ((double)p * a[j] > 1e18) break;
      p = p * a[j];
      s = pref[j] - pref[i - 1];
      if (p == s * k) {
        ans++;
      } else {
        if (p >= k * s && (p - k * s) % k == 0) {
          long long x = (p - k * s) / k;
          long long r = nxt[j + 1] - 1;
          long long l = i + 1;
          if (l <= r && r <= n && (r - l + 1) >= x) {
            ans++;
          }
        }
      }
      j = nxt[j + 1];
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  getchar();
  getchar();
  return 0;
}
