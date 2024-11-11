#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7;
const long long mod = 1e9 + 7;
long long cnt[N];
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long calc(long long x, long long p, long long y) {
  if (p == 1) {
    return x;
  }
  long long res = 1;
  for (long long i = 1; i <= y; i++) {
    if (res * p >= N) {
      return -1;
    }
    res *= p;
  }
  if (res * x >= N) {
    return -1;
  }
  return res * x;
}
void solve() {
  long long n, p;
  cin >> n >> p;
  vector<long long> vc(n), a;
  for (auto &i : vc) {
    cin >> i;
    cnt[i]++;
  }
  map<long long, long long> used;
  for (auto i : vc) {
    if (used[i]) {
      continue;
    }
    used[i] = 1;
    a.push_back(i);
  }
  n = a.size();
  sort(a.rbegin(), a.rend());
  long long pos = 0, dif = 0;
  while (pos < n) {
    if (cnt[a[pos]] % 2 == 0) {
      pos++;
      continue;
    }
    long long x = a[pos], need = 1, ok = 0;
    for (long long i = pos + 1; i < n; i++) {
      long long new_need = calc(need, p, x - a[i]);
      if (new_need == -1) {
        break;
      }
      if (new_need <= cnt[a[pos]]) {
        cnt[a[pos]] -= new_need;
        pos = i;
        ok = 1;
        break;
      } else {
        need = new_need - cnt[a[pos]];
        x = a[i];
      }
    }
    if (!ok) {
      dif = binpow(p, a[pos]);
      for (long long i = pos + 1; i < n; i++) {
        dif -= cnt[a[i]] * binpow(p, a[i]) % mod;
        if (dif < 0) {
          dif += mod;
        }
      }
      break;
    }
  }
  cout << dif << '\n';
  for (auto i : vc) {
    cnt[i] = 0;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
