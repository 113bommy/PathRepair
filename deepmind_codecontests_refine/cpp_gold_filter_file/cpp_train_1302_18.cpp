#include <bits/stdc++.h>
using namespace std;
long long mypow(long long base, long long n) {
  if (n == 0) return 1;
  long long t = mypow(base, n / 2);
  t = t * t % 1000000007;
  if (n & 1) return t * base % 1000000007;
  return t;
}
long long mypow(long long base, long long n, long long dmod) {
  if (n == 0) return 1;
  long long t = mypow(base, n / 2, dmod);
  t = t * t % dmod;
  if (n & 1) return t * base % dmod;
  return t;
}
int p, k;
bool mark[1111111];
int main() {
  cin >> p >> k;
  if (k == 0) {
    cout << mypow(p, p - 1) << endl;
    return 0;
  }
  long long res = 1;
  if (k == 1) res = p;
  memset(mark, 0, sizeof(mark));
  for (int i = 1; i < p; ++i)
    if (!mark[i]) {
      int cnt = 0;
      long long v = i;
      while (!mark[v]) {
        mark[v] = 1;
        ++cnt;
        v = (v * k) % p;
      }
      if (mypow(k, cnt, p) == 1) res = res * p % 1000000007;
    }
  cout << res << endl;
}
