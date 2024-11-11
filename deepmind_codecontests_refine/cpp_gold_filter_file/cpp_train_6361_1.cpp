#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const long double PI = acos(-1.0);
const long long mod1 = inf + 7;
const long long mod2 = inf + 9;
const int MAXN = 1000005;
const long double EPS = 1e-11;
int hp = 179;
signed main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  if (n < 100) {
    for (int i = 0; i < 4500; ++i) {
      long long x = rnd() % n + 1;
      cout << x << ' ' << x << endl;
      string s;
      cin >> s;
      if (s == "Yes") {
        return 0;
      }
    }
  }
  long long l = 1, r = n;
  for (;;) {
    while (r - l > 4 * k + 3) {
      long long m = (l + r) / 2;
      cout << l << ' ' << m << endl;
      string s;
      cin >> s;
      if (s == "No") {
        l = max(1LL, m - k);
        r = min(n, r + k);
      } else {
        l = max(1LL, l - k);
        r = min(n, m + k);
      }
    }
    long long x = rnd() % (r - l + 1) + l;
    cout << x << ' ' << x << endl;
    l = max(1LL, l - k);
    r = min(n, r + k);
    string s;
    cin >> s;
    if (s == "Yes") {
      return 0;
    }
  }
}
