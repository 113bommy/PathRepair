#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
inline int pow_(long long a, int n, int p = mod) {
  int r = 1;
  while (n) {
    if (n & 1) r = r * a % p;
    n >>= 1;
    a = a * a % p;
  }
  return r;
}
inline int inv_(int a) { return pow_(a, mod - 2, mod); }
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline void adds(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
inline int mul(int a, int b) { return a * 1ll * b % mod; }
inline void muls(int& a, int b) { a = a * 1ll * b % mod; }
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int pp[5000100];
int main() {
  int T, n, p;
  scanf("%d", &T);
  map<int, int> mp;
  vector<pair<int, int> > v;
  while (T--) {
    mp.clear();
    v.clear();
    scanf("%d%d", &n, &p);
    pp[0] = 1;
    for (int i = 1; i <= 2 * n + 100; ++i) {
      pp[i] = pp[i - 1] * 1ll * p % mod;
    }
    for (int i = 0; i < (n); ++i) {
      int x;
      scanf("%d", &x);
      mp[x] += 1;
    }
    for (auto it : mp) v.push_back(it);
    reverse(v.begin(), v.end());
    if (p == 1) {
      printf("%d\n", n % 2);
      continue;
    }
    int lm = 0;
    long long tm = 1;
    while (tm <= 2000010) {
      lm += 1;
      tm *= p;
    }
    int i = 0;
    for (; i < v.size(); ++i) {
      if (v[i].second % 2 == 0) continue;
      v[i].second = 1;
      long long required = 1, j = i + 1;
      bool found = false;
      for (; j < v.size(); ++j) {
        if (required > 2000100 || v[j - 1].first - v[j].first >= lm) break;
        required *= pp[v[j - 1].first - v[j].first];
        if (v[j].second >= required) {
          found = true;
          break;
        }
        required -= v[j].second;
      }
      if (found) {
        v[j].second -= required;
        i = j - 1;
      } else {
        break;
      }
    }
    if (i == v.size()) {
      puts("0");
    } else {
      int ans = pow_(p, v[i].first);
      for (int j = i + 1; j < v.size(); ++j) {
        ans -= v[j].second * 1ll * pow_(p, v[j].first) % mod;
        if (ans < 0) ans += mod;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
