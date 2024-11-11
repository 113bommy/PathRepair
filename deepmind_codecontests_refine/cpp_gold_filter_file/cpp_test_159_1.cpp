#include <bits/stdc++.h>
using namespace std;
const long long iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 87;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const long long maxn = 1e6 + 5;
unsigned long long H[maxn];
bool np[maxn];
unsigned long long val[maxn];
long long n;
void RET(vector<long long> no) {
  vector<long long> yay(n + 1);
  for (long long t : no) yay[t] = 1;
  cout << n - (long long)no.size() << '\n';
  for (long long i = 1; i <= n; ++i) {
    if (!yay[i]) cout << i << ' ';
  }
  cout << '\n';
  exit(0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  mt19937_64 rnd(time(0));
  for (long long i = 0; i < maxn; ++i) {
    val[i] = rnd();
  }
  for (long long i = 2; i < maxn; ++i) {
    if (!np[i]) {
      for (long long j = i; j < maxn; j += i) {
        if (j != i) np[j] = 1;
        long long r = j;
        while (r % i == 0) {
          r /= i;
          H[j] ^= val[i];
        }
      }
    }
  }
  cin >> n;
  for (long long i = 1; i < maxn; ++i) H[i] ^= H[i - 1];
  unsigned long long all = 0;
  for (long long i = 1; i <= n; ++i) all ^= H[i];
  if (all == 0) {
    RET({});
  }
  for (long long i = 1; i <= n; ++i) {
    if (H[i] == all) {
      RET({i});
    }
  }
  vector<pair<unsigned long long, long long> > v;
  for (long long i = 1; i <= n; ++i) {
    v.push_back({H[i], i});
  }
  sort(v.begin(), v.end());
  for (long long i = 1; i <= n; ++i) {
    long long at =
        lower_bound(v.begin(), v.end(),
                    pair<unsigned long long, long long>{H[i] ^ all, i + 1}) -
        v.begin();
    if (at < (long long)v.size() && (v[at].first == (H[i] ^ all))) {
      RET({i, v[at].second});
    }
  }
  assert(n % 2 == 1);
  RET({n, n / 2, 2});
}
