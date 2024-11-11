#include <bits/stdc++.h>
using namespace std;
const long long LLMAX = 0x7fffffffffffffff;
void showVector(vector<long long> s) {
  cout << "----------" << endl;
  for (auto x : s) cout << x << " ";
  cout << endl << "----------" << endl;
}
const long long MAX_V = 11;
long long head[MAX_V];
struct EDGE {
  long long u, v, w;
  EDGE(long long tu = 0, long long tv = 0, long long tw = 0) {
    u = tu, v = tv, w = tw;
  }
};
struct Triple {
  long long f, s, t;
};
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long dir[8] = {-1, 0, 1, 0, 1, 0, 0, -1};
long long f[111111];
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> f[i];
  }
  long long ans = 0;
  for (long long i = 0; i < 20; i++) {
    for (long long j = 1; j <= n; j++) {
      if (f[j] & (1 << i)) {
        long long k;
        for (k = j; k <= n; k++)
          if ((f[j] & (1 << i)) == 0) break;
        k--;
        ans += ((1 + k - j + 1) * (k - j + 1) / 2) * (1 << i);
        j = k;
      }
    }
  }
  for (long long t = 1; t <= m; t++) {
    long long x, y;
    cin >> x >> y;
    for (long long i = 0; i < 20; i++) {
      if ((f[x] & (1 << i)) ^ (y & (1 << i))) {
        long long l, r;
        for (r = x + 1; r <= n; r++)
          if ((f[r] & (1 << i)) == 0) break;
        for (l = x - 1; l >= 1; l--)
          if ((f[l] & (1 << i)) == 0) break;
        long long fir = x - l, sec = r - x;
        if (y & (1 << i)) {
          ans += fir * sec * (1 << i);
        } else
          ans -= fir * sec * (1 << i);
      }
    }
    cout << ans << endl;
    f[x] = y;
  }
  return 0;
}
