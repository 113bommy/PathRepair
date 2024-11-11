#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
long long MOD = 998244353;
long long mpow(long long a, long long b) {
  if (b >= (MOD - 1)) b %= (MOD - 1);
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long mpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2, p);
  t1 *= t1;
  t1 %= p;
  if (b % 2) t1 *= a;
  t1 %= p;
  return t1;
}
long long modinverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long range(long long l, long long r) { return l + rand() % (r - l + 1); }
long long rev(long long v) { return mpow(v, MOD - 2); }
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<bitset<1000> > ans(n + 1);
  for (long long i = 0; i < n + 1; i++)
    for (long long j = 0; j < 1000; j++) ans[i][j] = 0;
  vector<pair<long long, long long> > same;
  for (long long i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      same.push_back(make_pair(i, j));
    }
  }
  long long i = 0;
  while (i < n) {
    while (((long long)(same).size())) {
      long long a1 = same.back().first, b = same.back().second;
      if ((ans[a1] ^ ans[b]).count()) {
        same.pop_back();
      } else {
        same.pop_back();
        ans[b][i] = 1;
        a[i]--;
        for (long long j = 0; j < n + 1; j++) {
          if (j == a1 || j == b) continue;
          if (a[i]) {
            ans[j][i] = 1;
            a[i]--;
          }
        }
        i++;
      }
    }
    while (i < n) {
      for (long long j = 0; j < a[i]; j++) ans[j][i] = 1;
      i++;
    }
  }
  vector<long long> in;
  for (long long i = 0; i < n + 1; i++) {
    if (ans[i].count()) in.push_back(i);
  }
  cout << ((long long)(in).size()) << "\n";
  for (long long i = 0; i < ((long long)(in).size()); i++) {
    for (long long j = 0; j < n; j++) cout << ans[in[i]][j];
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
