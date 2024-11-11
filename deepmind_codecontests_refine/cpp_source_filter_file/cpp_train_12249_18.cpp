#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
char _;
inline long long powmod(long long x, long long n, long long _mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % _mod;
    x = (x * x) % _mod;
    n >>= 1;
  }
  return res;
}
int n;
int a[1000006];
int b[1000006];
int seen[1000006];
vector<int> factors(int x) {
  vector<int> ret;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ret.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) ret.push_back(x);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n + 1; ++i) cin >> a[i];
  int cur = 1;
  while (cur <= n) {
    vector<int> f = factors(a[cur]);
    bool ok = true;
    for (int i = 0; i < int((f).size()); ++i) {
      if (seen[f[i]]) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    b[cur] = a[cur];
    cur++;
    for (int i = 0; i < int((f).size()); ++i) seen[f[i]] = 1;
  }
  if (cur <= n) {
    for (int i = a[cur] + 1;; i++) {
      vector<int> f = factors(i);
      bool ok = true;
      for (int j = 0; j < int((f).size()); ++j) {
        if (seen[f[j]]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        b[cur] = i;
        for (int j = 0; j < int((f).size()); ++j) {
          seen[f[j]] = 1;
        }
        cur++;
        break;
      }
    }
  }
  if (cur <= n) {
    vector<int> v;
    for (int i = 2;; i++) {
      if (cur + int((v).size()) > 1e5 + 5) break;
      if (seen[i]) continue;
      vector<int> f = factors(i);
      bool ok = true;
      for (int j = 0; j < int((f).size()); ++j)
        if (seen[f[j]]) {
          ok = false;
          break;
        }
      if (ok) {
        v.push_back(i);
        for (int j = 0; j < int((f).size()); ++j) seen[f[j]] = 1;
      }
    }
    int i = 0;
    while (cur <= n) {
      b[cur++] = v[i++];
    }
  }
  for (int i = 1; i < n + 1; ++i) cout << b[i] << ' ';
  cout << '\n';
  return 0;
}
