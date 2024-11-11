#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long int fast_exp(long long int base, long long int ex) {
  long long int res = 1;
  while (ex > 0) {
    if (ex % 2 == 1) res = (res * base) % mod;
    base = (base * base) % mod;
    ex /= 2;
  }
  return res % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  long long int re = gcd(b, a % b);
  return re;
}
long long n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  long long b[n];
  long long c[n];
  map<pair<long long, long long>, pair<long long, long long> > mt;
  long long ma = 0;
  long long in1 = -1;
  long long in2 = -1;
  for (int i = 0; i < n; i++) {
    long long d[3];
    cin >> d[0] >> d[1] >> d[2];
    sort(d, d + 3);
    a[i] = d[0];
    b[i] = d[1];
    c[i] = d[2];
    if (mt[make_pair(d[0], d[1])].second > d[2])
      mt[make_pair(d[0], d[1])] = make_pair(i, d[2]);
    if (mt[make_pair(d[1], d[2])].second > d[0])
      mt[make_pair(d[1], d[2])] = make_pair(i, d[0]);
    if (mt[make_pair(d[0], d[2])].second > d[1])
      mt[make_pair(d[0], d[2])] = make_pair(i, d[1]);
    ma = max(ma, min(d[0], min(d[1], d[2])));
    if (ma == min(d[0], min(d[1], d[2]))) {
      in1 = i;
    }
  }
  long long ans = ma;
  long long k = 1;
  for (int i = 0; i < n; i++) {
    if (mt[make_pair(a[i], b[i])].first != i) {
      long long f = mt[make_pair(a[i], b[i])].second;
      long long first = f + c[i];
      long long co = min(min(a[i], b[i]), first);
      if (ans < co) {
        k = 2;
        in1 = i;
        in2 = mt[make_pair(a[i], b[i])].first;
        ans = co;
      }
    }
    if (mt[make_pair(a[i], c[i])].first != i) {
      long long f = mt[make_pair(a[i], c[i])].second;
      long long first = f + b[i];
      long long co = min(min(a[i], c[i]), first);
      if (ans < co) {
        k = 2;
        in1 = i;
        in2 = mt[make_pair(a[i], c[i])].first;
        ans = co;
      }
    }
    if (mt[make_pair(b[i], c[i])].first != i) {
      long long f = mt[make_pair(b[i], c[i])].second;
      long long first = f + a[i];
      long long co = min(min(b[i], c[i]), first);
      if (ans < co) {
        k = 2;
        in1 = i;
        in2 = mt[make_pair(b[i], c[i])].first;
        ans = co;
      }
    }
  }
  cout << k << "\n";
  cout << in1 + 1 << " ";
  if (k == 2) cout << in2 + 1 << "\n";
  return 0;
}
