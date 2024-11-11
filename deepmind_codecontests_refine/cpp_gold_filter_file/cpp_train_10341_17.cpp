#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
T sqr(T a) {
  return a * a;
}
const int INF = int(1e9) + 7;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
const int mod = 1000000009;
const int NMAX = 2000000;
long long cnt[NMAX], cnt1[NMAX];
void init() {
  cnt[1] = 5;
  cnt1[1] = 2;
  for (int i = int(2); i < int(NMAX); ++i) {
    cnt[i] = cnt[i - 1];
    cnt[i] += cnt1[i - 1] * 4;
    cnt1[i] = cnt1[i - 1] * 2;
    cnt[i] %= mod;
    cnt1[i] %= mod;
  }
}
int main() {
  init();
  int n;
  cin >> n;
  long long ans = 0, prev = 1;
  int next = 1;
  for (int i = 1; i <= int(n); ++i) {
    if (i == 1) ans++;
    if (i == 2) {
      ans += 1;
      if (i + 1 <= n) ans += 1;
    }
    if (i <= 2) continue;
    if (i % 2 == 1) {
      ans += prev;
      if (i + 1 <= n) ans += prev;
    } else {
      ans += prev;
      if (i + 1 <= n) ans += prev * cnt[next];
      prev *= cnt[next];
      next++;
    }
    ans %= mod;
    prev %= mod;
  }
  ans = ((ans * ans) % mod * 2 + 2) % mod;
  cout << ans << endl;
  return 0;
}
