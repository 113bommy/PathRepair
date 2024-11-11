#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10, INF = 1e18 - 10;
long long a[maxn], psum[maxn], n, ans = INF;
bool notprime[2 * maxn];
vector<long long> prime;
inline long long get(long long p) {
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += min((psum[i] % p), p - (psum[i] % p));
  }
  return res;
}
inline void findprime() {
  notprime[1] = 1;
  for (int i = 2; i < maxn + 30; ++i) {
    if (!notprime[i]) {
      prime.push_back(i);
      for (int j = 2 * i; j < maxn + 30; j += i) {
        notprime[j] = 1;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  findprime();
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  psum[0] = a[0];
  for (int i = 1; i < n; ++i) {
    psum[i] = a[i] + psum[i - 1];
  }
  if (psum[n - 1] == 1) {
    cout << -1 << endl;
    return 0;
  }
  long long val = psum[n - 1];
  for (int i = 0; 1ll * prime[i] * prime[i] <= val; ++i) {
    long long x = prime[i];
    if (val % x == 0) {
      ans = min(ans, get(x));
      while (val % x == 0) {
        val /= x;
      }
    }
  }
  if (val > 1) {
    ans = min(ans, get(val));
  }
  cout << ans << endl;
}
