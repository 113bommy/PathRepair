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
pair<long long, long long> hashFn(vector<long long> vc) {
  long long p1 = 31, p2 = 97;
  long long m1 = 1e9 + 9, m2 = 998244353;
  long long hsv1 = 0, hsv2 = 0, p_pow1 = 1, p_pow2 = 1;
  for (long long i = 0; i < vc.size(); i++) {
    hsv1 = ((hsv1 + vc[i] + 1) * p_pow1) % m1;
    p_pow1 = (p_pow1 * p1) % m1;
    hsv2 = ((hsv2 + vc[i] + 1) * p_pow2) % m2;
    p_pow2 = (p_pow2 * p2) % m2;
  }
  return make_pair(hsv1, hsv2);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> ar(n);
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
  }
  vector<vector<long long> > dcp(n);
  bool flag = 1;
  for (long long i = 0; i < n; i++) {
    long long pw = 0;
    while (ar[i] != 0) {
      while (ar[i] % k == 0) {
        ar[i] /= k;
        pw++;
      }
      ar[i] -= 1;
      dcp[i].push_back(pw);
      if (ar[i] % k != 0) {
        flag = 0;
        break;
      }
    }
  }
  if (flag == 0) {
    cout << "NO"
         << "\n";
  } else {
    bool flg = 1;
    vector<long long> tpp(80, -1);
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < dcp[i].size(); j++) {
        if (tpp[dcp[i][j]] != -1) {
          flg = 0;
        } else {
          tpp[dcp[i][j]] = i;
        }
      }
    }
    if (flg) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
