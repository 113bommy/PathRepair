#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const long long inf = 1ll << 60;
const long long iinf = 2147483647;
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 5;
const double PI = acos(-1);
long long pw(long long x, long long p) {
  long long ret = 1;
  while (p > 0) {
    if (p & 1) {
      ret *= x;
      ret %= mod;
    }
    x *= x;
    x %= mod;
    p >>= 1;
  }
  return ret;
}
long long inv(long long a) { return pw(a, mod - 2); }
vector<string> vc;
vector<long long> ans0(maxn), ans1(maxn);
void run(long long bpos, vector<long long> &id) {
  if (bpos == -1 || (long long)(id.size()) == 0) return;
  long long res = 0, cnt = 0, rres = 0, rcnt = 0;
  vector<long long> a, b;
  for (long long i = ((long long)(id.size())) - 1; i >= 0; i--) {
    if (vc[id[i]][bpos] == '0') {
      a.push_back(i);
    } else {
      b.push_back(i);
    }
    if (i == (long long)(id.size()) - 1) {
      if (vc[id[i]][bpos] - '0')
        rcnt++;
      else
        cnt++;
      continue;
    }
    if (vc[id[i]][bpos] == '0') {
      rres += rcnt;
      cnt++;
    } else {
      res += cnt;
      rcnt++;
    }
  }
  ans0[bpos] += res;
  ans1[bpos] += rres;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  run(bpos - 1, a);
  run(bpos - 1, b);
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vc = vector<string>(n);
  for (long long i = (0); i < (n); i++) {
    long long x;
    cin >> x;
    for (long long j = (0); j < (31); j++) {
      vc[i] += (((1 << j) & x) > 0) + '0';
    }
  }
  vector<long long> tmp(n);
  for (long long i = (0); i < (n); i++) tmp[i] = i;
  run(30, tmp);
  long long btres = 0, x = 0;
  for (long long i = (0); i < (31); i++) {
    if (ans1[i] < ans0[i]) {
      x += (1 << i);
      btres += ans1[i];
    } else {
      btres += ans0[i];
    }
  }
  cout << btres << ' ' << x << '\n';
}
