#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")
using namespace std;
const long long MOD = 1000000007;
const long long MOD2 = 1000000009;
const long long BASE = 257;
const long long INF = 1000000050;
const long long BIG = (long long)2e18 + 50;
const long long MX = 100010;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    long long gr = (n - 1) / 3;
    long long ind = (n - 1) % 3;
    long long cur = 0;
    long long add = 0;
    while (cur <= gr - (1ll << add)) {
      cur += (1ll << add);
      add += 2;
    }
    long long fs = gr - cur + (1ll << add);
    if (ind == 0) {
      cout << fs << '\n';
    } else {
      long long cnt = gr - cur;
      long long se = 1ll << (add + 1);
      long long curpw = 0;
      while (cnt) {
        long long md = cnt % 4;
        long long td = 0;
        if (md == 1)
          td = 2;
        else if (md == 2)
          td = 3;
        else if (md == 3)
          td = 1;
        se += td << curpw;
        curpw += 2;
        cnt /= 4;
      }
      if (ind == 1) {
        cout << se << '\n';
      } else {
        cout << (se ^ fs) << '\n';
      }
    }
  }
}
